# Xiaozhi Cloud Chat S3

## Introduzione

Xiaozhi Cloud Chat S3 è un progetto modificato di Xiaozhi AI: è il primo prodotto di produzione con schermo grande da 2.8" a tutela degli occhi, caratteri di grandi dimensioni e batteria da 2000 mAh. Include numerose innovazioni e ottimizzazioni.

## Versione ufficiale

Il codice della versione ufficiale è mantenuto nel progetto principale Xiaozhi AI e segue gli aggiornamenti del progetto, facilitando estensioni personalizzate e firmware di terze parti. Supporta wake-word, interruzione vocale, OTA e commutazione libera 4G/Wi‑Fi.

### Operazioni con i pulsanti

- **Accensione**: dallo stato spento, tenere premuto il pulsante per 1 secondo e poi rilasciare per accendere.
- **Spegnimento**: da acceso, tenere premuto il pulsante per 1 secondo; la barra del titolo mostrerà "Per favore attendere" e dopo 2 secondi il dispositivo si spegnerà automaticamente.
- **Sveglia/Interruzione**: in una normale conversazione, premere una volta il pulsante.
- **Commutazione 4G/Wi‑Fi**: durante l'avvio o nella schermata di configurazione della rete, fare doppio clic sul pulsante entro 1 secondo (richiede modulo 4G installato).
- **Cambia modalità di interruzione vocale (AEC)**: dopo l'avvio, quando è in stato inattivo, fare doppio clic sul pulsante entro 1 secondo per scorrere le modalità di interruzione vocale.
- **Ripristino della configurazione di rete**: a dispositivo acceso, premere tre volte il pulsante entro 1 secondo per riavviare e avviare la procedura di configurazione della rete.

### Comandi vocali

- **Abilita/disabilita interruzione vocale (AEC)**: quando si riproduce musica, disattivare l'interruzione vocale per evitare che la riproduzione venga interrotta.
- **Cambia modalità di visualizzazione IPS**: la nuova versione di Xiaozhi Cloud Chat S3 utilizza uno schermo IPS; potrebbe essere necessario cambiare la modalità di visualizzazione per ottenere il rendering corretto.

## Versione modificata (mod)

La versione modificata (mod) è mantenuta separatamente a causa di estese modifiche a basso livello e viene periodicamente unita al ramo principale.

### Perché è una mod

- Prima implementazione del provisioning via QR code WeChat.
- Prima a supportare provisioning da un singolo telefono.
- Prima a supportare accesso alla console tramite scansione QR.
- Prima a fornire interfacce in tradizionale, giapponese e inglese.
- Prima a offrire una modalità completamente vocale.
- Fornisce script dedicati per il flashing e altre opzioni di aggiornamento.

## Differenze tra le versioni

| Caratteristica | Versione ufficiale | Versione mod |
| -------------- | ------------------ | ------------ |
| Interruzione vocale | ✓ | ✓ |
| Funzionalità 4G | ✓ | ✓ |
| Aggiornamento automatico firmware | ✓ | X |
| Supporto firmware terzi | ✓ | X |
| Schermata standby meteo | X | ✓ |
| Promemoria sveglia | X | ✓ |
| Riproduzione musica da rete | X | ✓ |
| Provisioning via QR WeChat | X | ✓ |
| Provisioning da singolo telefono | X | ✓ |
| Accesso console via QR | X | ✓ |
| Interfacce tradizionale/giapponese/inglese | X | ✓ |
| Supporto multilingua | richiede compilazione manuale | ✓ |
| Supporto altoparlanti/cuffie Bluetooth esterne | ✓ | ✓ |

# Comandi di compilazione e configurazione

**Clona il repository**

```bash
git clone https://github.com/78/xiaozhi-esp32.git
```

**Entra nella cartella del progetto**

```bash
cd xiaozhi-esp32
```

**Imposta il target di compilazione su ESP32S3**

```bash
idf.py set-target esp32s3
```

**Apri `menuconfig`**

```bash
idf.py menuconfig
```

**Seleziona la scheda**

```bash
Xiaozhi Assistant -> Board Type -> seleziona `Xiaozhi Cloud Chat S3` -> abilita `Enable Device-Side AEC`
```

**Compilazione**

```bash
idf.py build
```

**Compila, flash e apri il monitor seriale**

```bash
idf.py build flash monitor
```
