Di seguito c'è una versione tradotta in italiano del documento sul protocollo di comunicazione WebSocket, basata sull'implementazione del codice presente nel repository. Descrive come il dispositivo interagisce con il server tramite WebSocket.

Questo documento deriva dall'analisi del codice; in fase di deployment verificare le implementazioni lato server per eventuali dettagli mancanti.

---

## 1. Panoramica del flusso

1. **Inizializzazione del dispositivo**  
   - All'accensione il dispositivo inizializza `Application`:  
     - codec audio, display, LED, ecc.  
     - connessione di rete  
     - crea e inizializza l'istanza di `Protocol` per WebSocket (`WebsocketProtocol`)  
   - Entra nel ciclo principale in attesa di eventi (ingresso audio, uscita audio, task pianificati).

2. **Stabilire la connessione WebSocket**  
   - Quando il dispositivo deve iniziare una sessione vocale (es. wake word o pressione tasto), chiama `OpenAudioChannel()`:  
     - legge la URL del WebSocket dalla configurazione  
     - imposta header di richiesta (`Authorization`, `Protocol-Version`, `Device-Id`, `Client-Id`)  
     - chiama `Connect()` per stabilire la connessione con il server

3. **Dispositivo invia messaggio "hello"**  
   - Dopo la connessione il dispositivo invia un JSON di handshake, esempio:  
   ```json
   {
     "type": "hello",
     "version": 1,
     "features": { "mcp": true },
     "transport": "websocket",
     "audio_params": {
       "format": "opus",
       "sample_rate": 16000,
       "channels": 1,
       "frame_duration": 60
     }
   }
   ```
   - Il campo `features` è opzionale e dipende dalle opzioni di compilazione (es. `"mcp": true`).  
   - `frame_duration` corrisponde a `OPUS_FRAME_DURATION_MS` (es. 60 ms).

4. **Server risponde con "hello"**  
   - Il dispositivo attende un messaggio JSON con `"type": "hello"` e verifica che `"transport": "websocket"`.  
   - Il server può fornire `session_id`; il dispositivo lo salva se presente.  
   - Esempio risposta server:  
   ```json
   {
     "type": "hello",
     "transport": "websocket",
     "session_id": "xxx",
     "audio_params": { "format": "opus", "sample_rate": 24000, "channels": 1, "frame_duration": 60 }
   }
   ```
   - Se la risposta corrisponde, la connessione audio è considerata pronta; in caso di timeout (default 10s) la connessione è considerata fallita.

5. **Scambio successivo di messaggi**  
   - Tra dispositivo e server possono transitare:  
     - dati audio binari (Opus)  
     - messaggi JSON testuali (stato chat, eventi TTS/STT, messaggi MCP, ecc.)  
   - Nel codice i callback di ricezione differenziano i frame:  
     - `OnData(...)` con `binary == true` → audio Opus  
     - `OnData(...)` con `binary == false` → JSON testuale, da parsare con cJSON e gestire la logica applicativa
   - In caso di disconnessione, viene chiamato `OnDisconnected()` che a sua volta invoca `on_audio_channel_closed_()` e riporta il dispositivo in stato idle.

6. **Chiusura della connessione**  
   - Quando termina la sessione vocale il dispositivo chiama `CloseAudioChannel()` per disconnettere.  
   - La disconnessione lato server innesca lo stesso flusso di callback lato dispositivo.

---

## 2. Header comuni

Durante l'handshake WebSocket vengono impostati i seguenti header:  
- `Authorization`: token di accesso, es. `"Bearer <token>"`  
- `Protocol-Version`: versione del protocollo (coerente con `version` nel payload hello)  
- `Device-Id`: MAC fisico dell'interfaccia di rete  
- `Client-Id`: UUID software (resettato se si cancella NVS o si riscrive il firmware)

Il server può usare questi header per autenticazione e controllo accessi.

---

## 3. Versioni del protocollo binario

Il dispositivo supporta varie versioni del protocollo binario, selezionabili tramite `version` nella configurazione.

### 3.1 Versione 1 (default)
Invio diretto dei dati Opus senza metadati aggiuntivi; il WebSocket distingue frame text/binary.

### 3.2 Versione 2
Usa la struttura `BinaryProtocol2` con metadati (timestamp ecc.):
```c
struct BinaryProtocol2 {
    uint16_t version;        // versione
    uint16_t type;           // tipo messaggio (0: OPUS, 1: JSON)
    uint32_t reserved;       // riservato
    uint32_t timestamp;      // timestamp in ms (per AEC server-side)
    uint32_t payload_size;   // dimensione del payload
    uint8_t payload[];       // dati
} __attribute__((packed));
```

### 3.3 Versione 3
Usa la struttura `BinaryProtocol3` più compatta:
```c
struct BinaryProtocol3 {
    uint8_t type;            // tipo messaggio
    uint8_t reserved;        // riservato
    uint16_t payload_size;   // dimensione payload
    uint8_t payload[];       // dati
} __attribute__((packed));
```

---

## 4. Strutture JSON comuni

I frame testuali sono JSON; di seguito i tipi `type` più usati.

### 4.1 Dispositivo → Server

1. **Hello** — handshake iniziale (vedi esempio sopra).

2. **Listen** — indica avvio/stop della registrazione:
```json
{
  "session_id": "xxx",
  "type": "listen",
  "state": "start",
  "mode": "manual"
}
```

3. **Abort** — termina l'attuale riproduzione TTS o la canale audio:
```json
{
  "session_id": "xxx",
  "type": "abort",
  "reason": "wake_word_detected"
}
```

4. **Wake Word Detected** — segnala il rilevamento del wake word (può includere audio Opus del wake word):
```json
{
  "session_id": "xxx",
  "type": "listen",
  "state": "detect",
  "text": "你好小明"
}
```

5. **MCP** — messaggi del protocollo MCP (JSON-RPC 2.0) per controllo IoT; esempio di `result` inviato dal dispositivo:
```json
{
  "session_id": "xxx",
  "type": "mcp",
  "payload": {
    "jsonrpc": "2.0",
    "id": 1,
    "result": { "content": [{ "type": "text", "text": "true" }], "isError": false }
  }
}
```

---

### 4.2 Server → Dispositivo

1. **Hello** — risposta di handshake del server (deve contenere `"type":"hello"`).

2. **STT** — risultato ASR dal server:
```json
{"session_id": "xxx", "type": "stt", "text": "..."}
```

3. **LLM** — comandi LLM che possono includere emozione o testo visuale:
```json
{"session_id": "xxx", "type": "llm", "emotion": "happy", "text": "😀"}
```

4. **TTS** — controllo del flusso di sintesi vocale:
```json
{"session_id": "xxx", "type": "tts", "state": "start"}
```
e
```json
{"session_id": "xxx", "type": "tts", "state": "stop"}
```
Il server può anche inviare `sentence_start` con testo da visualizzare.

5. **MCP** — comandi o risultati MCP (es. chiamata `tools/call`):
```json
{
  "session_id": "xxx",
  "type": "mcp",
  "payload": {
    "jsonrpc": "2.0",
    "method": "tools/call",
    "params": { "name": "self.light.set_rgb", "arguments": { "r":255, "g":0, "b":0 } },
    "id": 1
  }
}
```

6. **System** — comandi di sistema (es. reboot):
```json
{"session_id": "xxx", "type": "system", "command": "reboot"}
```

7. **Custom** — messaggi personalizzati se abilitati (`CONFIG_RECEIVE_CUSTOM_MESSAGE`).

8. **Dati audio binari** — frame Opus da decodificare e riprodurre; se il dispositivo sta registrando i frame possono essere ignorati per evitare conflitti.

---

## 5. Codec audio

1. **Invio registrazione**  
   - L'audio acquisito viene processato (AEC/denoise/gain opzionali), codificato in Opus e inviato al server.  
   - A seconda della versione protocollo si inviano direttamente i frame Opus (v1) o con wrapper binario (v2/v3).

2. **Riproduzione**  
   - I frame binari ricevuti sono decodificati come Opus e inviati all'uscita audio.  
   - Se il sample rate server ≠ device, viene effettuato un resampling.

---

## 6. Stati tipici

Flussi di stato comuni in relazione ai messaggi WebSocket:

1. Idle → Connecting: l'utente innesca `OpenAudioChannel()` → stabilisce WebSocket → invia `hello`.
2. Connecting → Listening: connessione stabilita e si avvia la registrazione.
3. Listening → Speaking: server invia `tts start` → stop registrazione e playback audio.
4. Speaking → Idle: `tts stop` → ritorno a idle (o auto-listen se configurato).
5. Listening/Speaking → Idle: abort o disconnessione.

Diagrammi di stato automatico/manuale (mermaid) identici all'originale.

---

## 7. Gestione errori

1. **Connessione fallita**: `Connect(url)` fallisce o manca la risposta `hello` → `on_network_error_()` → messaggio di errore.  
2. **Server disconnesso**: `OnDisconnected()` → `on_audio_channel_closed_()` → ritorno a Idle o logica di retry.

---

## 8. Note utili

1. **Autenticazione**: il server deve validare `Authorization: Bearer <token>`. Token scaduti possono causare rifiuto handshake.  
2. **Controllo sessione**: `session_id` serve a separare conversazioni e può essere usato dal server per isolare stati.  
3. **Carico audio**: default Opus 16k mono, `OPUS_FRAME_DURATION_MS` controlla la durata del frame (tipicamente 60ms). Server può usare 24k per riproduzione musicale.  
4. **Versione protocollo**: scegliere 1/2/3 a seconda delle necessità (AEC, timestamp, ecc.).  
5. **Controllo IoT**: usare preferibilmente MCP (`type: "mcp"`) per discovery, controllo e sincronizzazione di stato; il vecchio schema `type: "iot"` è deprecato.
