# Mixgo Nova — Guida rapida

Mixgo_Nova è una scheda per IoT e didattica con sensori integrati e supporto a Mixly. Per problemi su ES8374 ADC vedere la sezione di patch indicata nel file originale.

## Compilazione

```bash
idf.py set-target esp32s3
idf.py menuconfig
idf.py build
```

Per creare il binario unificato:

```bash
idf.py merge-bin -o xiaozhi-nova.bin -f raw
```
