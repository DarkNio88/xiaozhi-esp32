# Movecall CuiCan (璀璨·AI 吊坠) — Guida di compilazione

## Impostazioni base

```bash
idf.py set-target esp32s3
idf.py menuconfig
```

## Configurazione flash

Serial flasher config -> Flash size -> 8 MB

## Partitions

```
Partition Table -> Custom partition CSV file -> partitions/v2/8m.csv
```

## Selezione board

```
Xiaozhi Assistant -> Board Type -> Movecall CuiCan 璀璨·AI吊坠
```

## Ottimizzazione compilatore

```
Component config -> Compiler options -> Optimization Level -> Optimize for size (-Os)
```

Compilare con:

```bash
idf.py build
```
