# ESP‑SensairShuttle

## Introduzione

ESP‑SensairShuttle è una scheda di sviluppo per applicazioni di rilevamento del movimento e interazione con grandi modelli, sviluppata in collaborazione con Bosch Sensortec. Monta un modulo ESP32‑C5‑WROOM‑1‑N16R8 con Wi‑Fi 2.4/5 GHz, Bluetooth LE e supporto per Thread/Zigbee.

## Sensori e ShuttleBoard

Il supporto per sensori e ShuttleBoard è documentato nella guida del produttore.

## Compilazione

Poiché sono richieste molte opzioni `sdkconfig`, si consiglia lo script di rilascio:

```bash
python ./scripts/release.py esp-sensairshuttle
```

Per compilare manualmente, modificare `main/boards/esp-sensairshuttle/config.json` e usare `idf.py menuconfig`.

Flash:

```bash
idf.py flash
```
