# Compilazione e configurazione — AtomS3R + Echo Pyramid

## Impostare il target su ESP32S3

```bash
idf.py set-target esp32s3
```

Aprire `menuconfig`:

```bash
idf.py menuconfig
```

Selezionare la board:

```text
Xiaozhi Assistant -> Board Type -> M5Stack AtomS3R + Echo Pyramid
```

Impostazioni importanti:

- `Serial flasher config` → `Flash size` → `8 MB`
- `Partition Table` → `Custom partition CSV file` → `partitions/v2/8m.csv`
- `Component config` → `ESP PSRAM` → `SPI RAM config` → `Mode (QUAD/OCT)` → abilitare `Octal Mode PSRAM` se necessario

Compilare:

```bash
idf.py build
```

## Uso

Alimentare l'Echo Pyramid tramite la porta USB‑C della base. La porta USB‑C dell'AtomS3R è utilizzata principalmente per il flashing.

Riferimenti:

https://github.com/m5stack/M5Echo-Pyramid
