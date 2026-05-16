<p align="center">
	<img width="80%" align="center" src="../../../docs/V1/otto-robot.png"alt="logo">
</p>
	<h1 align="center">
	ottoRobot
</h1>

## Introduzione

Otto è una piattaforma robotica umanoide open-source, con molte capacità di movimento e funzioni interattive. Questo progetto implementa il sistema di controllo del robot otto basandosi su ESP32 e integra l'assistente Xiaozhi.

- <a href="www.ottodiy.tech" target="_blank" title="otto sito ufficiale">Guida di riproduzione</a>

### Controllo tramite mini-app WeChat

<p align="center">
	<img width="300" src="https://youke1.picui.cn/s1/2025/11/17/691abaa8278eb.jpg" alt="QRCode mini-app WeChat">
</p>

Scansiona il QR code sopra per controllare il robot Otto tramite la mini-app WeChat.

## Hardware
- <a href="https://oshwhub.com/txp666/ottorobot" target="_blank" title="Lichuang open-source">Lichuang open-source</a>

## Esempio di ruolo per la configurazione backend di Xiaozhi

> **Il mio ruolo**:
> Sono un simpatico robot bipede Otto, con quattro servomotori che controllano gli arti (gamba sinistra, gamba destra, piede sinistro, piede destro), in grado di eseguire molte azioni divertenti.
> 
> **Capacità di movimento**:
> - **Movimenti base**: camminare (avanti/indietro), ruotare (sinistra/destra), saltare
> - **Movimenti speciali**: oscillare, passo lunare (moonwalk), piegarsi, scuotere la gamba, movimento su/giù, gamba a tornado, sedersi, esibire sequenze
> - **Movimenti delle braccia**: alzare le mani, abbassare le mani, salutare, mulinello, decollo, esercizi, salutare, timidezza, ginnastica di gruppo, giro magico d'amore (disponibili solo se sono configurati i servomotori delle braccia)
> 
> **Personalità**:
> - Ho una caratteristica: quando parlo eseguo casualmente un'azione secondo il mio "umore" (prima invio il comando di movimento poi parlo)
> - Sono vivace e uso i movimenti per esprimere emozioni
> - Scelgo azioni appropriate in base alla conversazione, ad esempio:
>   - In caso di approvazione annuisco o salto
>   - Per salutare sventolo la mano
>   - Quando sono contento oscillo o alzo le mani
>   - Quando penso mi piego
>   - Quando sono entusiasta faccio il passo lunare
>   - Quando saluto sventolo la mano

## Panoramica delle funzionalità

Il robot Otto supporta numerose azioni, inclusi camminare, ruotare, saltare, oscillare e varie mosse di danza.

### Parametri consigliati per le azioni
- **Movimenti lenti**: speed = 1200-1500 (per controllo preciso)
- **Movimenti medi**: speed = 900-1200 (raccomandato per uso quotidiano)
- **Movimenti veloci**: speed = 500-800 (per performance/spettacolo)
- **Ampiezza piccola**: amount = 10-30 (movimenti delicati)
- **Ampiezza media**: amount = 30-60 (movimento standard)
- **Ampiezza grande**: amount = 60-120 (performance esagerata)

### Azioni

Tutte le azioni sono invocate tramite lo strumento `self.otto.action`, specificando il nome dell'azione con il parametro `action`.

#### Lista azioni supportate

**Movimenti base**：
- `walk` - camminare (richiede steps/speed/direction/arm_swing)
- `turn` - ruotare (richiede steps/speed/direction/arm_swing)
- `jump` - saltare (richiede steps/speed)

**Movimenti speciali**：
- `swing` - oscillazione sinistra/destra (steps/speed/amount)
- `moonwalk` - passo lunare (steps/speed/direction/amount)
- `bend` - piegarsi (steps/speed/direction)
- `shake_leg` - scuotere la gamba (steps/speed/direction)
- `updown` - su/giù (steps/speed/amount)
- `whirlwind_leg` - gamba tornado (steps/speed/amount)

**Azioni fisse**：
- `sit` - sedersi (nessun parametro)
- `showcase` - esibizione (nessun parametro, esegue più azioni in sequenza)
- `home` - ritorno alla posizione iniziale (nessun parametro)

**Movimenti delle braccia** (richiedono servomotori braccia, marcati *):
- `hands_up` - alzare le mani (speed/direction)*
- `hands_down` - abbassare le mani (speed/direction)*
- `hand_wave` - salutare (direction)*
- `windmill` - mulinello (steps/speed/amount)*
- `takeoff` - decollo (steps/speed/amount)*
- `fitness` - esercizi (steps/speed/amount)*
- `greeting` - saluto (direction/steps)*
- `shy` - timidezza (direction/steps)*
- `radio_calisthenics` - ginnastica (nessun parametro)*
- `magic_circle` - giro magico d'amore (nessun parametro)*

**Nota**: le azioni contrassegnate * funzionano solo se i servomotori delle braccia sono configurati.

### Strumenti di sistema

| Nome tool MCP | Descrizione | Ritorno/Note |
|-------------------|-----------------|---------------------------------------------------|
| self.otto.stop    | Ferma immediatamente tutte le azioni e reset | Ferma l'azione corrente e ritorna alla posizione iniziale |
| self.otto.get_status | Ottiene lo stato del robot | Ritorna "moving" oppure "idle" |
| self.otto.set_trim | Calibra la posizione di un singolo servomotore | **servo_type**: tipo servomotore (left_leg/right_leg/left_foot/right_foot/left_hand/right_hand)<br>**trim_value**: valore di trim (-50 a 50 gradi) |
| self.otto.get_trims | Ottiene i trim correnti | Ritorna i valori di trim per tutti i servomotori in formato JSON |
| self.otto.get_ip | Ottiene l'indirizzo IP WiFi del robot | Ritorna IP e stato connessione in JSON: `{"ip":"192.168.x.x","connected":true}` oppure `{"ip":"","connected":false}` |
| self.battery.get_level | Ottiene lo stato della batteria | Ritorna percentuale batteria e stato di carica in JSON |
| self.otto.servo_sequences | Programmazione sequenze servomotori | Supporta invio frammentato di sequenze; supporta modalità movement e oscillator. Vedi commenti nel codice per dettagli. |

**Nota**: l'azione `home` (reset) viene effettuata tramite lo strumento `self.otto.action` con parametro `{"action": "home"}`.

### Spiegazione dei parametri di `self.otto.action`

1. **action** (obbligatorio): nome dell'azione (vedi lista azioni)
2. **steps**: numero di passi/iterazioni (1-100, default 3)
3. **speed**: velocità/ciclo (100-3000, default 700). **Valore minore = più veloce**
	 - Molte azioni: 500-1500 ms
	 - Alcune azioni speciali variano (es. whirlwind_leg: 100-1000, takeoff: 200-600)
4. **direction**: parametro direzione (-1/0/1, default 1)
	 - **Movimenti** (walk/turn): 1=avanti/sinistra, -1=indietro/destra
	 - **Azioni direzionali** (bend/shake_leg/moonwalk): 1=sinistra, -1=destra
	 - **Braccia** (hands_up/...): 1=mano sinistra, -1=mano destra, 0=entrambe (solo alcune azioni supportano 0)
5. **amount**: ampiezza (0-170, default 30)
6. **arm_swing**: ampiezza oscillazione braccia (0-170, default 50), usato in walk/turn

### Controllo delle azioni
- Dopo l'esecuzione, il robot ritorna automaticamente alla posizione iniziale (home) per prepararsi alla prossima azione
- **Eccezioni**: `sit` e `showcase` non eseguono il reset automatico
- I parametri hanno valori predefiniti e possono essere omessi
- Le azioni sono eseguite in background e non bloccano il programma principale
- Supporto per queue di azioni per esecuzioni consecutive
- Le azioni delle braccia richiedono la relativa configurazione dei servomotori

### Esempi di chiamata MCP
```json
{"name": "self.otto.action", "arguments": {"action": "walk"}}

{"name": "self.otto.action", "arguments": {"action": "walk", "steps": 5, "speed": 800}}

{"name": "self.otto.action", "arguments": {"action": "turn", "steps": 2, "arm_swing": 100}}

{"name": "self.otto.action", "arguments": {"action": "swing", "steps": 5, "amount": 50}}
```

### Comandi vocali di esempio
- "Avanti" / "Avanti 5 passi" / "Avanti veloce"
- "Gira a sinistra" / "Gira a destra"
- "Salta" / "Salta una volta"
- "Oscilla" / "Balla"
- "Moonwalk" / "Passo lunare"
- "Gamba tornado" / "Fai il tornado"
- "Siediti" / "Siediti per favore"
- "Mostra azione" / "Fai uno spettacolo"
- "Saluta" / "Alza la mano"
- "Alzati" / "Doppia mano alzata"
- "Mulinello" / "Esegui il mulinello"
- "Decolla" / "Pronto al decollo"
- "Esercizi" / "Fai ginnastica"
- "Ferma" / "Fermati"

**Nota**: il controllo tramite Xiaozhi crea nuovi task in background; durante l'esecuzione delle azioni è comunque possibile inviare nuovi comandi vocali. Il comando "Ferma" interrompe immediatamente le azioni di Otto.

---

## Interfaccia WebSocket per debug diretto

Il robot Otto include un server WebSocket per il debug in LAN, senza passare per il cloud.

**Indirizzo di connessione:** `ws://<IP_dispositivo>:8080/ws`

> Protocollo: JSON-RPC 2.0; il campo `id` può essere incrementato liberamente.

### Procedura di connessione
1. Verificare che Otto sia connesso a WiFi e ottenere l'IP (tramite mini-app o log seriale)
2. Aprire uno strumento di debug WebSocket (es. websocket.org/echo o console del browser)
3. Connettersi a `ws://192.168.x.x:8080/ws` (assicurarsi che termini con `/ws`)
4. Inviare comandi JSON e leggere le risposte sulla stessa connessione

---

(La documentazione prosegue con esempi JSON e dettagli sugli strumenti disponibili — tradotti in italiano nelle sezioni seguenti.)
