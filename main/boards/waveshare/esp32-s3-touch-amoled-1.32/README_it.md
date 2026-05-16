# Waveshare ESP32-S3-Touch-AMOLED-1.32

Link prodotto:
[Waveshare ESP32-S3-Touch-AMOLED-1.32](https://www.waveshare.net/shop/ESP32-S3-Touch-AMOLED-1.32.htm)

## Compilazione

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
idf.py set-target esp32s3
idf.py menuconfig
# Selezionare: Xiaozhi Assistant -> Board Type -> Waveshare ESP32-S3-Touch-AMOLED-1.32
idf.py build
idf.py build flash monitor
```
