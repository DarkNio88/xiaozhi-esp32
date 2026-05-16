# Comandi di configurazione e compilazione

**Imposta il target di compilazione su ESP32S3:**

```bash
idf.py set-target esp32s3
```

**Apri `menuconfig`:**

```bash
idf.py menuconfig
```

**Seleziona la scheda:**

```
Xiaozhi Assistant -> Board Type -> Movecall Moji (derivato da Xiaozhi AI)
```

**Compila:**

```bash
idf.py build
```