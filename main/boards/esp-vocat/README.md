# ESP-VoCat 喵伴

## Introduzione

<div align="center">
    <a href="https://oshwhub.com/esp-college/echoear"><b> Pagina progetto su Oshwhub </b></a>
</div>

ESP-VoCat 喵伴 è un kit di sviluppo AI intelligente basato sul modulo ESP32-S3-WROOM-1, dotato di uno schermo tattile QSPI circolare da 1.85" e di un array a doppio microfono. Supporta il wake-word offline e algoritmi di localizzazione della sorgente sonora. Per i dettagli hardware consultare la pagina progetto su Oshwhub.

## Configurazione e comandi di compilazione

**Imposta il target di compilazione su ESP32S3**

```bash
idf.py set-target esp32s3
```

**Apri `menuconfig` e configura**

```bash
idf.py menuconfig
```

Configurare le seguenti opzioni:

### Configurazione di base
- `Xiaozhi Assistant` → `Board Type` → selezionare `Espressif ESP-VoCat`

### Scelta dello stile UI

ESP-VoCat supporta diversi stili di interfaccia; selezionarli tramite `menuconfig`:

- `Xiaozhi Assistant` → `Select display style` → seleziona lo stile di visualizzazione

#### Stili disponibili

##### Stile animazione Emote (Emote animation style) — Consigliato
- **Opzione di configurazione**: `USE_EMOTE_MESSAGE_STYLE`
- **Caratteristiche**: utilizza il sistema personalizzato `EmoteDisplay` per mostrare espressioni
- **Funzionalità**: supporta animazioni di espressioni, animazioni oculari e icone di stato
- **Adatto a**: scenari di assistente intelligente per un'interazione più vivace
- **Classe**: `emote::EmoteDisplay`

**⚠️ Importante**: per questo stile sono richieste risorse personalizzate:
1. `Xiaozhi Assistant` → `Flash Assets` → selezionare `Flash Custom Assets`
2. `Xiaozhi Assistant` → `Custom Assets File` → inserire l'URL del file di risorse:

```
https://dl.espressif.com/AE/wn9_nihaoxiaozhi_tts-font_puhui_common_20_4-echoear.bin
```

##### Stile messaggi predefinito (Enable default message style)
- **Opzione**: `USE_DEFAULT_MESSAGE_STYLE` (predefinito)
- **Caratteristiche**: interfaccia standard per la visualizzazione dei messaggi
- **Funzionalità**: visualizzazione tradizionale di testo e icone
- **Adatto a**: scenari di conversazione standard
- **Classe**: `SpiLcdDisplay`

##### Stile messaggi WeChat (Enable WeChat Message Style)
- **Opzione**: `USE_WECHAT_MESSAGE_STYLE`
- **Caratteristiche**: interfaccia in stile chat di WeChat
- **Funzionalità**: visualizzazione a bolle simile a WeChat
- **Adatto a**: utenti che preferiscono lo stile WeChat
- **Classe**: `SpiLcdDisplay`

> **Nota**: ESP-VoCat 喵伴 utilizza 16MB di Flash; è necessario usare una tabella di partizionamento dedicata per ripartire correttamente lo spazio tra applicazione, aggiornamenti OTA e file di risorse.

Premere `S` per salvare e `Q` per uscire.

**Compilazione**

```bash
idf.py build
```

**Flash**

Collegare ESP-VoCat 喵伴 al computer, assicurarsi che sia alimentato, quindi eseguire:

```bash
idf.py flash
```