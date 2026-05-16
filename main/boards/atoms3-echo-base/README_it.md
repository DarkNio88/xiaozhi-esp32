# AtomS3 Echo Base

Istruzioni rapide per AtomS3 Echo Base.

## Panoramica

Echo Base è una scheda base per i dispositivi Atom S3 con supporto per audio, microfono MEMS e interfacce per moduli camera. È pensata per applicazioni di riconoscimento vocale e audio.

## Compilazione

Impostare il target su ESP32S3:

```bash
idf.py set-target esp32s3
```

Aprire `menuconfig` e scegliere la board:

```bash
idf.py menuconfig
```

Selezionare: `Xiaozhi Assistant` → `Board Type` → `AtomS3 + Echo Base`

Compilare e flashare:

```bash
idf.py build
idf.py flash
```
