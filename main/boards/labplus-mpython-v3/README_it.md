 # labplus mPython V3

## Risorse a bordo
- MCU: ESP32‑S3 con 8 MB PSRAM e 16 MB Flash
- Sensori: pulsanti A/B (IO0/IO46), sensore luce (I2C), IMU (I2C), magnetometro (I2C), trigger audio (IO6), touch
- Esecutori: buzzer (IO21), LED RGB (IO16), codec audio ES8388 (I2C), TFT LCD (jd9853 SPI)

## Compilazione

Impostare il target su ESP32S3 e aprire `menuconfig`:

```bash
idf.py set-target esp32s3
idf.py menuconfig
```

Selezionare la board:

```text
Xiaozhi Assistant -> Board Type -> labplus mpython_v3 board
```

Impostare PSRAM: `Component config` → `ESP PSRAM` → `SPI RAM config` → `Quad Mode PSRAM`

Compilare:

```bash
idf.py build
```

Per utilizzo avanzato (es. flashing con `esptool.py`) consultare il file originale con i parametri dettagliati.
