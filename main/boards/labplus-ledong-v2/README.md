# labplus Ledong V2

## Risorse a bordo

- MCU: ESP32-S3 con 8MB PSRAM esterna e 16MB Flash

Sensori:
- Pulsanti (A, B): IO0, IO46
- Sensore di luce: I2C
- Giroscopio/accelerometro 6-assi: I2C
- Magnetometro: I2C
- Trigger audio: IO6
- Tasti touch: I2C
- Fotocamera: I2C

Attuatori:
- Buzzer: IO21
- LED RGB: IO16
- Codec di registrazione/playback (es8388): I2C
- TFT LCD (jd9853): SPI
- Driver motore: I2C

## Configurazione compilazione

### Imposta il target di compilazione su ESP32S3 (download via USB JTAG)

```bash
idf.py set-target esp32s3
```

### Apri `menuconfig` e configura

```bash
idf.py menuconfig
```

Selezionare la scheda:

```
Xiaozhi Assistant -> Board Type -> labplus Ledong_v2 board
```

Modificare la configurazione PSRAM:

```
Component config -> ESP PSRAM -> SPI RAM config -> Mode (QUAD/OCT) -> quad Mode PSRAM
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
- A: pressione breve — interrompi / risveglia
