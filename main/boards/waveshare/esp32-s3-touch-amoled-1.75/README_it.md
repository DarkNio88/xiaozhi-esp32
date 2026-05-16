# Waveshare ESP32-S3-Touch-AMOLED-1.75

Scheda ad alte prestazioni con display AMOLED capacitivo da 1.75", IMU a sei assi, RTC e codec audio a basso consumo. Ideale per integrazione in prodotti compatti.

## Compilazione

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
idf.py set-target esp32s3
idf.py menuconfig
# Selezionare: Xiaozhi Assistant -> Board Type -> Waveshare ESP32-S3-Touch-AMOLED-1.75
idf.py build
idf.py build flash monitor
```
