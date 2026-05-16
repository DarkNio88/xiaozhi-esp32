# Comandi di compilazione

## Compilazione one‑click

```bash
python scripts/release.py sensecap-watcher
```

## Compilazione manuale

```bash
idf.py set-target esp32s3
```

**Configurazione**

```bash
idf.py menuconfig
```

Seleziona la scheda:

```
Xiaozhi Assistant -> Board Type -> SenseCAP Watcher
```

Alcune opzioni aggiuntive per il watcher devono essere abilitate in `menuconfig`:

```
CONFIG_BOARD_TYPE_SEEED_STUDIO_SENSECAP_WATCHER=y
CONFIG_ESPTOOLPY_FLASHSIZE_32MB=y
CONFIG_PARTITION_TABLE_CUSTOM_FILENAME="partitions/v2/32m.csv"
CONFIG_BOOTLOADER_CACHE_32BIT_ADDR_QUAD_FLASH=y
CONFIG_ESPTOOLPY_FLASH_MODE_AUTO_DETECT=n
CONFIG_IDF_EXPERIMENTAL_FEATURES=y
```

## Compilazione e flashing

```bash
idf.py -DBOARD_NAME=sensecap-watcher build flash
```

Attenzione: se il dispositivo proveniva da una versione SenseCAP (non la build "Xiaozhi"), fai estrema attenzione agli indirizzi di partizione dello flash per non cancellare accidentalmente le informazioni di produzione del SenseCAP Watcher (EUI, ecc.). In caso di cancellazione, anche ripristinando il firmware SenseCAP il dispositivo potrebbe non connettersi correttamente al server SenseCraft. Prima di scrivere il firmware, registra tutte le informazioni di produzione necessarie per poter ripristinare il dispositivo.

Puoi eseguire il backup delle informazioni di fabbrica con il comando seguente:

```bash
# Esegui il backup della partizione factory che contiene le credenziali per la connessione al server SenseCraft
esptool.py --chip esp32s3 --baud 2000000 --before default_reset --after hard_reset --no-stub read_flash 0x9000 204800 nvsfactory.bin

```