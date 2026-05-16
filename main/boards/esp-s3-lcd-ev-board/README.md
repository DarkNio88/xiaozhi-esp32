Verificate la versione hardware della vostra scheda; se esistono più versioni, selezionate il tipo `ev_board` corrispondente nella configurazione.

Le versioni 1.4 e 1.5 differiscono solo nella mappatura degli I/O.

Consultate la documentazione ufficiale per i dettagli: https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32s3/esp32-s3-lcd-ev-board/user_guide.html

Modifiche specifiche della mappatura I/O:

```
I2C_SCL     IO18    ->     IO48
I2C_SDA     IO8     ->     IO47
LCD_DATA6   IO47    ->     IO8
LCD_DATA7   IO48    ->     IO18
```

Questa versione supporta solo display 480x480.