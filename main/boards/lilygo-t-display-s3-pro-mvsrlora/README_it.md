# LILYGO T-Display-S3-Pro (MVSRLora)

## Compilazione

Impostare il target su `ESP32S3` e configurare la board in `menuconfig`:

```bash
idf.py set-target esp32s3
idf.py menuconfig
```

Selezionare la variante desiderata in `Xiaozhi Assistant -> Board Type`:

- LILYGO T-Display-S3-Pro-MVSRLora
- LILYGO T-Display-S3-Pro-MVSRLora_NO_BATTERY

Link al repository ufficiale:

- https://github.com/Xinyuan-LilyGO/T-Display-S3-Pro
- https://github.com/Xinyuan-LilyGO/T-Display-S3-Pro-MVSRLora

Compilare con:

```bash
idf.py build
```
