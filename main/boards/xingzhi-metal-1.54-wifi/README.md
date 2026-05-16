# Wuming Technology Xingzhi 1.54 METAL (Wi‑Fi)

## Introduzione
Wuming Technology Xingzhi 1.54 METAL (Wi‑Fi) è una versione aggiornata del modello Xingzhi 1.54, dotata di un display LCD da 1.54" e del chip touch CST816. Utilizza l'interazione touch al posto dei tasti fisici e ha una scocca in lega di alluminio, migliorando l'esperienza d'uso e la qualità percepita.

### Operazioni sui tasti
- **Accensione**: a dispositivo spento, tenere premuto il tasto di accensione per 3s per avviare (nelle versioni precedenti premere 1s).
- **Spegnimento**: a dispositivo acceso, tenere premuto il tasto di accensione per 5s per spegnere (nelle versioni precedenti, l'inserimento USB non spegne automaticamente).
- **Risveglio/Interruzione**: durante una conversazione, toccare il pulsante centrale.
- **Ripristino rete**: dopo l'accensione, toccare il pulsante centrale entro 1s per riavviare ed entrare nella configurazione della rete.
- **Aumenta volume**: a dispositivo acceso, toccare il pulsante destro per aumentare il volume; tenendo premuto per 2s aumenta continuamente.
- **Diminuisci volume**: a dispositivo acceso, toccare il pulsante sinistro per diminuire il volume; tenendo premuto per 2s diminuisce continuamente.

### Sospensione
- **Sospensione leggera**: dopo 60s di inattività entra in sospensione leggera (luminosità schermo ridotta all'1%).
- **Sospensione profonda**: dopo 300s di inattività entra in sospensione profonda (spegnimento).
- **Ripristino**: in sospensione leggera, toccare il pulsante centrale per risvegliare il dispositivo (la luminosità del display viene ripristinata).

# Comandi di compilazione e configurazione

**Clona il repository**

```bash
git clone https://github.com/78/xiaozhi-esp32.git
```

**Entra nella cartella del progetto**

```bash
cd xiaozhi-esp32
```

**Imposta il target su ESP32S3**

```bash
idf.py set-target esp32s3
```

**Apri `menuconfig`**

```bash
idf.py menuconfig
```

**Seleziona la scheda**

```text
Xiaozhi Assistant -> Board Type -> Wuming Technology Xingzhi 1.54 METAL (wifi)
```

**Compila**

```bash
idf.py build
```

**Scarica e apri il monitor seriale**

```bash
idf.py build flash monitor
```