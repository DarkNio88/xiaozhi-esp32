L'hardware è basato sulla scheda di sviluppo ESP32S3CAM; il codice è una modifica di `bread-compact-wifi-lcd`.
La fotocamera utilizzata è OV2640.
Nota: la fotocamera occupa molte linee IO, pertanto utilizza i pin USB 19 e 20 dell'ESP32S3.
Il cablaggio è definito in `config.h`.

# Comandi di configurazione e compilazione

**Imposta il target di compilazione su ESP32S3:**

```bash
idf.py set-target esp32s3
```

**Apri menuconfig:**

```bash
idf.py menuconfig
```

**Seleziona la scheda:**

```bash
Xiaozhi Assistant -> Board Type -> Breadboard nuovo cablaggio (WiFi) + LCD + Camera
```

**Compilazione e flashing:**

```bash
idf.py build flash
```