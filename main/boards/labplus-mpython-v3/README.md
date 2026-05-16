# labplus mPython V3

## Risorse a bordo
    MCU: ESP32-S3 con PSRAM esterna 8MB e Flash 16MB
    Sensori:
        Pulsanti (A, B)    IO0 IO46
        Sensore di luce    I2C
        6-assi              I2C
        Magnetometro       I2C
        Rilevamento audio  IO6
        Touch (per Python)
        Fotocamera         I2C
    Attuatori:
        Buzzer             IO21
        LED RGB            IO16
        Codec audio ES8388 I2C
        TFT LCD (jd9853)   SPI


## Configurazione di compilazione

### Imposta target su ESP32S3 (USB JTAG)

```bash
idf.py set-target esp32s3
```

### Apri `menuconfig`

```bash
idf.py menuconfig
```

***Seleziona la scheda:***

```
Xiaozhi Assistant -> Board Type -> labplus mpython_v3 board
```

***Modifica configurazione PSRAM:***

```
Component config -> ESP PSRAM -> SPI RAM config -> Mode (QUAD/OCT) -> Quad Mode PSRAM
```

**Compilazione:**

```bash
idf.py build
```

**Packaging firmware:**

```bash
esptool.py -p /dev/ttyACM0 -b 1500000 --before default_reset --after hard_reset --chip esp32s3 write_flash --flash_mode dio --flash_freq 80m --flash_size 16MB 0x0 bootloader/bootloader.bin 0x100000 xiaozhi.bin 0x8000 partition_table/partition-table.bin 0xd000 ota_data_initial.bin 0x10000 srmodels/srmodels.bin 
```

## Uso

### Configurazione pulsanti
* A: pressione breve - interrompi / risveglia
