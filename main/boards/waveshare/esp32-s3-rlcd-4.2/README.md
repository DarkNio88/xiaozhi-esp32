# Link prodotto

[Waveshare ESP32-S3-RLCD-4.2](https://www.waveshare.net/shop/ESP32-S3-RLCD-4.2.htm)

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
Xiaozhi Assistant -> Board Type -> Waveshare ESP32-S3-RLCD-4.2
```

**Compilazione**

```bash
idf.py build
```

**Scarica e apri il monitor seriale**

```bash
idf.py build flash monitor
```

