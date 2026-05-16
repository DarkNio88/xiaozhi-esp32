# Link prodotto

[Waveshare ESP32-C6-Touch-LCD-1.69](https://www.waveshare.net/shop/ESP32-C6-Touch-LCD-1.69.htm)
[Waveshare ESP32-C6-LCD-1.69](https://www.waveshare.net/shop/ESP32-C6-LCD-1.69.htm)

# Comandi di compilazione e configurazione

**Clona il repository**

```bash
git clone https://github.com/78/xiaozhi-esp32.git
```

**Entra nella cartella del progetto**

```bash
cd xiaozhi-esp32
```

**Imposta il target di compilazione su ESP32C6**

```bash
idf.py set-target esp32c6
```

**Apri `menuconfig`**

```bash
idf.py menuconfig
```

**Seleziona la scheda**

```text
Xiaozhi Assistant -> Board Type -> Waveshare ESP32-C6-LCD-1.69
```

**Compila**

```bash
idf.py build
```

**Scarica e apri il monitor seriale**

```bash
idf.py build flash monitor
```

## Operazioni sui tasti
### Tasto BOOT
**Se premuto prima di essere connessi al server:** entra in modalità di configurazione rete (provisioning)
**Se premuto quando connessi al server:** risveglio / interruzione

### Tasto PWR
**Doppio click:** spegne/riaccende lo schermo
**Premuto a lungo:** accensione/spegnimento del dispositivo