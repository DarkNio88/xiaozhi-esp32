# ESP‑P4‑Function‑EV‑Board

Supporto scheda per ESP‑P4‑Function‑EV‑Board. Wi‑Fi è gestito via ESP‑Hosted con coprocessore ESP32‑C6; il display usa un adattatore MIPI‑DSI.

Caratteristiche principali:
- Wi‑Fi: `esp_wifi_remote` + `esp_hosted` (SDIO) con ESP32‑C6
- Display: 7" MIPI‑DSI (1024×600) tramite adattatore
- Audio: codec ES8311 (speaker + microfono)
- Touch: controller GT911
- MicroSD, Camera (MIPI‑CSI / DVP), USB host/device, SPIFFS, font Unicode

Configurazione:

In `menuconfig`: `Xiaozhi Assistant` → `Board Type` → `ESP‑P4‑Function‑EV‑Board`

Impostazioni richieste (normalmente impostate da `config.json`):

- `CONFIG_SLAVE_IDF_TARGET_ESP32C6=y`
- `CONFIG_ESP_HOSTED_P4_DEV_BOARD_FUNC_BOARD=y`
- `CONFIG_ESP_HOSTED_SDIO_HOST_INTERFACE=y`
- `CONFIG_ESP_HOSTED_SDIO_4_BIT_BUS=y`

Collegamenti LCD (vedere guida Espressif):

- Connettere l'adattatore J3 alla porta MIPI DSI della scheda
- `RST_LCD` → `GPIO27`, `PWM` → `GPIO26`

Esempio build:

```powershell
idf.py set-target esp32p4
idf.py menuconfig
idf.py build
```
