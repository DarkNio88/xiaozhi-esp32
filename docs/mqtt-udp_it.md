# Protocollo ibrido MQTT + UDP

Documentazione tradotta che descrive il protocollo ibrido MQTT + UDP usato nel progetto: controllo e messaggi JSON su MQTT, trasporto audio in tempo reale su UDP (con cifratura).

---

## 1. Panoramica

Il protocollo usa due canali:
- **MQTT** per messaggi di controllo, sincronizzazione di stato e scambio JSON
- **UDP** per il trasporto audio in tempo reale (supporta cifratura)

### Caratteristiche principali

- Separazione canali (controllo vs dati) per garantire real‑time
- Cifratura UDP con AES‑CTR
- Protezione con numeri di sequenza per prevenire replay e disordine
- Riconnessione automatica per MQTT

---

## 2. Flusso generale

Diagramma di sequenza (semplificato): il dispositivo apre la connessione MQTT, negozia il canale UDP (Hello/Hello Response), stabilisce la connessione UDP e scambia dati audio cifrati (Opus); i messaggi di controllo continuano su MQTT.

---

## 3. Canale di controllo MQTT

### 3.1 Connessione

Parametri di connessione MQTT:
- Endpoint (host:port)
- Client ID unico
- Username/Password
- Keep Alive (default 240s)

### 3.2 Scambio Hello

#### Dispositivo → Server (Hello)

```json
{
  "type": "hello",
  "version": 3,
  "transport": "udp",
  "features": { "mcp": true },
  "audio_params": { "format": "opus", "sample_rate": 16000, "channels": 1, "frame_duration": 60 }
}
```

#### Server → Dispositivo (Hello Response)

```json
{
  "type": "hello",
  "transport": "udp",
  "session_id": "xxx",
  "audio_params": { "format": "opus", "sample_rate": 24000, "channels": 1, "frame_duration": 60 },
  "udp": {
    "server": "192.168.1.100",
    "port": 8888,
    "key": "0123456789ABCDEF0123456789ABCDEF",
    "nonce": "0123456789ABCDEF0123456789ABCDEF"
  }
}
```

Spiegazione campi UDP:
- `udp.server`: indirizzo del server UDP
- `udp.port`: porta UDP del server
- `udp.key`: chiave AES (hex)
- `udp.nonce`: nonce/IV (hex)

### 3.3 Tipi di messaggi JSON (su MQTT)

#### Dispositivo → Server

1. **Listen**
```json
{ "session_id": "xxx", "type": "listen", "state": "start", "mode": "manual" }
```

2. **Abort**
```json
{ "session_id": "xxx", "type": "abort", "reason": "wake_word_detected" }
```

3. **MCP**
```json
{ "session_id": "xxx", "type": "mcp", "payload": { "jsonrpc": "2.0", "id": 1, "result": {...} } }
```

4. **Goodbye**
```json
{ "session_id": "xxx", "type": "goodbye" }
```

#### Server → Dispositivo

I tipi di messaggi sono equivalenti a quelli del canale WebSocket: STT, TTS, LLM, MCP, System, Custom.

---

## 4. Canale audio UDP

### 4.1 Stabilire la connessione

Dopo la Hello Response MQTT, il dispositivo usa le informazioni UDP per inizializzare il contesto AES‑CTR e aprire la connessione UDP verso il server.

### 4.2 Formato dei pacchetti audio cifrati

Struttura del pacchetto:

```
|type 1byte|flags 1byte|payload_len 2bytes|ssrc 4bytes|timestamp 4bytes|sequence 4bytes|
|payload payload_len bytes|
```

Campi principali:
- `type`: 0x01
- `flags`: riservato
- `payload_len`: lunghezza del payload (network byte order)
- `ssrc`: sync source
- `timestamp`: timestamp (network byte order)
- `sequence`: numero di sequenza (network byte order)
- `payload`: dati Opus cifrati

### 4.2.2 Cifratura

Usa AES‑CTR:
- chiave: 128 bit fornita dal server
- nonce: 128 bit fornito dal server
- il contatore incorpora timestamp e sequence

### 4.3 Gestione sequenze

- `local_sequence_` incrementa in invio
- `remote_sequence_` usato per verificare ordine
- pacchetti con sequence < atteso sono scartati (protezione replay)
- tolleranza a piccoli salti di sequence (log di warning)

### 4.4 Error handling

1. Decrittazione fallita → log ed scarto pacchetto
2. Sequence anomalo → log di warning, possibile processing
3. Formato pacchetto errato → log ed scarto

---

## 5. Gestione degli stati

Diagramma di stati rappresenta transizioni tra Disconnected, MQTT Connecting, MQTT Connected, richiesta canale, UDP Connected, Audio Streaming, ecc.

Condizione di canale audio aperto (esempio C++):

```cpp
bool IsAudioChannelOpened() const {
    return udp_ != nullptr && !error_occurred_ && !IsTimeout();
}
```

---

## 6. Parametri di configurazione

### MQTT

- `endpoint`, `client_id`, `username`, `password`, `keepalive` (default 240s), `publish_topic`

### Audio

- formato: Opus
- sample rate device: 16000 Hz (server 24000 Hz per riproduzione)
- canali: 1
- frame duration: 60ms

---

## 7. Errori e riconnessione

### MQTT

- retry automatico su fallimento
- error reporting
- cleanup su disconnessione

### UDP

- non tentare reconnect automatico (si negozia nuovamente via MQTT)
- dipende dal canale MQTT per ri‑negoziazione

### Timeout

- `Protocol` base fornisce timeout (default 120s)

---

## 8. Sicurezza

### Trasporto
- MQTT: TLS/SSL (porta 8883)  
- UDP: AES‑CTR per audio

### Autenticazione
- MQTT: username/password  
- UDP: chiavi distribuite via MQTT

### Protezione replay
- sequenze monotone  
- scarto pacchetti scaduti

---

## 9. Performance

### Concorrenza

Proteggere connessioni UDP con mutex:

```cpp
std::lock_guard<std::mutex> lock(channel_mutex_);
```

### Gestione memoria

- creare/distruggere oggetti di rete dinamicamente
- usare smart pointer per buffer audio
- rilasciare contesti di cifratura quando non necessari

### Ottimizzazioni rete

- riuso connessioni UDP
- ottimizzazione dimensione pacchetti
- verifiche di continuità sequenza

---

## 10. Confronto con WebSocket

| Caratteristica | MQTT + UDP | WebSocket |
|---|---:|---:|
| Canale di controllo | MQTT | WebSocket |
| Canale audio | UDP (cifrato) | WebSocket (binary) |
| Tempo reale | Alto (UDP) | Medio |
| Affidabilità | Media | Alta |
| Complessità | Alta | Bassa |
| Cifratura | AES‑CTR | TLS |
| Compatibilità firewall | Bassa | Alta |

---

## 11. Raccomandazioni di deployment

- Assicurare raggiungibilità delle porte UDP e regole firewall  
- Deployment di MQTT broker e server UDP  
- Gestione sicura delle chiavi

## 12. Conclusione

Il protocollo ibrido offre alta reattività per scenari audio in tempo reale ma introduce complessità di rete e deployment; valutare trade‑off tra tempo reale e semplicità architetturale.
