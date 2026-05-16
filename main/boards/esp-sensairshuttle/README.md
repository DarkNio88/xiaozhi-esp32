# ESP-SensairShuttle

## Introduzione

<div align="center">
    <a href="https://docs.espressif.com/projects/esp-dev-kits/zh_CN/latest/esp32c5/esp-sensairshuttle/index.html">
        <b> Documentazione scheda di sviluppo </b>
    </a>
    |
    <a href="#sensori--supporto-shuttleboard">
        <b> Documentazione sensori & <i>ShuttleBoard</i> </b>
    </a>
</div>

ESP-SensairShuttle è una scheda di sviluppo realizzata da Espressif in collaborazione con Bosch Sensortec, rivolta a scenari di rilevamento del movimento e di interazione uomo-macchina basata su grandi modelli.

La scheda è basata sul modulo ESP32-C5-WROOM-1-N16R8 e offre connettività Wi‑Fi 6 dual‑band (2.4 & 5 GHz, 802.11ax), Bluetooth® 5 (LE), Zigbee e Thread (802.15.4).

## Supporto sensori & schede figlie _ShuttleBoard_

Presto disponibile.

## Comandi di configurazione e compilazione

Poiché ESP-SensairShuttle richiede la configurazione di numerose opzioni `sdkconfig`, si consiglia di usare lo script di compilazione.

**Compilazione**

```bash
python ./scripts/release.py esp-sensairshuttle
```

Per compilare manualmente, consultare `main/boards/esp-sensairshuttle/config.json` per modificare le opzioni corrispondenti in `menuconfig`.

**Flash**

```bash
idf.py flash
```
