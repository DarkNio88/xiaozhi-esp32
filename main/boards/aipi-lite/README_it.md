# Aipi-Lite — Comandi di compilazione

Comandi rapidi per compilare e flashare la board `AIPI-Lite`.

## Compilazione one‑click

```bash
python scripts/release.py aipi-lite
```

## Compilazione manuale

Impostare il target su ESP32S3:

```bash
idf.py set-target esp32s3
```

Aprire il menu di configurazione:

```bash
idf.py menuconfig
```

Selezionare la board:

```text
Xiaozhi Assistant -> Board Type -> AIPI-Lite
```

## Compilazione e flash

```bash
idf.py -DBOARD_NAME=aipi-lite build flash
```

## Attenzione
Se il dispositivo è stato fornito con il firmware AiPi‑Lite (non versione Xiaozhi), prestate massima attenzione alla tabella delle partizioni quando eseguite il flash per evitare di sovrascrivere informazioni di fabbrica (ad es. EUI). Se queste informazioni vengono cancellate il dispositivo potrebbe non riconnettersi al server anche dopo un ripristino del firmware. Prima di procedere, eseguite il backup delle informazioni di produzione.

Esempio di backup della partizione factory (contenente le credenziali per il server SenseCraft):

```bash
esptool.py --chip esp32s3 --baud 2000000 --before default_reset --after hard_reset --no-stub read_flash 0x9000 16384 nvsfactory.bin
```
