# jiuchuan-xiaozhi-sound
Altoparlante AI "Xiaozhi" di Jiuchuan Technology

## 🛠️ Guida alla compilazione
**Ambiente di sviluppo**: ESP-IDF v5.4.1

### Passi di compilazione:
> ⚠️ **Suggerimento**: se durante la compilazione l'accesso ai repository online fallisce, prova a cambiare lo stato dell'acceleratore o modifica il file [idf_component.yml] per usare mirror nazionali.

1. Apri la cartella del progetto con VSCode;
2. Pulisci il progetto (Clean Project);
3. Imposta la versione ESP‑IDF su `v5.4.1`;
4. Clicca la notifica in basso a destra in VSCode per generare il file `compile_commands.json`;
5. Imposta il dispositivo target su `[esp32s3] -> [JTAG]`;
6. Apri **SDK Configuration Editor**;
7. Imposta **Board Type** su **Jiuchuan Technology**;
8. Salva la configurazione e avvia la compilazione.

## 🔌 Procedure di flashing
1. Collega l'altoparlante al PC con un cavo dati;
2. Spegni il dispositivo e tieni premuto il tasto di accensione;
3. Nel tool di flashing seleziona la porta seriale corretta (COM Port);
4. Premi il pulsante di flashing e scegli la modalità UART;
5. Non rilasciare il tasto di accensione finché il flashing non è completato.

## Piedinatura
- 1-9:
  - 1. DAT2: NC
  - 2. CD/DAT3: Chip Select, attivo basso. (sconosciuto)
  - 3. CMD: IO48 (Command/Response Line), la scheda invia comandi e dati alla TF card attraverso questa linea
  - 4. VDD: Alimentazione
  - 5. CLX: IO47 (clock), generato dall'host per sincronizzare la comunicazione dati
  - 6. VSS: GND
  - 7. DAT0: IO21, SPI_MISO, la TF card restituisce risposte e dati sull'host tramite questa linea
  - 8. DAT1: NC

Da destra a sinistra, numerati da 1 a 9.