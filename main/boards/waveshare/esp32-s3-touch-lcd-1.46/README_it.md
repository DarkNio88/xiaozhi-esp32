# Waveshare ESP32-S3-Touch-LCD-1.46 / 1.46B

Link prodotto:
https://www.waveshare.net/shop/ESP32-S3-Touch-LCD-1.46.htm
https://www.waveshare.net/shop/ESP32-S3-Touch-LCD-1.46B.htm

## Compilazione

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
idf.py set-target esp32s3
idf.py menuconfig
# Selezionare: Xiaozhi Assistant -> Board Type -> Waveshare ESP32-S3-Touch-LCD-1.46
idf.py build
idf.py build flash monitor
```
