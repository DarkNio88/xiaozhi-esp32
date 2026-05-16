# Link prodotto

[Waveshare ESP32-S3-LCD-0.85](https://www.waveshare.net/shop/ESP32-S3-LCD-0.85.htm)

# Comandi di configurazione e compilazione

**Clona il repository**

```bash
git clone https://github.com/78/xiaozhi-esp32.git
```

**Entra nella cartella del progetto**

```bash
cd xiaozhi-esp32
```

**Imposta il target di compilazione su ESP32C6**

```bash
idf.py set-target esp32c6
```

**Apri menuconfig**

```bash
idf.py menuconfig
```

**Seleziona la scheda**

```bash
Xiaozhi Assistant -> Board Type -> Waveshare ESP32-S3-LCD-0.85
```

**Imposta la dimensione del flash:**

```
Serial flasher config -> Flash size -> 8 MB
```

**Imposta la tabella partizioni:**

```
Partition Table -> Custom partition CSV file -> partitions/v2/8m.csv
```

**Compilazione**

```bash
idf.py build
```

**Scarica e apri il monitor seriale**

```bash
idf.py build flash monitor
```

