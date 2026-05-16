# LILYGO T‑Display‑P4

Scheda di sviluppo basata su ESP32‑P4 con display MIPI ad alta risoluzione e numerose periferiche (ESP32‑C6 co‑processor, speaker, mic, LoRa, GPS, Ethernet, camera, ecc.).

## Configurazione (ESP32P4)

```bash
idf.py set-target esp32p4
idf.py menuconfig
# Selezionare: Xiaozhi Assistant -> Board Type -> LILYGO T-Display-P4
idf.py build
```

## Configurazione (ESP32C6)

Flashare l'esempio slave da `esp-hosted-mcu` per il chip ESP32C6 (la versione di `esp-hosted-mcu` deve corrispondere a quella usata nel progetto).
