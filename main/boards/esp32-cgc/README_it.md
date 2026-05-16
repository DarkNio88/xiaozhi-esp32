# ESP32‑CGC — Panoramica e compilazione

## Repository e risorse
- Vedere i repository del progetto per la documentazione hardware e i dettagli di layout.

## Compilazione

Impostare il target su ESP32:

```bash
idf.py set-target esp32
```

Aprire `menuconfig` e selezionare le opzioni:

- `Xiaozhi Assistant` → `Board Type` → `ESP32 CGC`
- `Xiaozhi Assistant` → `LCD Type` → selezionare `ST7735, risoluzione 128×128` se richiesto

Compilare:

```bash
idf.py build
```
