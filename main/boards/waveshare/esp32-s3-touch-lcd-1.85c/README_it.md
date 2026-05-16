# Waveshare ESP32-S3-Touch-LCD-1.85C

Link prodotto:
https://www.waveshare.net/shop/ESP32-S3-Touch-LCD-1.85C.htm

## Compilazione

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
idf.py set-target esp32s3
idf.py menuconfig
# Selezionare: Xiaozhi Assistant -> Board Type -> Waveshare ESP32-S3-Touch-LCD-1.85C
idf.py build
idf.py build flash monitor
```
