# AtomS3R CAM/M12 + Echo Base

Panoramica e istruzioni per AtomS3R CAM/M12 con Echo Base.

## Introduzione

AtomS3R CAM e AtomS3R M12 sono controllori programmabili basati su ESP32‑S3‑PICO‑1‑N8R8 con fotocamera. Echo Base è una scheda base per riconoscimento vocale per la serie M5 Atom, dotata di decoder audio mono ES8311, microfono MEMS e amplificatore di potenza NS4150B.

Queste schede di sviluppo non dispongono di display né di pulsanti aggiuntivi; il risveglio avviene tramite voce. Se necessario, usare `idf.py monitor` per visualizzare i log e diagnosticare lo stato.

## Configurazione e compilazione

Impostare il target su ESP32S3:

```bash
idf.py set-target esp32s3
```

Aprire il menu di configurazione:

```bash
idf.py menuconfig
```

Configurare le opzioni seguenti:

- `Xiaozhi Assistant` → `Board Type` → selezionare `AtomS3R CAM/M12 + Echo Base`
- `Xiaozhi Assistant` → `IoT Protocol` → selezionare `MCP协议` per abilitare il riconoscimento da camera
- `Partition Table` → `Custom partition CSV file` → impostare `partitions/v2/8m.csv`
- `Serial flasher config` → `Flash size` → `8 MB`

Salvare con `S` e uscire con `Q`.

Compilare:

```bash
idf.py build
```

Flash del firmware:

```bash
idf.py flash
```

Dopo il flashing, premere il pulsante RESET per riavviare la scheda.
