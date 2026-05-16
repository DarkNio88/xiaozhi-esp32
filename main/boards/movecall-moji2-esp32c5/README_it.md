# Guida alla compilazione

Questa pagina spiega come configurare e compilare il firmware per Movecall Moji2.0 (derivato Xiaozhi AI).

## Requisiti di ambiente
- **ESP‑IDF**: v5.5
- **Chip target**: ESP32‑C5

## Informazioni hardware
Questo progetto si basa sul design open‑source:
- [Movecall Moji2 su OSHWHUB](https://oshwhub.com/movecall/moji2)

---

## Passi per la compilazione

### 1. Impostare il target
Impostare il target su ESP32‑C5:

```bash
idf.py set-target esp32c5
```

### 2. Selezionare la board
Aprire il menu di configurazione:

```bash
idf.py menuconfig
```

Nel menu navigare:
`Xiaozhi Assistant` -> `Board Type` -> `Movecall Moji2.0 小智AI衍生版`

Salvare con **S**, confermare con Invio, uscire con **Q**.

### 3. Compilare

```bash
idf.py build
```

---

## Comandi utili

Pulire la build (se compaiono errori):

```bash
idf.py fullclean
```

Flash del firmware:

```bash
idf.py flash
```

Monitor seriale:

```bash
idf.py monitor
```
