# Wuming Technology Xiaozhi ABS 2.0

## Introduzione
La Wuming Technology Xiaozhi ABS 2.0 è una scheda di sviluppo per interazione vocale AI con un ottimo rapporto qualità/prezzo. È dotata di un display LCD da 1,54" e di tasti fisici indipendenti; utilizza il modulo di comunicazione 4G **ML307R**, permettendo l'accesso ai modelli anche in assenza di Wi‑Fi.

## Caratteristiche principali
- Connessione duale: supporta commutazione tra Wi‑Fi e modulo 4G ML307R (Cat.1), adatta a scenari diversi
- Sistema di visualizzazione: display LCD 1.54" 240×240 con layout UI personalizzato ottimizzato per schermi quadrati da 1.54"
- Interazione con tasti fisici: tasto Boot indipendente e tasti volume +/-, supporto per click singolo, doppio click, pressione lunga e sequenze a cinque pressioni
- Estendibilità: slot Micro SD integrato per storage locale; è possibile prevedere un motore a vibrazione per feedback tattile sui tasti
- Gestione energetica: supporto per monitoraggio ADC della batteria, stato di carica in tempo reale, sospensione automatica e deep sleep per risparmio energetico
- Compatibilità ecosistema: piena compatibilità con il firmware Xiaozhi ESP32, supporto per modelli come Qwen/DeepSeek e compatibilità con il protocollo MCP per il controllo dei dispositivi
- A causa delle differenze hardware, la posizione di alcune emoticon e testi nella UI può variare leggermente

## Differenze principali con la versione in alluminio (XINGZHI_METAL_1_54_WIFI)
| Caratteristica | xingzhi-abs-2.0 | Versione in alluminio |
|----------------|------------------|---------------------|
| Modalità di interazione | Tasti fisici indipendenti (Boot/Volume+/Volume-) | Chip touch CST816 + interazione touch |
| Materiale scocca | Plastica ABS | Alluminio |

### Operazioni sui tasti
- **Accensione**: a dispositivo spento, tenere premuto il tasto di accensione per 3s per avviare
- **Spegnimento**: a dispositivo acceso, tenere premuto il tasto di accensione per 5s per spegnere
- **Risveglio/Interruzione**: a dispositivo in chiamata o in standby, premere il tasto Boot per risvegliare o interrompere una conversazione vocale in corso
- **Ripristino rete**: entro 1s dall'accensione, premere il tasto Boot per riavviare il dispositivo ed entrare nella configurazione della rete
- **Cambia modalità rete**: a dispositivo acceso, doppio click sul tasto Boot per commutare tra Wi‑Fi e 4G
- **Controllo stato SD**: a dispositivo acceso, premere il tasto Boot cinque volte per verificare lo stato di montaggio della SD e visualizzarlo sullo schermo
- **Aumenta volume**: a dispositivo acceso, premere il tasto Volume+ per aumentare il volume del 10%; tenere premuto Volume+ per 2s per passare direttamente al 100%
- **Diminuisci volume**: a dispositivo acceso, premere il tasto Volume- per diminuire il volume del 10%; tenere premuto Volume- per 2s per ridurre direttamente al 0% (silenzioso)

### Sospensione
- **Sospensione leggera**: dopo 60s di inattività il dispositivo entra in sospensione leggera (luminosità dello schermo ridotta all'1%)
- **Deep sleep**: dopo 300s di inattività il dispositivo si spegne automaticamente
- **Ripristino**: in sospensione leggera, premere qualsiasi tasto per risvegliare il dispositivo (la luminosità dello schermo viene ripristinata)

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

**Apri menuconfig**

```bash
idf.py menuconfig
```

**Seleziona la scheda**

```text
Xiaozhi Assistant -> Board Type -> Wuming Technology Xiaozhi ABS 2.0
```

**Compila**

```bash
idf.py build
```

**Scarica e apri il monitor seriale**

```bash
idf.py build flash monitor
```