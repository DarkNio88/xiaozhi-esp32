# Scheda ESP‑S3 LCD EV — Note hardware

Verificare la versione hardware della scheda e selezionare il relativo `ev_board type` in `menuconfig` se necessario. Le versioni 1.4 e 1.5 differiscono solo nell'assegnazione degli IO.

Documentazione ufficiale: https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32s3/esp32-s3-lcd-ev-board/user_guide.html

Mappature IO principali (esempio 1.4 → 1.5):

- `I2C_SCL`: IO18 → IO48
- `I2C_SDA`: IO8  → IO47
- `LCD_DATA6`: IO47 → IO8
- `LCD_DATA7`: IO48 → IO18

Questa versione del driver supporta display 480×480.
