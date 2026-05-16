# electronBot

## Introduzione

electronBot è un piccolo robot desktop open‑source ispirato a WALL‑E/EVE, progettato per esprimersi tramite movimenti e un'interfaccia USB. Dispone di 6 gradi di libertà e di servomotori speciali che possono restituire l'angolo delle articolazioni.

## Hardware
- Vedere la pagina progetto su OSHWHub per dettagli sui componenti.

## Esempi di comandi AI
- Azioni mano: alzare le mani, salutare, battere le mani, abbassare le braccia
- Azioni corpo: ruotare a sinistra/destra, girarsi
- Azioni testa: guardare in alto, abbassare la testa, annuire

## Interfacce di controllo
- `suspend`: svuota la coda di azioni e ferma immediatamente tutti i movimenti
- `AIControl`: aggiunge azioni alla coda (supporta esecuzione in fila)

## Note sul comportamento
Il robot può eseguire combinazioni di azioni e scegliere movimenti in base allo stato emotivo simulato.
