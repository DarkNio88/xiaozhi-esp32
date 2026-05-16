# Waveshare ESP32-S3-LCD-0.85

Link prodotto:
[Waveshare ESP32-S3-LCD-0.85](https://www.waveshare.net/shop/ESP32-S3-LCD-0.85.htm)

## Compilazione

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
idf.py set-target esp32s3
idf.py menuconfig
# Selezionare: Xiaozhi Assistant -> Board Type -> Waveshare ESP32-S3-LCD-0.85
```

Impostare flash size su `8 MB` e scegliere la partition table `partitions/v2/8m.csv` se richiesto.

```bash
idf.py build
idf.py build flash monitor
```
