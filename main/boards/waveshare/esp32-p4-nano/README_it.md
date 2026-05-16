# Waveshare ESP32-P4-NANO

Scheda compatta e altamente integrata basata su ESP32‑P4.

## Note display
Alcuni display raccomandati e dipendenze BSP sono elencati nel README originale; molti pannelli DSI richiedono il BSP ufficiale Waveshare e potrebbero non essere pienamente supportati da xiaozhi-esp32.

## Compilazione rapida

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
idf.py set-target esp32p4
idf.py menuconfig
# Selezionare la variante corretta in Xiaozhi Assistant -> Board Type
idf.py build
```
