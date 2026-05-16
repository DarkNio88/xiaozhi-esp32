# DFRobot K10 (Xingkong Board)

## Configurazione pulsanti
- A: breve pressione - interrompi / risveglia; pressione lunga 1s - aumenta volume
- B: breve pressione - interrompi / risveglia; pressione lunga 1s - diminuisci volume

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
Xiaozhi Assistant -> Board Type -> DFRobot K10 (Xingkong Board)
```

**Modifica la configurazione PSRAM:**

```
Component config -> ESP PSRAM -> SPI RAM config -> Mode (QUAD/OCT) -> Octal Mode PSRAM
```

**Abilita lo swapping dell'endianness del buffer della fotocamera:**

```
Xiaozhi Assistant -> Camera Configuration -> Enable software camera buffer endianness swapping
```

**Configura la fotocamera:**

```
Component config -> Espressif Camera Sensors Configurations -> Camera Sensor Configuration -> Select and Set Camera Sensor -> GC2145 -> Auto detect GC2145

```

```
Component config -> Espressif Camera Sensors Configurations -> Camera Sensor Configuration -> Select and Set Camera Sensor -> GC2145 -> Select default output format for DVP interface (RGB565 800x600 20fps, DVP 8-bit, 20M input) -> RGB565 800x600 20fps, DVP 8-bit, 20M input

```

**Compilazione:**

```bash
idf.py build
```



