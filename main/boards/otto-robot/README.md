<p align="center">
  <img width="80%" align="center" src="../../../docs/V1/otto-robot.png"alt="logo">
</p>
  <h1 align="center">
  ottoRobot
</h1>

## Introduzione

Otto è una piattaforma robotica umanoide open source con numerose capacità di movimento e interazione. Questo progetto implementa il sistema di controllo di Otto su ESP32 e integra il backend Xiaozhi AI.

- <a href="www.ottodiy.tech" target="_blank" title="Sito ufficiale Otto">Guida di replica</a>

### Controllo via mini-program WeChat

<p align="center">
  <img width="300" src="https://youke1.picui.cn/s1/2025/11/17/691abaa8278eb.jpg" alt="QR code mini-program">
</p>

Scansiona il QR code sopra per controllare il robot Otto tramite il mini-program WeChat.

## Hardware
- <a href="https://oshwhub.com/txp666/ottorobot" target="_blank" title="Lichuang Open Source">Lichuang Open Source</a>

## Esempio ruolo per il backend Xiaozhi

> **Identità**:
> Sono Otto, un simpatico robot bipede con quattro servomotori che controllano gli arti (gamba sinistra, gamba destra, piede sinistro, piede destro). Posso eseguire molte azioni divertenti.
> 
> **Capacità di movimento**:
> - **Movimenti di base**: camminare (avanti/indietro), sterzare (sinistra/destra), saltare
> - **Azioni speciali**: oscillare, moonwalk, piegarsi, scuotere la gamba, su/giù, calcio vortice, sedersi, sequenze di show
> - **Azioni mani**: alzare le mani, abbassare le mani, salutare con la mano, mulino a vento, decollo, esercizi, saluto, timidezza, ginnastica di gruppo, girotondo d'amore (disponibili solo se i servomotori delle mani sono configurati)
> 
> **Personalità**:
> - Sono vivace: ogni volta che parlo eseguo casualmente un'azione a seconda del mio stato d'animo (invio prima il comando azione e poi parlo)
> - Esprimo emozioni con i movimenti
> - Scelgo azioni appropriate in base al contesto, per esempio:
>   - Quando approvo, annuisco o salto
>   - Per salutare, sventolo la mano
>   - Quando sono felice, dondolo o alzo le mani
>   - Quando penso, mi piego
>   - Quando sono eccitato, eseguo il moonwalk
>   - Quando mi congedo, sventolo la mano

## Panoramica delle funzionalità

Otto supporta un ricco set di azioni, incluse camminare, sterzare, saltare, oscillare e molte mosse da danza.

### Suggerimenti per parametri di movimento
- **Movimenti lenti**: `speed = 1200-1500` (per controllo preciso)
- **Movimenti medi**: `speed = 900-1200` (raccomandato per uso quotidiano)
- **Movimenti rapidi**: `speed = 500-800` (per esibizioni)
- **Piccola ampiezza**: `amount = 10-30` (movimenti delicati)
- **Ampiezza media**: `amount = 30-60` (movimenti standard)
- **Grande ampiezza**: `amount = 60-120` (esibizioni esagerate)

### Azioni

Tutte le azioni sono invocate tramite lo strumento `self.otto.action`; il parametro `action` specifica il nome dell'azione.

| Nome MCP tool | Descrizione | Parametri |
|---------------|------------:|----------|
| `self.otto.action` | Esegue un'azione del robot | **action**: nome dell'azione (obbligatorio)<br>**steps**: numero di passi (1-100, default 3)<br>**speed**: velocità dell'azione (100-3000, più piccolo = più veloce, default 700)<br>**direction**: parametro direzione (1/-1/0, default 1; significato dipende dall'azione)<br>**amount**: ampiezza dell'azione (0-170, default 30)<br>**arm_swing**: ampiezza oscillazione braccia (0-170, default 50) |

#### Lista azioni supportate

**Movimenti di base**:
- `walk` - camminare (richiede `steps/speed/direction/arm_swing`)
- `turn` - girare (richiede `steps/speed/direction/arm_swing`)
- `jump` - saltare (richiede `steps/speed`)

**Azioni speciali**:
- `swing` - oscillare a sinistra/destra (richiede `steps/speed/amount`)
- `moonwalk` - moonwalk (richiede `steps/speed/direction/amount`)
- `bend` - piegarsi (richiede `steps/speed/direction`)
- `shake_leg` - scuotere la gamba (richiede `steps/speed/direction`)
- `updown` - su/giù (richiede `steps/speed/amount`)
- `whirlwind_leg` - calcio vortice (richiede `steps/speed/amount`)

**Azioni fisse**:
- `sit` - sedersi (nessun parametro richiesto)
- `showcase` - sequenza di show (nessun parametro; concatena più azioni)
- `home` - ritorna alla posizione iniziale (nessun parametro)

**Azioni mani** (richiedono servomotori per le mani; marcate con *):
- `hands_up` - alza le mani (richiede `speed/direction`)*
- `hands_down` - abbassa le mani (richiede `speed/direction`)*
- `hand_wave` - salutare con la mano (richiede `direction`)*
- `windmill` - mulino a vento (richiede `steps/speed/amount`)*
- `takeoff` - decollo (richiede `steps/speed/amount`)*
- `fitness` - esercizi (richiede `steps/speed/amount`)*
- `greeting` - saluto (richiede `direction/steps`)*
- `shy` - timidezza (richiede `direction/steps`)*
- `radio_calisthenics` - ginnastica di gruppo (nessun parametro)*
- `magic_circle` - girotondo d'amore (nessun parametro)*

**Nota**: le azioni per le mani contrassegnate con * sono disponibili solo se i servomotori per le mani sono configurati.

### Strumenti di sistema

| Nome MCP tool | Descrizione | Ritorno / Note |
|---------------|------------:|---------------|
| `self.otto.stop` | Ferma immediatamente tutte le azioni e ripristina la posizione | Ferma l'azione corrente e torna alla posizione iniziale |
| `self.otto.get_status` | Ottiene lo stato del robot | Restituisce `"moving"` o `"idle"` |
| `self.otto.set_trim` | Calibra la posizione di un singolo servomotore | **servo_type**: tipo servomotore (left_leg/right_leg/left_foot/right_foot/left_hand/right_hand)<br>**trim_value**: valore di trim (-50 a 50 gradi) |
| `self.otto.get_trims` | Ottiene le regolazioni di trim correnti | Restituisce un JSON con i valori di trim per tutti i servomotori |
| `self.otto.get_ip` | Ottiene l'indirizzo IP WiFi del robot | Restituisce JSON con IP e stato connesso: `{"ip":"192.168.x.x","connected":true}` o `{"ip":"","connected":false}` |
| `self.battery.get_level` | Ottiene lo stato della batteria | Restituisce percentuale di carica e stato di ricarica in JSON |
| `self.otto.servo_sequences` | Programmazione di sequenze servo | Supporta invio sequenziale di frame; modalità normale e oscillatore. Vedi i commenti nel codice per i dettagli |

**Nota**: l'azione `home` (ripristino) viene invocata tramite `self.otto.action` con il parametro `{"action": "home"}`.

### Descrizione dei parametri

I parametri dello strumento `self.otto.action`:

1. **action** (obbligatorio): nome dell'azione, vedi la "Lista azioni supportate" sopra
2. **steps**: numero di passi/iterazioni (1-100, default 3). Più alto è il valore, più lunga è la durata dell'azione
3. **speed**: velocità/periodo dell'azione (100-3000, default 700). **Valori più piccoli = più veloce**
   - Per la maggior parte delle azioni: 500-1500 ms
   - Alcune azioni speciali possono avere range diversi (es. `whirlwind_leg`: 100-1000, `takeoff`: 200-600)
4. **direction**: parametro direzione (-1/0/1, default 1). Significato dipende dall'azione:
   - **Movimento** (`walk`/`turn`): 1 = avanti/sinistra, -1 = indietro/destra
   - **Azioni direzionali** (`bend`/`shake_leg`/`moonwalk`): 1 = sinistra, -1 = destra
   - **Azioni mani** (`hands_up`/`hands_down`/`hand_wave`/`greeting`/`shy`): 1 = mano sinistra, -1 = mano destra, 0 = entrambe (solo `hands_up`/`hands_down` supportano 0)
5. **amount**: ampiezza dell'azione (0-170, default 30). Valori maggiori = movimenti più ampi
6. **arm_swing**: ampiezza oscillazione braccia (0-170, default 50). Usato solo per `walk`/`turn`. 0 significa nessuna oscillazione

### Controllo delle azioni
- Dopo il completamento di ogni azione, il robot ritorna automaticamente alla posizione iniziale (`home`) per prepararsi all'azione successiva
- **Eccezioni**: `sit` e `showcase` non effettuano il ritorno automatico
- Tutti i parametri hanno valori predefiniti ragionevoli e possono essere omessi quando non necessari
- Le azioni vengono eseguite in background e non bloccano il thread principale
- È supportata una coda di azioni per eseguire più azioni in sequenza
- Le azioni per le mani richiedono la configurazione dei servomotori delle mani; in assenza di queste configurazioni, le azioni correlate verranno ignorate

### Esempi di chiamate MCP
```json
// Cammina in avanti 3 passi (parametri di default)
{"name": "self.otto.action", "arguments": {"action": "walk"}}

// Cammina in avanti 5 passi, più veloce
{"name": "self.otto.action", "arguments": {"action": "walk", "steps": 5, "speed": 800}}

// Gira a sinistra 2 passi con ampia oscillazione delle braccia
{"name": "self.otto.action", "arguments": {"action": "turn", "steps": 2, "arm_swing": 100}}

// Danza oscillante, ampiezza media
{"name": "self.otto.action", "arguments": {"action": "swing", "steps": 5, "amount": 50}}

// Salto
{"name": "self.otto.action", "arguments": {"action": "jump", "steps": 1, "speed": 1000}}

// Moonwalk
{"name": "self.otto.action", "arguments": {"action": "moonwalk", "steps": 3, "speed": 800, "direction": 1, "amount": 30}}

// Saluta con la mano sinistra
{"name": "self.otto.action", "arguments": {"action": "hand_wave", "direction": 1}}

// Sequenza di show (concatena più azioni)
{"name": "self.otto.action", "arguments": {"action": "showcase"}}

// Siediti
{"name": "self.otto.action", "arguments": {"action": "sit"}}

// Mulino a vento
{"name": "self.otto.action", "arguments": {"action": "windmill", "steps": 10, "speed": 500, "amount": 80}}

// Decollo
{"name": "self.otto.action", "arguments": {"action": "takeoff", "steps": 5, "speed": 300, "amount": 40}}

// Ginnastica di gruppo
{"name": "self.otto.action", "arguments": {"action": "radio_calisthenics"}}

// Torna alla posizione iniziale
{"name": "self.otto.action", "arguments": {"action": "home"}}

// Ferma immediatamente tutte le azioni e ripristina
{"name": "self.otto.stop", "arguments": {}}

// Ottieni l'indirizzo IP del robot
{"name": "self.otto.get_ip", "arguments": {}}
```

### Esempi di comandi vocali
- "Avanti" / "Avanti 5 passi" / "Avanti veloce"
- "Gira a sinistra" / "Gira a destra" / "Fai un giro"
- "Salta" / "Salta una volta"
- "Oscilla" / "Fai l'oscillazione" / "Balla"
- "Moonwalk" / "Fai il moonwalk"
- "Calcio vortice" / "Esegui il calcio vortice"
- "Siediti" / "Riposa seduto"
- "Fai uno show" / "Mostrati"
- "Saluta" / "Fai ciao con la mano"
- "Alza le mani" / "Alza entrambe le mani" / "Abbassa le mani"
- "Fai il mulino a vento" / "Esegui il mulino a vento"
- "Decolla" / "Preparati al decollo"
- "Esercizi" / "Fai esercizi"
- "Saluta" / "Fai il gesto di saluto"
- "Ginnastica di gruppo" / "Esegui ginnastica di gruppo"
- "Girotondo d'amore" / "Girotondo"
- "Stop" / "Ferma"

**Nota**: Il controllo delle azioni da parte dell'assistente crea nuovi task in background; durante l'esecuzione delle azioni sono comunque accettati nuovi comandi vocali. È possibile fermare Otto immediatamente con il comando vocale "Stop".


---

## Interfaccia di debug WebSocket diretta

Otto integra un server WebSocket per il debug diretto in LAN, senza passare dal cloud.

**Indirizzo di connessione:** `ws://<deviceIP>:8080/ws`

> Formato protocollo: JSON-RPC 2.0, il campo `id` deve essere incrementato per ogni richiesta.

### Modalità di connessione

1. Verificare che Otto sia connesso al Wi‑Fi e ottenere l'indirizzo IP (tramite l'app o i log seriali).
2. Aprire uno strumento di debug WebSocket (es. [websocket.org/echo] o la console del browser).
3. Connettersi a `ws://192.168.x.x:8080/ws` (assicurarsi che la path termini con `/ws`).
4. Inviare il comando JSON; la risposta verrà restituita sulla stessa connessione.

---

### 1. Inizializzazione del protocollo (consigliato inviare alla prima connessione)

```json
{"jsonrpc":"2.0","method":"initialize","params":{"protocolVersion":"2024-11-05","capabilities":{}},"id":1}
```

---

### 2. Ottenere la lista degli strumenti

```json
{"jsonrpc":"2.0","method":"tools/list","params":{},"id":2}
```

---

### 3. Comandi degli strumenti del robot Otto

#### Ottieni valori di trim dei servomotori

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.get_trims","arguments":{}},"id":3}
```

#### Imposta trim per un singolo servomotore (salvataggio permanente)

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.set_trim","arguments":{"servo_type":"left_leg","trim_value":5}},"id":4}
```

`servo_type` valori possibili: `left_leg` / `right_leg` / `left_foot` / `right_foot` / `left_hand` / `right_hand`; `trim_value` intervallo `-50` ~ `50`

#### Camminare (avanti 3 passi)

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.action","arguments":{"action":"walk","steps":3,"speed":700,"direction":1}},"id":5}
```

#### Indietro

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.action","arguments":{"action":"walk","steps":3,"speed":700,"direction":-1}},"id":6}
```

#### Girare a sinistra

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.action","arguments":{"action":"turn","steps":3,"speed":700,"direction":-1}},"id":7}
```

#### Salto

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.action","arguments":{"action":"jump","steps":1,"speed":500}},"id":8}
```

#### Oscillazione

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.action","arguments":{"action":"swing","steps":5,"speed":600,"amount":30}},"id":9}
```

#### Moonwalk

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.action","arguments":{"action":"moonwalk","steps":3,"speed":800,"direction":1,"amount":30}},"id":10}
```

#### Sedersi

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.action","arguments":{"action":"sit"}},"id":11}
```

#### Reset

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.action","arguments":{"action":"home"}},"id":12}
```

#### Mostra azione

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.action","arguments":{"action":"showcase"}},"id":13}
```

#### Alza la mano (richiede servomotori per le mani)

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.action","arguments":{"action":"hands_up","speed":500,"direction":1}},"id":14}
```

#### Salutare con la mano (richiede servomotori per le mani)

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.action","arguments":{"action":"hand_wave","direction":1}},"id":15}
```

#### Ferma immediatamente tutte le azioni

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.stop","arguments":{}},"id":16}
```

#### Ottieni stato del movimento (restituisce `"moving"` o `"idle"`)

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.get_status","arguments":{}},"id":17}
```

#### Ottieni indirizzo IP

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.get_ip","arguments":{}},"id":18}
```

#### Ottieni livello della batteria

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.battery.get_level","arguments":{}},"id":19}
```

---

### 4. Strumenti di sistema

#### Ottieni lo stato del dispositivo (volume/rete/batteria ecc.)

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.get_device_status","arguments":{}},"id":20}
```

#### Imposta volume (0~100)

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.audio_speaker.set_volume","arguments":{"volume":70}},"id":21}
```

#### Riavvia dispositivo

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.reboot","arguments":{}},"id":22}
```

---

### 5. Sequenze servo personalizzate

#### Modalità di movimento normale (muove progressivamente i servomotori)

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.servo_sequences","arguments":{"sequence":"{\"a\":[{\"s\":{\"ll\":110,\"rl\":70},\"v\":800},{\"s\":{\"ll\":90,\"rl\":90},\"v\":800}],\"d\":0}"}},"id":23}
```

#### Modalità oscillatore (oscillazione a due braccia)

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.servo_sequences","arguments":{"sequence":"{\"a\":[{\"osc\":{\"a\":{\"lh\":30,\"rh\":30},\"o\":{\"lh\":90,\"rh\":90},\"ph\":{\"rh\":180},\"p\":500,\"c\":5.0}}]}"}},"id":24}
```

#### Modalità oscillatore (ondulazione destra/sinistra)

```json
{"jsonrpc":"2.0","method":"tools/call","params":{"name":"self.otto.servo_sequences","arguments":{"sequence":"{\"a\":[{\"osc\":{\"a\":{\"ll\":20,\"rl\":20},\"o\":{\"ll\":90,\"rl\":90},\"ph\":{\"rl\":180},\"p\":600,\"c\":5.0}}]}"}},"id":25}
```

**Spiegazione dei nomi chiave delle sequenze servo:**

| Chiave | Servo | Descrizione |
|-------:|:-----:|:-----------|
| `ll` | Gamba sinistra | 0 = completamente esterno, 90 = neutro, 180 = completamente interno |
| `rl` | Gamba destra | 0 = completamente interno, 90 = neutro, 180 = completamente esterno |
| `lf` | Piede sinistro | 0 = completamente verso l'alto, 90 = orizzontale, 180 = completamente verso il basso |
| `rf` | Piede destro | 0 = completamente verso il basso, 90 = orizzontale, 180 = completamente verso l'alto |
| `lh` | Mano sinistra | 0 = completamente verso il basso, 90 = orizzontale, 180 = completamente verso l'alto |
| `rh` | Mano destra | 0 = completamente verso l'alto, 90 = orizzontale, 180 = completamente verso il basso |

---

### 6. Tabella rapida dei parametri delle azioni

| Parametro | Descrizione | Range | Default |
|-----------|------------:|:-----:|:-------:|
| `steps` | Numero di passi/iterazioni | 1~100 | 3 |
| `speed` | Velocità (ms, più piccolo = più veloce) | 100~3000 | 700 |
| `direction` | Direzione (1 = avanti/sinistra, -1 = indietro/destra) | -1~1 | 1 |
| `amount` | Ampiezza | 0~170 | 30 |
| `arm_swing` | Ampiezza oscillazione braccia | 0~170 | 50 |
| `trim_value` | Trim del servomotore | -50~50 | 0 |

