# Mixgo_Nova (Yuankong · Gioventù) — Scheda di sviluppo

<img src="https://mixly.cn/public/icon/2024/6/09705006c1c643beb96338791ee1dea0_m.png" alt="Mixgo_Nova" width="200"/>

**[Mixgo_Nova](https://mixly.cn/fredqian/mixgo_nova)** è una scheda di sviluppo multifunzione progettata per IoT, istruzione e progetti maker; integra numerosi sensori e moduli di comunicazione wireless, supporta la programmazione grafica (Mixly) e l'interazione vocale offline, ideale per prototipazione rapida e didattica.

---

## 🛠️ Comandi di compilazione e configurazione

**Problema di acquisizione CODE MIC con ES8374:**

```
managed_components\espressif__esp_codec_dev\device\es8374

static int es8374_config_adc_input(audio_codec_es8374_t *codec, es_adc_input_t input)
{
    int ret = 0;
    int reg = 0;
    ret |= es8374_read_reg(codec, 0x21, &reg);
    if (ret == 0) {
        reg = (reg & 0xcf) | 0x24;
        ret |= es8374_write_reg(codec, 0x21, reg);
    }
    return ret;
}

PS: Alla riga L386 cambiare `reg = (reg & 0xcf) | 0x14;` in `reg = (reg & 0xcf) | 0x24;`
```

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
Xiaozhi Assistant -> Board Type -> Yuankong · Gioventù
```

**Modifica configurazione PSRAM:**

```
Component config -> ESP PSRAM -> SPI RAM config -> Mode (QUAD/OCT) -> QUAD Mode PSRAM
```

**Modifica configurazione Flash:**

```
Serial flasher config -> Flash size -> 8 MB
Partition Table -> Custom partition CSV file -> partitions/v2/8m.csv
```

**Compilazione:**

```bash
idf.py build
```

**Unisci BIN:**

```bash
idf.py merge-bin -o xiaozhi-nova.bin -f raw
```