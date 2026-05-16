# AtomMatrix + Echo Base

## Impostare il target su ESP32

```bash
idf.py set-target esp32
```

Aprire `menuconfig` e selezionare la board:

```bash
idf.py menuconfig
```

```text
Xiaozhi Assistant -> Board Type -> AtomMatrix + Echo Base
```

Compilare:

```bash
idf.py build
```
