# RYMCU BigSmart

Questa cartella contiene l'adattamento per la scheda di sviluppo `RYMCU BigSmart`, mappata sulle seguenti risorse hardware:

- MCU: ESP32-S3-WROOM-1-N16R8
- Display: ST7789 (320x240, SPI)
- Touch: GT911 (I2C)
- Audio: ES8311 + ES7210 (I2S + I2C)
- Estensione IO: PCA9557 (indirizzo I2C `0x19`)
- Fotocamera: GC0308 (DVP)

Documentazione hardware di riferimento:

- https://github.com/rymcu/BigSmart-Open/blob/main/docs/rymcu-bigsmart-hardware.md

## Compilazione

```bash
idf.py set-target esp32s3
idf.py menuconfig
```

Nel menu selezionare:

`Xiaozhi Assistant -> Board Type -> RYMCU BigSmart`

Quindi eseguire:

```bash
idf.py build
```
