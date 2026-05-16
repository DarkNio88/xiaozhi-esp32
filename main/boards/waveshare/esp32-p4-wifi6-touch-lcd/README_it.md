# Waveshare ESP32-P4-WIFI6-Touch-LCD

Serie di schede composta da un ESP32‑P4 con schermo gestito da un co‑processore ESP32‑C6.

## Configurazione
Impostare il target appropriato in `menuconfig` e selezionare la variante di board:

- Waveshare ESP32-P4-WIFI6-Touch-LCD-4B
- Waveshare ESP32-P4-WIFI6-Touch-LCD-4.3
- Waveshare ESP32-P4-WIFI6-Touch-LCD-7B
- Waveshare ESP32-P4-WIFI6-Touch-LCD-3.4C
- Waveshare ESP32-P4-WIFI6-Touch-LCD-4C
- Waveshare ESP32-P4-WIFI6-Touch-LCD-7
- Waveshare ESP32-P4-WIFI6-Touch-LCD-8
- Waveshare ESP32-P4-WIFI6-Touch-LCD-10.1

Esempio rapido:

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
idf.py set-target esp32p4
idf.py menuconfig
# Selezionare la variante corretta in Xiaozhi Assistant -> Board Type
idf.py build
```
