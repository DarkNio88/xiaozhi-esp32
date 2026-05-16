# AtomS3R CAM/M12 + Echo Base

## Introduzione

<div align="center">
    <a href="https://docs.m5stack.com/zh_CN/core/AtomS3R%20Cam"><b> Pagina prodotto AtomS3R CAM </b></a>
    |
    <a href="https://docs.m5stack.com/zh_CN/core/AtomS3R-M12"><b> Pagina prodotto AtomS3R M12 </b></a>
    |
    <a href="https://docs.m5stack.com/zh_CN/atom/Atomic%20Echo%20Base"><b> Pagina prodotto Echo Base </b></a>
</div>

AtomS3R CAM e AtomS3R M12 sono controller IoT programmabili di M5Stack basati su ESP32-S3-PICO-1-N8R8 e dotati di fotocamera. Atomic Echo Base è una base per riconoscimento vocale progettata per le unità M5 Atom, che integra un decoder audio mono ES8311, microfoni MEMS e un amplificatore di potenza NS4150B.

Entrambe le schede **non includono schermo né pulsanti aggiuntivi** e richiedono il risveglio vocale. Se necessario, usa `idf.py monitor` per visualizzare i log e verificare lo stato di esecuzione.

## Configurazione e comandi di compilazione

**Imposta il target di compilazione su ESP32S3**

```bash
idf.py set-target esp32s3
```

**Apri menuconfig e configura**

```bash
idf.py menuconfig
```

Configura le seguenti opzioni:

- `Xiaozhi Assistant` → `Board Type` → seleziona `AtomS3R CAM/M12 + Echo Base`
- `Xiaozhi Assistant` → `IoT Protocol` → seleziona `MCP protocol` per abilitare il riconoscimento della fotocamera
- `Partition Table` → `Custom partition CSV file` → cancella il contenuto esistente e inserisci `partitions/v2/8m.csv`
- `Serial flasher config` → `Flash size` → seleziona `8 MB`

Premi `S` per salvare e `Q` per uscire.

**Compilazione**

```bash
idf.py build
```

**Flash**

Collega AtomS3R CAM/M12 al computer e tieni premuto il tasto RESET laterale finché il LED verde sotto il tasto non lampeggia.

```bash
idf.py flash
```

Dopo il flashing, premi il tasto RESET per riavviare.
