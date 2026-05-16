# ESP-Spot

## Introduzione

<div align="center">
    <a href="https://oshwhub.com/esp-college/esp-spot"><b> Pagina progetto su Oshwhub </b></a>
    |
    <a href="https://www.bilibili.com/video/BV1ekRAYVEZ1/"><b> Demo su Bilibili </b></a>
</div>

ESP-Spot è una scheda open-source del progetto ESP Friends per interazione vocale intelligente. Integra microfono, altoparlante e sensore IMU; può funzionare a batteria. ESP-Spot non ha display, ma dispone di un LED RGB e due pulsanti. Dettagli hardware sono disponibili sulla pagina del progetto su Oshwhub.

Il progetto ESP-Spot utilizza i moduli ESP32-S3-WROOM-1-N16R8 o ESP32-C5-WROOM-1-N8R8. Se si replica la scheda con una dimensione di Flash diversa, aggiornare i parametri corrispondenti.

## Configurazione e comandi di compilazione

**Selezione del target di compilazione**

```bash
idf.py set-target esp32s3 # Spot S3
# oppure
idf.py set-target esp32c5 # Spot C5
```

**Aprire `menuconfig` e configurare**

```bash
idf.py menuconfig
```

Configurare le seguenti voci:

- `Xiaozhi Assistant` → `Board Type` → selezionare `ESP-Spot-S3` o `ESP-Spot-C5`

Premere `S` per salvare e `Q` per uscire.

**Compilare**

```bash
idf.py build
```

**Flash**

```bash
idf.py flash
```

> [!TIP]
>
> **Se il computer non rileva la porta seriale di ESP-Spot, provate i seguenti passi:**
> 1. Aprite il coperchio frontale;
> 2. Estraete la scheda PCB che contiene il modulo;
> 3. Tenete premuto il pulsante <kbd>BOOT</kbd> e inserite nuovamente la PCB (fate attenzione all'orientamento).
>
> In questo modo ESP-Spot dovrebbe entrare in modalità di download. Dopo il flash potrebbe essere necessario ricollegare la PCB.

## Risparmio energetico

ESP-Spot supporta la modalità Deep Sleep.

Quando è inattivo per 10 minuti, ESP-Spot entra automaticamente in Deep Sleep; premere un pulsante oppure scuoterlo per riattivarlo.
