# SenseCAP Watcher — Istruzioni di compilazione

## Compilazione rapida

```bash
python scripts/release.py sensecap-watcher
```

## Configurazione manuale

```bash
idf.py set-target esp32s3
idf.py menuconfig
# Selezionare: Xiaozhi Assistant -> Board Type -> SenseCAP Watcher
idf.py -DBOARD_NAME=sensecap-watcher build flash
```

### Avvertenza importante
Se il dispositivo ha firmware SenseCAP di produzione, fare attenzione a non cancellare le partizioni contenenti informazioni di fabbrica (EUI, credenziali). Eseguire il backup prima di procedere.

Esempio di backup della partizione factory:

```bash
esptool.py --chip esp32s3 --baud 2000000 --before default_reset --after hard_reset --no-stub read_flash 0x9000 204800 nvsfactory.bin
```
