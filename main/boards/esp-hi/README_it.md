# ESP-Hi

## Introduzione

ESP-Hi è un robot AI dialogico a bassissimo costo basato su ESP32‑C3. Integra un display a colori da 0,96" per mostrare espressioni e supporta numerose animazioni e movimenti del corpo. Il progetto è ottimizzato per minimizzare l'uso di RAM e Flash pur mantenendo il supporto per wake‑word e diversi driver periferici. Maggiori dettagli hardware sono disponibili sul repository del progetto.

## WebUI

ESP-Hi include una WebUI per controllare i movimenti: collega il telefono e la board alla stessa rete Wi‑Fi e visita `http://esp-hi.local/`.

Per disabilitare la WebUI, disabilitare `ESP_HI_WEB_CONTROL_ENABLED` in `Component config` → `Servo Dog Configuration` → `Web Control` → `Enable ESP-HI Web Control`.

## Configurazione e compilazione

Poiché sono richieste molte opzioni `sdkconfig`, si consiglia di usare lo script di build:

```bash
python ./scripts/release.py esp-hi
```

Per compilare manualmente, fare riferimento a `esp-hi/config.json` e adattare le opzioni via `idf.py menuconfig`.

## Flash

```bash
idf.py flash
```

## Suggerimenti utili

- Il controllo dei servi può occupare la porta USB Type‑C e impedire la connessione al PC (quindi il flash o la visualizzazione dei log). In tal caso:
  1. Scollegare l'alimentazione alla parte "corpo", lasciare collegata solo la testa.
  2. Tenere premuto il pulsante della board e collegare il cavo USB al PC per entrare in modalità di flashing.

- Per visualizzare i log via USB, impostare `CONFIG_ESP_CONSOLE_USB_SERIAL_JTAG=y` in `Component config` → `ESP System Settings` → `Channel for console output` → selezionare `USB Serial/JTAG Controller`. Questo disabiliterà temporaneamente il controllo dei servi.
