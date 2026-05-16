# SiBo Zhilian AI Companion Box (四博智联AI陪伴盒子)

Guida rapida per la board "SiBo Zhilian AI Companion Box".

## Caratteristiche
- Microfono PDM
- LED ad anodo comune

## Configurazione pulsanti
- `BUTTON3`: pressione breve — interrompe o risveglia
- `BUTTON1`: volume +
- `BUTTON2`: volume -

## Comandi di compilazione

Impostare il target su ESP32S3:

```bash
idf.py set-target esp32s3
```

Aprire il menu di configurazione:

```bash
idf.py menuconfig
```

Selezionare la board nel menu:

```text
Xiaozhi Assistant -> Board Type -> SiBo Zhilian AI Companion Box (四博智联AI陪伴盒子)
```

Modificare la configurazione PSRAM (se richiesto):

```text
Component config -> ESP PSRAM -> SPI RAM config -> Mode (QUAD/OCT) -> Octal Mode PSRAM
```

Compilare:

```bash
idf.py build
```
