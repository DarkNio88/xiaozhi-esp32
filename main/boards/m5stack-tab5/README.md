# Guida rapida — M5Stack Tab5

- Documentazione ufficiale: https://docs.m5stack.com/zh_CN/core/Tab5

## Avvio rapido

Usare `M5Burner` per selezionare il modello Tab5 e cercare "Xiaozhi" per scaricare il firmware precompilato.

## Requisiti di `idf` e dipendenze

- `idf` versione consigliata: v5.5.2 o superiore (opzionale: v6.0-dev per funzionalità sperimentali)
- Non è necessario sovrascrivere le dipendenze: il progetto specifica le versioni corrette di `esp_video` e `esp_ipa` in `main/idf_component.yml`. Non modificare le versioni delle dipendenze a meno che non si adatti anche il codice sorgente.

Per utenti con ESP32‑P4 Rev < 3.0: assicurarsi che `sdkconfig.defaults` contenga la seguente riga:

```
CONFIG_ESP32P4_SELECTS_REV_LESS_V3=y
```

Altrimenti durante il flashing potreste ricevere l'errore: `'bootloader/bootloader.bin' requires chip revision in range [v3.0 - v3.99] (this chip is revision v1.x)`

## Compilazione automatica (consigliata)

```shell
python ./scripts/release.py m5stack-tab5
```

## Compilazione manuale

1. Modifica le opzioni in `m5stack-tab5/config.json` se necessario.
2. Compila con:

```shell
idf.py build
```

3. Flash e monitor:

```shell
idf.py flash monitor
```

> Nota: per entrare in modalità download tenere premuto il tasto di reset per ~2 secondi finché il LED verde non lampeggia, quindi rilasciare.

## Segnalazioni test

- @2025/05/17: problemi riscontrati durante i test:
	- `listening...` impiega diversi secondi prima che l'input vocale venga catturato
	- regolazione della luminosità non accurata
	- controllo del volume non coerente
