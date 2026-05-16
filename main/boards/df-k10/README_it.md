# DFRobot K10

## Pulsanti
- `A`: breve pressione — interrompe / risveglia; pressione lunga (1s) — aumenta volume
- `B`: breve pressione — interrompe / risveglia; pressione lunga (1s) — diminuisce volume

## Compilazione e configurazione

Impostare il target su ESP32S3:

```bash
idf.py set-target esp32s3
```

Aprire `menuconfig` e selezionare la board:

```text
Xiaozhi Assistant -> Board Type -> DFRobot K10
```

Impostazioni utili:

- `Component config` → `ESP PSRAM` → `Octal Mode PSRAM`
- `Xiaozhi Assistant` → `Camera Configuration` → abilitare lo swapping dell'endianness del buffer della camera se richiesto
- Configurare il sensore GC2145 se presente (auto detect e selezionare formato output, es. `RGB565 800x600 20fps`)

Compilare:

```bash
idf.py build
```
