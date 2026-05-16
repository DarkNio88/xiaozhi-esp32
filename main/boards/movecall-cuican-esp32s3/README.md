# Guida alla configurazione e compilazione (ESP32-S3)

## Comandi di base

### Imposta il target del chip

```bash
idf.py set-target esp32s3
```

### Apri l'interfaccia di configurazione

```bash
idf.py menuconfig
```

### Configurazione Flash:

```
Serial flasher config -> Flash size -> 8 MB
```

### Configurazione tabella partizioni:

```
Partition Table -> Custom partition CSV file -> partitions/v2/8m.csv
```

### Selezione della scheda di sviluppo:

```
Xiaozhi Assistant -> Board Type -> Movecall CuiCan (pendente AI "CuiCan")
```

### Abilita ottimizzazione compilazione:

```
Component config → Compiler options → Optimization Level → Optimize for size (-Os)
```

### Compilazione:

```bash
idf.py build
```