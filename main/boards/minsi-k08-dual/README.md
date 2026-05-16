minsi-k08-wifi e minsi-k08-ml307 sono soluzioni proposte da Minsi Technology basate su ESP32S3N16R8, dotate di amplificatore di potenza audio MAX98357 e microfono omnidirezionale INMP441. Si tratta di una trasformazione dello speaker K08 (trasparente) per ottenere un robot di chat AI in stile punk con grandi altoparlanti e batteria di grande capacità, progettato per l'esperienza vocale Xiaozhi.

<a href="https://item.taobao.com/item.htm?id=889892765588" target="_blank" title="Minsi-k08">Minsi-k08</a>

  <a href="minsi-k08.jpg" target="_blank" title="Minsi-k08">
    <img src="minsi-k08.jpg" width="240" />
  </a>




# Comandi di compilazione e configurazione

**Imposta il target di compilazione su ESP32S3:**

```bash
idf.py set-target esp32s3
```

**Apri menuconfig:**

```bash
idf.py menuconfig
```

**Seleziona la scheda:**

```
Xiaozhi Assistant -> Board Type -> Minsi K08 (DUAL)
```

**Compilazione e flashing:**

```bash
idf.py build flash
```
