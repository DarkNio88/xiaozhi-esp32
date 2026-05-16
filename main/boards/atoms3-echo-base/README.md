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
Xiaozhi Assistant -> Board Type -> AtomS3 + Echo Base
```

**Disabilita il risveglio vocale:**

```
Xiaozhi Assistant -> [ ] Abilita risveglio vocale e elaborazione audio -> Deseleziona
```

**Imposta la dimensione del flash:**

```
Serial flasher config -> Flash size -> 8 MB
```

**Imposta la tabella partizioni:**

```
Partition Table -> Custom partition CSV file -> partitions/v2/8m.csv
```

**Disabilita PSRAM esterno:**

```
Component config -> ESP PSRAM -> [ ] Support for external, SPI-connected RAM -> Deseleziona
```

**Compilazione:**

```bash
idf.py build
```