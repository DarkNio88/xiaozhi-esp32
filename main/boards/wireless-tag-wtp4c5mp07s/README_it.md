# Wireless‑Tag WTP4C5MP07S

Scheda combo con display MIPI DSI 7" (1024×600) e scheda di sviluppo WT99P4C5‑S1 (ESP32‑P4).

## Configurazione (ESP32P4)

```bash
idf.py set-target esp32p4
idf.py menuconfig
```

Selezionare in `menuconfig`: `Xiaozhi Assistant` → `Board Type` → `Wireless‑Tag WTP4C5MP07S`.

Impostazioni utili (PSRAM, Wi‑Fi slave target, buffer Wi‑Fi) sono descritte nel file originale.

Per la modalità ESP32C5: flashare l'esempio slave da `esp-hosted-mcu` corrispondente.
