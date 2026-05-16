# Zhengchen 1.54" TFT (WiFi)

## Introduzione

Link al prodotto e alla documentazione del venditore sono inclusi nel file originale.

## Compilazione

Impostare il target su ESP32S3:

```bash
idf.py set-target esp32s3
```

Aprire `menuconfig` e selezionare la board:

```text
Xiaozhi Assistant -> Board Type -> zhengchen-1.54tft-wifi
```

Compilare:

```bash
idf.py build
```

Per flash e monitoraggio dei log:

```bash
idf.py build flash monitor
```

Per generare il firmware binario unificato:

```bash
idf.py merge-bin
```
