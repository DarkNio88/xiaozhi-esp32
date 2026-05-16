## Link prodotto

[Waveshare ESP32-S3-ePaper-1.54](https://www.waveshare.net/shop/ESP32-S3-ePaper-1.54.htm)

```bash
esptool.py flash_id
V1: 4MB Flash, 2MB PSRAM
V2: 8MB Flash, 8MB PSRAM
```

# Comandi di configurazione e compilazione

**Clona il repository**

```bash
git clone https://github.com/78/xiaozhi-esp32.git
```

**Entra nella cartella del progetto**

```bash
cd xiaozhi-esp32
```

**Imposta il target di compilazione su ESP32S3**

```bash
idf.py set-target esp32s3
```

**Apri menuconfig**

```bash
idf.py menuconfig
```

**Seleziona la scheda**

```bash
Xiaozhi Assistant -> Board Type -> Waveshare ESP32-S3-ePaper-1.54
```

**Compilazione**

```bash
idf.py build
```

**Scarica e apri il monitor seriale**

```bash
idf.py build flash monitor
```

