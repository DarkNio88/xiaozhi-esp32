# Compilazione e configurazione — Bread Compact ESP32

## Impostare il target su ESP32

```bash
idf.py set-target esp32
```

Aprire il menu di configurazione:

```bash
idf.py menuconfig
```

Selezionare la board nel menu:

```text
Xiaozhi Assistant -> Board Type -> Breadboard ESP32 DevKit
```

Compilare:

```bash
idf.py build
```
