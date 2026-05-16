# ESP‑BOX‑3

## Introduzione

ESP‑BOX‑3 è un kit AIoT ufficiale basato su ESP32‑S3‑WROOM‑1 (16 MB Flash, 8 MB PSRAM), con schermo IPS 2.4" (320×240), array di due microfoni e supporto per AEC su dispositivo.

## Caratteristiche hardware
- MCU: ESP32‑S3‑WROOM‑1
- Schermo: 2.4" IPS LCD (ILI9341)
- Audio: codec ES8311 + ADC ES7210
- Flash: 16 MB (PSRAM 8 MB)
- Pulsanti: Boot (single/double click)

## Configurazione e compilazione

Impostare il target su ESP32S3:

```bash
idf.py set-target esp32s3
```

Aprire `menuconfig` e configurare:

- `Xiaozhi Assistant` → `Board Type` → selezionare `ESP BOX 3`
- `Xiaozhi Assistant` → `Select display style` → scegliere lo stile di UI desiderato

Se si sceglie lo stile "Emote animation style", è richiesto un file di risorse personalizzato (configurabile in `Flash Assets`).

Compilare e flashare:

```bash
idf.py build
idf.py flash
```

## Funzionalità runtime

- Supporto AEC lato dispositivo (può essere attivato/disattivato con doppio clic su Boot)
- Diverse opzioni di stile UI (emote, default, WeChat‑like)

## Ripristino e problemi comuni

- Per resettare e cancellare la configurazione: tenere premuto Boot per 3 secondi.
