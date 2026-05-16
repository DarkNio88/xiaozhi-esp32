# Comandi di compilazione

## Compilazione con un comando

```bash
python scripts/release.py aipi-lite
```

## Configurazione e compilazione manuale

```bash
idf.py set-target esp32s3
```

**Configurazione**

```bash
idf.py menuconfig
```

Seleziona la scheda

```
Xiaozhi Assistant -> Board Type -> AIPI-Lite
```

## Compilazione e scrittura (flash)

```bash
idf.py -DBOARD_NAME=aipi-lite build flash
```

Attenzione: se il dispositivo è stato originariamente consegnato con il firmware AiPi-Lite (non la versione Xiaozhi), fare attenzione alle impostazioni delle partizioni di flash per evitare la cancellazione accidentale delle informazioni di fabbrica di AiPi-Lite (come EUI, ecc.). In caso contrario, anche ripristinando il firmware Xorigin il dispositivo potrebbe non riuscire a connettersi correttamente al server. Prima di eseguire il flash del firmware, annotate tutte le informazioni di dispositivo necessarie per poterle eventualmente ripristinare.

Potete usare il seguente comando per eseguire il backup delle informazioni di fabbrica:

```bash
# firstly backup the factory information partition which contains the credentials for connecting the SenseCraft server
esptool.py --chip esp32s3 --baud 2000000 --before default_reset --after hard_reset --no-stub read_flash 0x9000 16384 nvsfactory.bin

```