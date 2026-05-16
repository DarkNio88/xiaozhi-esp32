# Board: Bread Compact (WiFi) + LCD + Camera

Hardware basato sulla scheda ESP32S3CAM; il codice è una modifica di `bread-compact-wifi-lcd`.

La fotocamera utilizzata è OV2640.

Attenzione: la fotocamera occupa molti pin I/O e utilizza i pin USB 19 e 20 dell'ESP32S3.

La mappatura dei pin è definita in `config.h`.

## Comandi per compilare e flashare

Impostare il target su ESP32S3:

```bash
idf.py set-target esp32s3
```

Aprire il menu di configurazione:

```bash
idf.py menuconfig
```

Selezionare la board nel menu:

```bash
Xiaozhi Assistant -> Board Type -> Breadboard: nuovo cablaggio (WiFi) + LCD + Camera
```

Compilare e flashare:

```bash
idf.py build flash
```
