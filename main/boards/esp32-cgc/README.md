# Link al progetto della scheda
- V1: [https://oshwhub.com/wdmomo/esp32-xiaozhi-kidpcb](https://oshwhub.com/wdmomo/esp32-xiaozhi-kidpcb)
- V2: [https://oshwhub.com/wdmomo/esp32-xiaozhi-kidpcb_copy](https://oshwhub.com/wdmomo/esp32-xiaozhi-kidpcb_copy)
- Ulteriori informazioni: [wdmomo.fun](https://www.wdmomo.fun:81/doc/index.html?file=001_%E8%AE%BE%E8%AE%A1%E9%A1%B9%E7%9B%AE/0001_%E5%B0%8F%E6%99%BAAI/002_ESP32-CGC%E5%BC%80%E5%8F%91%E6%9D%BF%E5%B0%8F%E6%99%BAAI)

## Comandi di compilazione e configurazione

**Imposta il target di compilazione su ESP32:**

```bash
idf.py set-target esp32
```

**Apri `menuconfig`:**

```bash
idf.py menuconfig
```

**Seleziona la scheda:**

```
Xiaozhi Assistant -> Board Type -> ESP32 CGC
```

**Seleziona il tipo di display:**

```
Xiaozhi Assistant -> LCD Type -> "ST7735, risoluzione 128×128"
```

**Compila:**

```bash
idf.py build
```
