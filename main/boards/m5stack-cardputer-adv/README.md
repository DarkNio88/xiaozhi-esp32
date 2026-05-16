# M5Stack Cardputer Adv

M5Stack Cardputer Adv è un computer in formato card basato su ESP32-S3FN8 (Stamp-S3A).

## Specifiche hardware

| Componente | Specifiche |
|------|------|
| MCU | ESP32-S3FN8 @ 240MHz |
| Flash | 8MB |
| Display | ST7789V2 1.14" 240x135 |
| Codec audio | ES8311 |
| Amplificatore | NS4150B |
| Microfono | MEMS |
| Tastiera | 56 tasti (TCA8418) |
| IMU | BMI270 |
| Batteria | 1750mAh |

## Definizione pin

### Display (ST7789V2)
| Funzione | GPIO |
|------|------|
| MOSI | GPIO35 |
| SCLK | GPIO36 |
| CS | GPIO37 |
| DC | GPIO34 |
| RST | GPIO33 |
| BL | GPIO38 |

### Audio (ES8311)
| Funzione | GPIO |
|------|------|
| I2C SDA | GPIO8 |
| I2C SCL | GPIO9 |
| I2S BCLK | GPIO41 |
| I2S LRCK | GPIO43 |
| I2S DOUT | GPIO46 |
| I2S DIN | GPIO42 |

## Utilizzo

1. Premere il pulsante BOOT per entrare in modalità di configurazione di rete
2. Dopo la connessione alla rete WiFi, è possibile utilizzare le funzionalità dell'assistente vocale

## Parametri di flashing

Chip: ESP32-S3, Flash: 8MB, Modalità: DIO, Frequenza: 80MHz

| Indirizzo | File |
|------|------|
| 0x0 | bootloader/bootloader.bin |
| 0x8000 | partition_table/partition-table.bin |
| 0xd000 | ota_data_initial.bin |
| 0x20000 | xiaozhi.bin |
| 0x600000 | generated_assets.bin |

Comando di flashing (la directory di build è `build-cardputer-adv`):

```bash
python -m esptool --chip esp32s3 -b 460800 -p PORT \
  --before default_reset --after hard_reset \
  write_flash --flash_mode dio --flash_size 8MB --flash_freq 80m \
  0x0 build-cardputer-adv/bootloader/bootloader.bin \
  0x8000 build-cardputer-adv/partition_table/partition-table.bin \
  0xd000 build-cardputer-adv/ota_data_initial.bin \
  0x20000 build-cardputer-adv/xiaozhi.bin \
  0x600000 build-cardputer-adv/generated_assets.bin
```

Sostituire `PORT` con la porta seriale reale (es. `/dev/cu.usbmodem21101`).

## Link di riferimento

- [Documentazione ufficiale M5Stack Cardputer Adv](https://docs.m5stack.com/en/core/Cardputer-Adv)
