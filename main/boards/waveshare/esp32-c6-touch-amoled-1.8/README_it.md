# Waveshare ESP32-C6-Touch-AMOLED-1.8

Scheda di sviluppo compatta dotata di display AMOLED capacitivo da 1.8", IMU a 6 assi, RTC, codec audio a basso consumo e gestione energetica integrata. Buona per prototipi che richiedono display e sensori.

## Uso rapido

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
idf.py set-target esp32c6
idf.py menuconfig
# Selezionare: Xiaozhi Assistant -> Board Type -> Waveshare ESP32-C6-Touch-AMOLED-1.8
idf.py build
idf.py build flash monitor
```
