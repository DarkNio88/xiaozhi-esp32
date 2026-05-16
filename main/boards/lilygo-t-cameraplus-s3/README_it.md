# LILYGO T‑CameraPlus‑S3

Modulo telecamera basato su ESP32‑S3 con display 240×240, microfono digitale, speaker e supporto SD. Include una UI base sviluppata con LVGL (se non presente, caricare il programma `Lvgl_UI`).

Repository ufficiale: https://github.com/Xinyuan-LilyGO/T-CameraPlus-S3

## Compilazione

```bash
idf.py set-target esp32s3
idf.py menuconfig
idf.py build
```

Selezionare la board corretta in `Xiaozhi Assistant` → `Board Type` (ci sono opzioni per V1.0/V1.1 e V1.2).
