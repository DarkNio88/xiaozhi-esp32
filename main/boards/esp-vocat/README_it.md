# ESP‑VoCat ("Meow Companion")

## Introduzione

ESP‑VoCat è un kit AI con ESP32‑S3‑WROOM‑1, display circolare QSPI 1.85", doppio microfono e supporto per wake‑word e sound‑source localization. Hardware e dettagli su OSHWHub.

## Compilazione e configurazione

Impostare il target su ESP32S3:

```bash
idf.py set-target esp32s3
```

Aprire `menuconfig` e selezionare la board:

```text
Xiaozhi Assistant -> Board Type -> Espressif ESP-VoCat
```

Selezionare lo stile UI in `Xiaozhi Assistant` → `Select display style`.

Se si usa lo stile "Emote animation style" è necessario impostare il file di risorse custom in `Flash Assets` → `Custom Assets File` con l'URL fornito nel file originale.

Compilare e flashare:

```bash
idf.py build
idf.py flash
```
