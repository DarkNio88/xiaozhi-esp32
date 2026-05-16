## Introduzione al prodotto

- Scheda ESP32-S3 Muma con display LCD 1.54" per robot di chat vocale AI DeepSeek (N16R8).

## Funzionalità

- Piccolo "Muma" carino, supporta meteo e orologio, riproduzione video da SD, dialogo AI intelligente. Tutto il firmware è open source, adatto all'apprendimento della programmazione per bambini e facilmente estendibile.
- L'AI Xiaozhi supporta il risveglio vocale. La versione con touch supporta inoltre il risveglio tramite tocco e l'interruzione.
- Display: 1.54" ST7789, risoluzione 240x240
- Link al prodotto:
	https://spotpear.cn/shop/ESP32-S3-AI-1.54-inch-LCD-Display-TouchScreen-N16R8-muma-DeepSeek/sp-esp32-s3-1.54-muma-W-Bat.html

# Comandi di compilazione e configurazione

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
Xiaozhi Assistant -> Board Type -> Spotpear ESP32-S3-LCD-1.54-MUMA
```

**Compilazione:**

```bash
idf.py build
```
