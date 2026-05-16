# Modulo fotocamera AI DFRobot ESP32-S3

## Introduzione
ESP32-S3 AI CAM è un modulo fotocamera intelligente basato sul chip ESP32-S3, progettato per l'elaborazione di immagini/video e l'interazione vocale. È adatto per applicazioni di videosorveglianza, riconoscimento immagini ai margini (edge) e dialoghi vocali AI.
![](https://ws.dfrobot.com.cn/FsTrGbrX2NZAwzWS8OSQGOGikuYA)

[Dettagli sul prodotto](https://wiki.dfrobot.com.cn/SKU_DFR1154_ESP32_S3_AI_CAM)

[Dimostrazione delle funzionalità visive](https://www.bilibili.com/video/BV1ktjSzNEUU/)

## Caratteristiche
* Microfono PDM
* Fotocamera integrata OV3660

## Configurazione pulsanti
* BOOT: pressione breve - interrompi / risveglia

## Comandi di configurazione e compilazione

**Imposta il target di compilazione su ESP32S3:**

```bash
idf.py set-target esp32s3
```

**Apri menuconfig:**

```bash
idf.py menuconfig
```

**Seleziona la scheda:**

```
Xiaozhi Assistant -> Board Type -> Modulo fotocamera AI DFRobot ESP32-S3
```

**Modifica la configurazione PSRAM:**

```
Component config -> ESP PSRAM -> SPI RAM config -> Mode (QUAD/OCT) -> Octal Mode PSRAM
```

**Imposta la potenza TX WiFi su 10 dBm:**

```
Component config -> PHY -> (10)Max WiFi TX power (dBm)
```

**Configurazione della fotocamera:**

* **OV3660**
```
Component config -> Espressif Camera Sensors Configurations -> Camera Sensor Configuration -> Select and Set Camera Sensor -> OV3660 ->  Auto detect OV3660

```

```
Component config -> Espressif Camera Sensors Configurations -> Camera Sensor Configuration -> Select and Set Camera Sensor -> OV3660 ->  Select default output format for DVP interface (YUV422 240x240 24fps, DVP 8-bit, 20M input)
```

* **OV2640**
```
Component config -> Espressif Camera Sensors Configurations -> Camera Sensor Configuration -> Select and Set Camera Sensor -> OV2640 ->  Auto detect OV2640

```

```
Component config -> Espressif Camera Sensors Configurations -> Camera Sensor Configuration -> Select and Set Camera Sensor -> OV2640 ->  Select default output format for DVP interface (YUV422 240x240 25fps, DVP 8-bit, 20M input)
```

**Compilazione:**

```bash
idf.py build
```