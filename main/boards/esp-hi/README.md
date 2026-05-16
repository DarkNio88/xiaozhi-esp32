# ESP-Hi

## Introduzione

<div align="center">
    <a href="https://oshwhub.com/esp-college/esp-hi"><b> Piattaforma open-source </b></a>
    |
    <a href="https://www.bilibili.com/video/BV1BHJtz6E2S"><b> Bilibili </b></a>
</div>

ESP-Hi è un robot di conversazione AI open-source del progetto ESP Friends basato su ESP32C3, caratterizzato da costi estremamente contenuti. ESP-Hi integra un display a colori da 0.96" per mostrare espressioni, e il robot (tipo cane) supporta già decine di movimenti. Sfruttando appieno le periferiche dell'ESP32-C3, è possibile realizzare acquisizione audio e riproduzione sonora con hardware di scheda minimo; il software è ottimizzato per ridurre l'uso di RAM e Flash e, in condizioni di risorse limitate, permette sia il rilevamento della parola di risveglio sia il supporto di varie periferiche. Per dettagli hardware vedi il progetto su [oshwhub.com](https://oshwhub.com/esp-college/esp-hi).

## WebUI

ESP-Hi x Xiaozhi include una WebUI per controllare i movimenti del corpo: collega il telefono e l'ESP-Hi alla stessa rete Wi‑Fi e visita `http://esp-hi.local/` dal telefono per usarla.

Per disabilitare la WebUI, disattiva `ESP_HI_WEB_CONTROL_ENABLED`, ovvero deseleziona `Component config` → `Servo Dog Configuration` → `Web Control` → `Enable ESP-HI Web Control`.

## Configurazione e comandi di compilazione

Poiché ESP-Hi richiede numerose opzioni in `sdkconfig`, si consiglia di usare lo script di build.

**Compilazione**

```bash
python ./scripts/release.py esp-hi
```

Per compilare manualmente, modifica le opzioni corrispondenti in `esp-hi/config.json` e imposta menuconfig.

**Flash**

```bash
idf.py flash
```

> [!TIP]
>
> **Il controllo dei servi occupa la porta USB Type-C dell'ESP-Hi**, impedendo la connessione al computer (impossibile flashare/visualizzare i log). Se incontrassi questo problema, segui le istruzioni:
>
> **Flash**
>
> 1. Scollega l'alimentazione dell'ESP-Hi, lasciando collegata solo la testa (non collegare il corpo).
> 2. Tieni premuto il pulsante dell'ESP-Hi e collega il dispositivo al computer.
>
> A questo punto ESP-Hi (ESP32C3) dovrebbe essere in modalità di flashing e sarà possibile usare il computer per il flash. Dopo il flash potrebbe essere necessario scollegare e ricollegare l'alimentazione.
>
> **Visualizzare i log**
>
> Imposta `CONFIG_ESP_CONSOLE_USB_SERIAL_JTAG=y`, cioè in `Component config` → `ESP System Settings` → `Channel for console output` seleziona `USB Serial/JTAG Controller`. Questa impostazione disabilita anche il controllo dei servi.
