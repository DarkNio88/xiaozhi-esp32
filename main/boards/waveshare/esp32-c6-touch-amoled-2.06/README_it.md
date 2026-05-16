# Waveshare ESP32-C6-Touch-AMOLED-2.06

Scheda a forma di orologio basata su ESP32‑C6 con display AMOLED capacitivo da 2.06", sensore a sei assi, RTC, codec audio e gestione energetica: ideale per prototipi wearable.

## Comandi di compilazione

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
idf.py set-target esp32c6
idf.py menuconfig
# Selezionare: Xiaozhi Assistant -> Board Type -> Waveshare ESP32-C6-Touch-AMOLED-2.06
idf.py build
idf.py build flash monitor
```
