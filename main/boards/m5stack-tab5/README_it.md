# M5Stack Tab5 — Istruzioni rapide

## Panoramica
Vedere la documentazione ufficiale M5Stack per dettagli hardware.

## Quick start

- `idf` raccomandata: v5.5.2 o superiore (consigliato: v6.0‑dev)
- Non cambiare le dipendenze `esp_video`/`esp_ipa` nel manifest `main/idf_component.yml` a meno che non si modifichi il codice.

## Build con release script

```bash
python ./scripts/release.py m5stack-tab5
```

## Build manuale

```bash
idf.py flash monitor
```

Nota: per entrare in download mode tenere premuto il pulsante di reset per ~2s fino a che il LED verde lampeggia rapidamente.
