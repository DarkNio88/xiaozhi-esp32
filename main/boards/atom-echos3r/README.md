# AtomEchoS3R
## Introduzione

AtomEchoS3R è un controller IoT programmabile prodotto da M5Stack basato su ESP32-S3-PICO-1-N8R8; integra il codec audio mono ES8311, microfoni MEMS e l'amplificatore di potenza NS4150B.

La versione di sviluppo **non include display né pulsanti aggiuntivi**: è necessario usare il wake word per l'attivazione vocale. Se necessario, utilizzare `idf.py monitor` per visualizzare i log e verificare lo stato di esecuzione.

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

- `Xiaozhi Assistant` → `Board Type` → seleziona `AtomEchoS3R`
- `Partition Table` → `Custom partition CSV file` → rimuovi il contenuto esistente e inserisci `partitions/v2/8m.csv`
- `Serial flasher config` → `Flash size` → seleziona `8 MB`
- `Component config` → `ESP PSRAM` → `Support for external, SPI-connected RAM` → `SPI RAM config` → seleziona `Octal Mode PSRAM`

Premi `S` per salvare e `Q` per uscire.

**Compilazione**

```bash
idf.py build
```

**Scrittura (flash)**

Collega AtomEchoS3R al computer e tieni premuto il pulsante RESET laterale finché il LED verde sotto il pulsante non lampeggia.

```bash
idf.py flash
```

Dopo il flash, premi il pulsante RESET una volta per riavviare il dispositivo.
