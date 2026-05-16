# RYMCU BigSmart — Panoramica e compilazione

Hardware principali:

- MCU: ESP32‑S3‑WROOM‑1‑N16R8
- Display: ST7789 (320×240, SPI)
- Touch: GT911 (I2C)
- Audio: ES8311 + ES7210 (I2S + I2C)
- IO expander: PCA9557 (I2C addr `0x19`)
- Camera: GC0308 (DVP)

Repository hardware: https://github.com/rymcu/BigSmart-Open/blob/main/docs/rymcu-bigsmart-hardware.md

## Compilazione

```bash
idf.py set-target esp32s3
idf.py menuconfig
# Selezionare: Xiaozhi Assistant -> Board Type -> RYMCU BigSmart
idf.py build
```
