# ESP32‑CGC‑144 — Riferimenti e compilazione

## Riferimenti
- Versione con cavo: vedi documentazione nel repository del progetto
- Versione con batteria: vedi documentazione nel repository del progetto

## Compilazione

Impostare il target su ESP32:

```bash
idf.py set-target esp32
```

Aprire `menuconfig` e selezionare la board:

```text
Xiaozhi Assistant -> Board Type -> ESP32 CGC 144
```

Compilare:

```bash
idf.py build
```
