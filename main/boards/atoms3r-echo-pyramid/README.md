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
Xiaozhi Assistant -> Board Type -> M5Stack AtomS3R + Echo Pyramid
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

## Istruzioni d'uso

Quando Echo Pyramid è in funzione, alimentalo tramite la porta USB-C della base Pyramid; la porta USB-C di AtomS3R è principalmente usata per il flashing.

# Riferimenti

https://github.com/m5stack/M5Echo-Pyramid