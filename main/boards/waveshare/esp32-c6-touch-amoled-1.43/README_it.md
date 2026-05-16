# Waveshare ESP32-C6-Touch-AMOLED-1.43

Link prodotto:
[Waveshare ESP32-C6-Touch-AMOLED-1.43](https://www.waveshare.net/shop/ESP32-C6-Touch-AMOLED-1.43.htm)

## Comandi di compilazione

Clonare il repository e impostare il target su ESP32C6:

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
idf.py set-target esp32c6
idf.py menuconfig
```

In `menuconfig` selezionare la scheda:

```
Xiaozhi Assistant -> Board Type -> Waveshare ESP32-C6-Touch-AMOLED-1.43
```

Compilare e flashare:

```bash
idf.py build
idf.py build flash monitor
```
