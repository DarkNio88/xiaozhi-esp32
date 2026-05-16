# Waveshare ESP32-S3-Touch-AMOLED-2.06

Scheda wearable tipo orologio con display AMOLED 2.06", IMU a sei assi, RTC e codec audio; adatta per prototipi wearable.

## Compilazione

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
idf.py set-target esp32s3
idf.py menuconfig
# Selezionare: Xiaozhi Assistant -> Board Type -> Waveshare ESP32-S3-Touch-AMOLED-2.06
idf.py build
idf.py build flash monitor
```
