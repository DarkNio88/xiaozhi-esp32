# DFRobot ESP32‑S3 AI CAM

## Introduzione

Modulo telecamera AI basato su ESP32‑S3, pensato per elaborazione immagini e interazione vocale (PDM mic, fotocamera OV3660 o OV2640).

## Caratteristiche
- Microfono PDM
- Fotocamera OV3660 (o OV2640)

## Pulsante
- `BOOT`: breve pressione — interrompe / risveglia

## Compilazione e configurazione

Impostare il target su ESP32S3:

```bash
idf.py set-target esp32s3
```

Aprire `menuconfig` e selezionare la board:

```text
Xiaozhi Assistant -> Board Type -> DFRobot ESP32-S3 AI Camera Module
```

Impostazioni consigliate:

- `Component config` → `ESP PSRAM` → `SPI RAM config` → `Mode (QUAD/OCT)` → abilitare `Octal Mode PSRAM` se necessario
- `Component config` → `PHY` → impostare `Max WiFi TX power (dBm)` a `10`

Configurazione fotocamera (esempi):
- OV3660: abilitare e scegliere `YUV422 240x240 24fps` per DVP
- OV2640: abilitare e scegliere `YUV422 240x240 25fps` per DVP

Compilare:

```bash
idf.py build
```
