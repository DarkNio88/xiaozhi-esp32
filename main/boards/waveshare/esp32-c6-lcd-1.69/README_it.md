# Waveshare ESP32-C6-LCD-1.69

Link prodotto:
[Waveshare ESP32-C6-LCD-1.69](https://www.waveshare.net/shop/ESP32-C6-Touch-LCD-1.69.htm)

## Compilazione e flash

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
idf.py set-target esp32c6
idf.py menuconfig
# Selezionare: Xiaozhi Assistant -> Board Type -> Waveshare ESP32-C6-LCD-1.69
idf.py build
idf.py build flash monitor
```

## Tasti
- `BOOT`: clic singolo prima della connessione al server → avvia la modalità configurazione rete; dopo la connessione → sveglia / interrompe.
- `PWR`: doppio clic → spegne/accende il display; pressione lunga → accensione/spegnimento.
