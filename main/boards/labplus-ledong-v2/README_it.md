# labplus Ledong V2

## Risorse a bordo
- MCU: ESP32‑S3 con 8 MB PSRAM e 16 MB Flash
- Sensori: pulsanti A/B, sensore luce, IMU, magnetometro, trigger audio, touch
- Esecutori: buzzer, RGB, codec ES8388, TFT LCD, motore (I2C)

## Compilazione

```bash
idf.py set-target esp32s3
idf.py menuconfig
idf.py build
```

Selezionare la board in `Xiaozhi Assistant` → `Board Type` → `labplus Ledong_v2 board`.
