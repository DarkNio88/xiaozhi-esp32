# M5Stack Cardputer Adv — Panoramica e flash

## Specifiche hardware (sintesi)
- MCU: ESP32‑S3FN8 @ 240MHz
- Flash: 8MB
- Display: ST7789V2 1.14" (240×135)
- Audio: ES8311 + NS4150B
- IMU: BMI270
- Batteria: 1750mAh

## Flash (esempio)

Sostituire `PORT` con la porta seriale corretta:

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

Per dettagli hardware consultare il README originale o la documentazione M5Stack.
