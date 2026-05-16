# Waveshare ESP32-S3-Touch-LCD-1.83

Scheda compatta con LCD capacitivo 1.83", IMU, RTC e codec audio integrati.

## Compilazione

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
idf.py set-target esp32s3
idf.py menuconfig
# Selezionare: Xiaozhi Assistant -> Board Type -> Waveshare ESP32-S3-Touch-LCD-1.83
idf.py build
idf.py build flash monitor
```
