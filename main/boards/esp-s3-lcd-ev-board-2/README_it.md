# Scheda di sviluppo ESP‑S3 LCD EV (versione 2)

Verificare la versione hardware della scheda prima di procedere: tra la v1.4 e la v1.5 sono cambiate alcune assegnazioni IO.

Consultare il manuale ufficiale per dettagli: https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32s3/esp32-s3-lcd-ev-board/user_guide.html

## Mappature IO principali (v1.4 → v1.5)

- `I2C_SCL`: IO18 → IO48
- `I2C_SDA`: IO8  → IO47
- `LCD_DATA6`: IO47 → IO8
- `LCD_DATA7`: IO48 → IO18

Questa versione supporta solo display 800×480.
