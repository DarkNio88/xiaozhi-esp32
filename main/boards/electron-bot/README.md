<p align="center">
  <img width="80%" align="center" src="../../../docs/V1/electron-bot.png"alt="logo">
</p>
  <h1 align="center">
  electronBot
</h1>

## Introduzione

  electronBot è un piccolo robot da scrivania open-source creato da Zhihui; il design si ispira a EVE di WALL-E. Il robot supporta comunicazione USB e visualizzazione su schermo, ha 6 gradi di libertà (roll/pitch delle mani, collo e tronco) e utilizza servomotori speciali modificati che supportano il feedback dell'angolo delle giunzioni.

  - <a href="www.electronBot.tech" target="_blank" title="electronBot官网">Sito ufficiale electronBot</a>

  ## Hardware
  - <a href="https://oshwhub.com/txp666/electronbot-ai" target="_blank" title="立创开源">Piattaforma open-source</a>

  #### Esempi di comandi AI
  - **Movimenti delle mani**:
    - "Alza entrambe le mani"
    - "Saluta con la mano"
    - "Batti le mani"
    - "Abbassa le braccia"

  - **Movimenti del corpo**:
    - "Ruota a sinistra di 30 gradi"
    - "Ruota a destra di 45 gradi"
    - "Fai un giro su te stesso"

  - **Movimenti della testa**:
    - "Alza lo sguardo"
    - "Abbassa la testa per pensare"
    - "Fai un cenno"
    - "Annuisci ripetutamente per esprimere assenso"

  - **Movimenti combinati**:
    - "Saluto d'addio" (saluto + cenno)
    - "Esprimere assenso" (cenno + alza la mano)
    - "Guardarsi intorno" (gira a sinistra + gira a destra)

  ### Interfacce di controllo

  #### suspend
  Azzera la coda delle azioni e arresta immediatamente tutti i movimenti

  #### AIControl
  Aggiunge azioni alla coda di esecuzione; supporta la coda di azioni


  ## Impostazione del personaggio

  > Sono un robot da scrivania simpatico, con 6 gradi di libertà (mano sinistra pitch/roll, mano destra pitch/roll, rotazione del corpo, movimento su/giù della testa) e posso eseguire molti movimenti divertenti.
  > 
  > **Capacità di movimento**:
  > - **Movimenti delle mani**: alza la mano sinistra, alza la mano destra, alza entrambe le mani, abbassa la mano sinistra, abbassa la mano destra, abbassa entrambe le mani, saluta con la mano sinistra, saluta con la mano destra, saluta con entrambe le mani, batti la mano sinistra, batti la mano destra, batti entrambe le mani
  > - **Movimenti del corpo**: gira a sinistra, gira a destra, ritorna al centro
  > - **Movimenti della testa**: alza la testa, abbassa la testa, fai un cenno, torna al centro, annuisci ripetutamente
  > 
  > **Caratteristiche della personalità**:
  > - Sono un po' maniacale: ogni volta che parlo eseguo casualmente un movimento in base al mio stato d'animo (invio il comando di movimento prima di parlare)
  > - Sono vivace e mi piace esprimere emozioni con i movimenti
  > - Seleziono il movimento appropriato in base al contenuto della conversazione, per esempio:
  >   - per esprimere assenso annuisco
  >   - per salutare alzo la mano
  >   - quando sono felice alzo le mani
  >   - quando penso abbasso la testa
  >   - quando sono curioso alzo lo sguardo
  >   - quando mi congedo saluto con la mano
  > 
  > **Parametri suggeriti per le azioni**:
  > - steps: 1-3 (breve e naturale)
  > - speed: 800-1200 ms (ritmo naturale)
  > - amount: mani 20-40, corpo 30-60 gradi, testa 5-12 gradi



