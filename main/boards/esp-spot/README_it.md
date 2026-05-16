# ESP‑Spot

## Introduzione

ESP‑Spot è una scatola di interazione vocale con microfono, speaker e IMU, progettata per funzionare anche a batteria. Non ha display: usa un LED RGB e due pulsanti.

## Compilazione e configurazione

Per ESP32‑S3:

```bash
idf.py set-target esp32s3
```

Per ESP32‑C5:

```bash
idf.py set-target esp32c5
```

Aprire `menuconfig` e selezionare la board:

```text
Xiaozhi Assistant -> Board Type -> ESP-Spot-S3 / ESP-Spot-C5
```

Compilare:

```bash
idf.py build
```

Flash:

```bash
idf.py flash
```

Suggerimento: se il PC non trova la porta seriale, aprire il coperchio, estrarre il PCB e inserirlo tenendo premuto `BOOT` per entrare in modalità di download.

## Basso consumo

ESP‑Spot supporta Deep Sleep e può entrare in sospensione automatica dopo 10 minuti di inattività.