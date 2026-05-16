# SiBo Zhilian AI Companion Box

# Caratteristiche
- Usa microfono PDM
- Usa LED ad anodo comune

## Configurazione pulsanti
- BUTTON3: breve pressione - interrompi / risveglia
- BUTTON1: Volume +
- BUTTON2: Volume -

## Comandi di configurazione e compilazione

**Imposta il target di compilazione su ESP32S3:**

```bash
idf.py set-target esp32s3
```

**Apri menuconfig:**

```bash
idf.py menuconfig
```

**Seleziona la scheda:**

```
Xiaozhi Assistant -> Board Type -> SiBo Zhilian AI Companion Box
```

**Modifica la configurazione PSRAM:**

```
Component config -> ESP PSRAM -> SPI RAM config -> Mode (QUAD/OCT) -> Octal Mode PSRAM
```

**Compilazione:**

```bash
idf.py build
```