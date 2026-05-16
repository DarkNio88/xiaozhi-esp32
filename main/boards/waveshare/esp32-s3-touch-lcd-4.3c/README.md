# Istruzioni d'uso

* [ESP32-S3-Touch-LCD-4.3C docs](https://www.waveshare.com/esp32-s3-touch-lcd-4.3c.htm)

## Esperienza rapida

Scarica il firmware compilato [qui](https://files.waveshare.com/wiki/ESP32-S3-Touch-LCD-4.3C/ESP32-S3-Touch-LCD-4.3C-Xiaozhi.bin)

```shell
esptool.py --chip esp32s3 -p /dev/ttyACM0 -b 460800 --before=default_reset --after=hard_reset write_flash --flash_mode dio --flash_freq 80m --flash_size 16MB 0x00 ESP32-S3-Touch-LCD-4.3C-Xiaozhi.bin 
```

## Uso di base

* idf version: v5.5-dev

1. Imposta il target di compilazione su `esp32s3`
```shell
idf.py set-target esp32s3
```

2. Modifica la configurazione
```shell
cp main/boards/esp32-s3-touch-lcd-4.3c/sdkconfig.4_3c sdkconfig
```

3. Compila e carica il programma
```shell
idf.py build flash monitor
```

## Log

@2025/05/17 Problemi di test

1. Al ritorno all'interfaccia dell'app, questa partizione deve esistere; altrimenti non ha effetto.
2.
3.

## TODO
