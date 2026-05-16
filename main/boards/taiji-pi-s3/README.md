# Avviso: cambio microfono e vetro (lotti >2528)

A causa della cessazione della produzione del precedente modello di microfono, dal luglio 2025 la Taiji Pai (JC3636W518) monta un nuovo microfono e un nuovo vetro dello schermo. Se il numero di lotto sul prodotto è maggiore di 2528, selezionare `I2S Type PDM`.

# Aggiunta configurazione stereo

# Comandi per configurare e compilare

**Imposta il target di compilazione su ESP32S3：**

```bash
idf.py set-target esp32s3
```

**Apri menuconfig：**

```bash
idf.py menuconfig
```

**Seleziona la scheda：**

```
Xiaozhi Assistant -> Board Type -> Taiji Pi S3

Xiaozhi Assistant -> TAIJIPAI_S3_CONFIG -> taiji-pi-S3 I2S Type -> I2S Type PDM
```

**Se è necessario scegliere stereo：**
```

Xiaozhi Assistant -> TAIJIPAI_S3_CONFIG -> Enabel use 2 slot
```


**Modifica la configurazione PSRAM：**

```
component config -> ESP PSRAM -> SPI RAM config -> Try to allocate memories of WiFi and LWIP in SPIRAM firstly. If failed, allocate internal memory

```

**Compilazione：**

```bash
idf.py build
```
