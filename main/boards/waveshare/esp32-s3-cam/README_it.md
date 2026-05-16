# Waveshare ESP32-S3-CAM (OV5640 / OV3660 / GC2145 / GC0308)

Schede camera basate su ESP32‑S3. Link prodotti:

- https://www.waveshare.net/shop/ESP32-S3-CAM-OV5640.htm
- https://www.waveshare.net/shop/ESP32-S3-CAM-OV3660.htm
- https://www.waveshare.net/shop/ESP32-S3-CAM-GC2145.htm
- https://www.waveshare.net/shop/ESP32-S3-CAM-GC0308.htm

## Compilazione

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
idf.py set-target esp32s3
idf.py menuconfig
# Selezionare la board corrispondente in Xiaozhi Assistant -> Board Type
idf.py build
idf.py build flash monitor
```
