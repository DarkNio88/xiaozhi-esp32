# Link prodotto

[Waveshare ESP32-C6-Touch-AMOLED-2.16](https://www.waveshare.net/shop/ESP32-C6-Touch-AMOLED-2.16.htm)

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
Xiaozhi Assistant -> Board Type -> Waveshare ESP32-C6-Touch-AMOLED-2.16
```

**Compilazione**

```bash
idf.py build
```

**Scarica e apri il monitor seriale**

```bash
idf.py build flash monitor
```

