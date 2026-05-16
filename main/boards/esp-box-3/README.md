# ESP-BOX-3

## Introduzione

<div align="center">
    <a href="https://github.com/espressif/esp-box"><b> ESP-BOX GitHub </b></a>
</div>

ESP-BOX-3 è un kit di sviluppo AIoT ufficiale di Espressif basato sul modulo ESP32-S3-WROOM-1, dotato di un display 2.4" 320x240 (ILI9341), array di due microfoni e supporto per wake word offline e AEC (echo cancellation) lato dispositivo.

## Caratteristiche hardware

- **MCU**: ESP32-S3-WROOM-1 (16MB Flash, 8MB PSRAM)
- **Display**: 2.4" IPS LCD (320x240, ILI9341)
- **Audio**: codec ES8311 + ADC ES7210 a doppio microfono
- **Funzionalità audio**: supporto per AEC lato dispositivo
- **Pulsanti**: tasto Boot (supporta singolo/doppio click)
- **Altro**: alimentazione e comunicazione via USB-C

## Configurazione e comandi di compilazione

**Imposta il target di compilazione su ESP32S3**

```bash
idf.py set-target esp32s3
```

**Apri menuconfig e configura**

```bash
idf.py menuconfig
```

Configura le seguenti opzioni:

### Configurazione base
- `Xiaozhi Assistant` → `Board Type` → seleziona `ESP BOX 3`

### Selezione stile UI

ESP-BOX-3 supporta diversi stili di UI; scegli lo stile tramite menuconfig:

- `Xiaozhi Assistant` → `Select display style` → scegli lo stile desiderato

#### Stili disponibili

##### Stile animazione emote (Emote animation style) - Raccomandato
- **Opzione di configurazione**: `USE_EMOTE_MESSAGE_STYLE`
- **Caratteristiche**: utilizza il sistema di visualizzazione delle espressioni personalizzato `EmoteDisplay`
- **Funzionalità**: supporta ricche animazioni delle espressioni, animazioni degli occhi e icone di stato
- **Adatto per**: scenari di assistente intelligente, offre un'interazione più vivace
- **Classe**: `emote::EmoteDisplay`

**⚠️ Importante**: per usare questo stile è necessario configurare risorse personalizzate:
1. `Xiaozhi Assistant` → `Flash Assets` → seleziona `Flash Custom Assets`
2. `Xiaozhi Assistant` → `Custom Assets File` → inserisci l'URL delle risorse:
   ```
   https://dl.espressif.com/AE/wn9_nihaoxiaozhi_tts-font_puhui_common_20_4-esp-box-3.bin
   ```

##### Stile messaggio predefinito (Enable default message style)
- **Opzione di configurazione**: `USE_DEFAULT_MESSAGE_STYLE` (predefinito)
- **Caratteristiche**: interfaccia standard per la visualizzazione dei messaggi
- **Funzionalità**: display tradizionale di testo e icone
- **Adatto per**: scenari di conversazione standard
- **Classe**: `SpiLcdDisplay`

##### Stile messaggi WeChat (Enable WeChat Message Style)
- **Opzione di configurazione**: `USE_WECHAT_MESSAGE_STYLE`
- **Caratteristiche**: interfaccia simile a WeChat
- **Funzionalità**: visualizzazione dei messaggi in stile bolle
- **Adatto per**: utenti che preferiscono lo stile WeChat
- **Classe**: `SpiLcdDisplay`

### Configurazione audio

#### Echo Cancellation (AEC) lato dispositivo
- `Xiaozhi Assistant` → `Enable Device-Side AEC` → abilita

L'hardware ESP-BOX-3 supporta AEC lato dispositivo, che riduce efficacemente il rumore dovuto alla riproduzione dagli altoparlanti migliorando la precisione del riconoscimento vocale.

**Cambio a runtime**: doppio click sul tasto Boot per abilitare/disabilitare AEC a runtime.

> **Nota**: l'AEC lato dispositivo richiede un percorso di riferimento pulito per l'uscita degli altoparlanti e una buona separazione fisica tra microfono e altoparlante per funzionare correttamente. L'hardware ESP-BOX-3 è progettato con ottimizzazioni in tal senso.

### Configurazione del wake word

ESP-BOX-3 supporta diversi metodi per il wake word:

- `Xiaozhi Assistant` → `Wake Word Implementation Type` → seleziona il tipo di wake word

Raccomandato:
- **Wakenet model with AFE** (`USE_AFE_WAKE_WORD`) - rilevamento del wake word compatibile con AEC

Premi `S` per salvare e `Q` per uscire.

**Compilazione**

```bash
idf.py build
```

**Flash**

Collega l'ESP-BOX-3 al computer ed esegui:

```bash
idf.py flash
```

## Descrizione dei pulsanti

### Funzioni del tasto Boot

#### Singolo click
- **Durante la configurazione WiFi**: entra in modalità di configurazione WiFi
- **In stato idle**: avvia la conversazione
- **Durante una conversazione**: interrompe o ferma la conversazione corrente

#### Doppio click (richiede AEC lato dispositivo abilitato)
- **In stato idle**: commuta l'AEC tra abilitato/disabilitato

## Domande frequenti

### 1. Perché è necessario l'AEC lato dispositivo?
L'AEC lato dispositivo può rimuovere in tempo reale l'influenza della riproduzione audio sugli ingressi del microfono, permettendo di riconoscere correttamente comandi vocali anche durante la riproduzione di musica o TTS.

### 2. Perché lo stile animazione emote non viene visualizzato?
Verifica di aver configurato correttamente l'URL delle risorse personalizzate e che il dispositivo possa accedere a tale URL per il download delle risorse.

### 3. Come ripristinare le impostazioni di fabbrica?
Tieni premuto il tasto Boot per più di 3 secondi; il dispositivo cancellerà tutte le impostazioni e si riavvierà.
