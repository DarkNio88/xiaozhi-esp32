# AtomEchoS3R

Breve descrizione e comandi per AtomEchoS3R.

AtomEchoS3R è una scheda di sviluppo basata su ESP32‑S3‑PICO‑1‑N8R8, dotata di decoder audio ES8311, microfono MEMS e amplificatore NS4150B.

Questa scheda non include display né pulsanti aggiuntivi; il risveglio avviene tramite la parola chiave vocale. Per debug usare `idf.py monitor`.

## Configurazione e compilazione

Impostare il target su ESP32S3:

```bash
idf.py set-target esp32s3
```

Aprire il menu di configurazione:

```bash
idf.py menuconfig
```

Impostazioni principali:

- `Xiaozhi Assistant` → `Board Type` → `AtomEchoS3R`
- `Partition Table` → `Custom partition CSV file` → `partitions/v2/8m.csv`
- `Serial flasher config` → `Flash size` → `8 MB`
- `Component config` → `ESP PSRAM` → abilitare `Octal Mode PSRAM` se necessario

Salvare con `S`, uscire con `Q`.

Compilare e flashare:

```bash
idf.py build
idf.py flash
```

Premere RESET dopo il flashing per riavviare la scheda.
