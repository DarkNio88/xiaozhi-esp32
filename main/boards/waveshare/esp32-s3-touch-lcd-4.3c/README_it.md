# Waveshare ESP32‑S3‑Touch‑LCD‑4.3C

Documentazione e firmware di esempio disponibili sul sito Waveshare.

Quick start:

```bash
esptool.py --chip esp32s3 -p /dev/ttyACM0 -b 460800 --before=default_reset --after=hard_reset write_flash --flash_mode dio --flash_freq 80m --flash_size 16MB 0x00 ESP32-S3-Touch-LCD-4.3C-Xiaozhi.bin
```

Per build locale:

```bash
idf.py set-target esp32s3
cp main/boards/esp32-s3-touch-lcd-4.3c/sdkconfig.4_3c sdkconfig
idf.py build flash monitor
```
