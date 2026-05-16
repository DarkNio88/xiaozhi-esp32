# Jiuchuan XiaoZhi (jiuchuan-xiaozhi-sound)

## Guida rapida alla compilazione

Ambiente di sviluppo raccomandato: ESP‑IDF v5.4.1

Passaggi principali:

1. Aprire il progetto in VSCode.
2. Pulire il progetto (Clean Project).
3. Impostare ESP‑IDF su `v5.4.1`.
4. Generare `compile_commands.json` tramite l'estensione VSCode (se richiesto).
5. Selezionare il target `esp32s3` e configurare `Board Type` su `九川科技` in `menuconfig`.
6. Compilare con `idf.py build`.

### Avvertenza
Se la compilazione fallisce per problemi di accesso a librerie online, è possibile usare mirror nazionali o modificare `idf_component.yml` per puntare a sorgenti locali.

### Flash
Seguite la procedura di flash descritta nel README originale: tenere premuto il tasto di alimentazione durante il trasferimento se richiesto.
