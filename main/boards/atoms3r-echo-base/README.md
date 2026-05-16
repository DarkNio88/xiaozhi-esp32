# Comandi di configurazione e compilazione

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
Xiaozhi Assistant -> Board Type -> AtomS3R + Echo Base
```

**Imposta la dimensione del flash:**

```
Serial flasher config -> Flash size -> 8 MB
```

**Imposta la tabella partizioni:**

```
Partition Table -> Custom partition CSV file -> partitions/v2/8m.csv
```

**Modifica la configurazione PSRAM:**

```
Component config -> ESP PSRAM -> SPI RAM config -> Mode (QUAD/OCT) -> Octal Mode PSRAM
```

**Compilazione:**

```bash
idf.py build
```