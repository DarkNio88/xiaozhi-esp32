# Siti web correlati al prodotto

```http
https://e.tb.cn/h.6Gl2LC7rsrswQZp?tk=qFuaV9hzh0k CZ356
```

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
Xiaozhi Assistant -> Board Type -> zhengchen-1.54tft-ml307
```

**Compilazione:**

```bash
idf.py build
```

**Download (flash + monitor):**

```bash
idf.py build flash monitor
```

Esegue il flashing e mostra i log della seriale.

**Generazione firmware:**

```bash
idf.py merge-bin
```
