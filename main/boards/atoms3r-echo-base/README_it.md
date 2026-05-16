# AtomS3R + Echo Base

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
Xiaozhi Assistant -> Board Type -> AtomS3R + Echo Base
```

Impostazioni consigliate:

- `Serial flasher config` → `Flash size` → `8 MB`
- `Partition Table` → `Custom partition CSV file` → `partitions/v2/8m.csv`
- `Component config` → `ESP PSRAM` → `SPI RAM config` → `Mode (QUAD/OCT)` → abilitare `Octal Mode PSRAM` se necessario

Compilare:

```bash
idf.py build
```
