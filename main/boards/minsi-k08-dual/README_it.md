# Minsi K08 (DUAL)

Scheda basata su ESP32‑S3 con amplificatore MAX98357 e microfono INMP441, progettata come speaker AI con batteria e design "punk". Link prodotto nel file originale.

## Compilazione

```bash
idf.py set-target esp32s3
idf.py menuconfig
idf.py build flash
```

Selezionare: `Xiaozhi Assistant` → `Board Type` → `敏思科技K08(DUAL)`
