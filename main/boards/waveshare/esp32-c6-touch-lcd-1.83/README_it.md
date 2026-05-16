# Waveshare ESP32-C6-Touch-LCD-1.83

Link prodotto: https://www.waveshare.net/shop/ESP32-C6-Touch-LCD-1.83.htm

## Compilazione

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
idf.py set-target esp32c6
idf.py menuconfig
# Selezionare: Xiaozhi Assistant -> Board Type -> Waveshare ESP32-C6-Touch-LCD-1.83
idf.py build
idf.py build flash monitor
```
