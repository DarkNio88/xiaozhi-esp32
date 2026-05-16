# Xingzhi ABS 2.0

## Introduzione

Xingzhi ABS 2.0 è una scheda di sviluppo per interazione vocale con display 1.54" e modulo 4G ML307R integrato, pensata per scenari senza Wi‑Fi.

## Caratteristiche principali
- Supporto Wi‑Fi e ML307R Cat.1 4G
- Display 1.54" 240×240
- Tasti fisici per Boot e controllo volume (supporto tap/long press/double/triple/5‑tap)
- Supporto MicroSD, gestione batteria e risparmio energetico

## Compilazione

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
idf.py set-target esp32s3
idf.py menuconfig
idf.py build
```

Per flash e monitor:

```bash
idf.py build flash monitor
```
