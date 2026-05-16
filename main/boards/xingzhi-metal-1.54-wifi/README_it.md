# Xingzhi 1.54 METAL (WiFi)

## Introduzione

Xingzhi 1.54 METAL è una versione migliorata con schermo LCD 1.54" e chip touch CST816; il case è in lega di alluminio per una migliore sensazione tattile.

## Operazioni e tasti
- Accensione: tenere premuto il pulsante di alimentazione 3s.
- Spegnimento: tenere premuto 5s per spegnere.
- Risveglio/Interruzione: tocco centrale breve.
- Ripristino rete: tocco centrale rapido per entrare in modalità di configurazione.
- Volume: tasti laterali per aumento/diminuzione (pressione lunga per incremento continuo).

## Compilazione

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
idf.py set-target esp32s3
idf.py menuconfig
```

Selezionare la board:

```text
Xiaozhi Assistant -> Board Type -> 无名科技星智1.54 METAL(wifi)
```

Compilare:

```bash
idf.py build
```

Per flash e log:

```bash
idf.py build flash monitor
```
