# Taiji Pi S3 — Note e compilazione

A partire da luglio 2025 (batch > 2528) il microfono e il vetro dello schermo sono stati modificati; per questi batch selezionare `I2S Type PDM` in configurazione.

## Configurazione

```bash
idf.py set-target esp32s3
idf.py menuconfig
```

Selezionare in `menuconfig`:

```
Xiaozhi Assistant -> Board Type -> 太极小派esp32s3
Xiaozhi Assistant -> TAIJIPAI_S3_CONFIG -> taiji-pi-S3 I2S Type -> I2S Type PDM
```

Per abilitare l'uso a due canali:

```
Xiaozhi Assistant -> TAIJIPAI_S3_CONFIG -> Enable use 2 slot
```

Modifica PSRAM:

```
component config -> ESP PSRAM -> SPI RAM config -> Try to allocate memories of WiFi and LWIP in SPIRAM firstly. If failed, allocate internal memory
```

Compilare con:

```bash
idf.py build
```
