# 使用说明 

* [M5Stack Tab5 docs](https://docs.m5stack.com/zh_CN/core/Tab5)

## 快速体验

到 [M5Burner](https://docs.m5stack.com/zh_CN/uiflow/m5burner/intro) 选择 Tab5 搜索小智下载固件

## 基础使用

* idf version: v5.5.2 or above (recommended: v6.0-dev)

* No dependency override needed — the project already specifies the correct `esp_video` and `esp_ipa` versions in `main/idf_component.yml`. Do NOT change the dependency versions unless you are also modifying the source code to match the older API.

针对 ESP32-P4 Rev <3.0 用户:
确保你的 sdkconfig.defaults 包含:

CONFIG_ESP32P4_SELECTS_REV_LESS_V3=y

否则烧写的时候会出现：'bootloader/bootloader.bin' requires chip revision in range [v3.0 - v3.99] (this chip is revision v1.x)

1. 使用 release.py 编译

```shell
python ./scripts/release.py m5stack-tab5
```

如需手动编译，请参考 `m5stack-tab5/config.json` 修改 menuconfig 对应选项。
# Istruzioni

* [Documentazione M5Stack Tab5](https://docs.m5stack.com/zh_CN/core/Tab5)

## Avvio rapido

Usare [M5Burner](https://docs.m5stack.com/zh_CN/uiflow/m5burner/intro): selezionare Tab5 e cercare "小智" per scaricare il firmware.

## Uso di base

* `idf` versione: v5.5.2 o superiore (consigliato: v6.0-dev)

* Non è necessario sovrascrivere dipendenze — il progetto specifica già le versioni corrette di `esp_video` e `esp_ipa` in `main/idf_component.yml`. NON cambiare le versioni delle dipendenze a meno che non si modifichi anche il codice sorgente per adattarlo a una API più vecchia.

Per utenti con ESP32-P4 Rev < 3.0:
Assicurarsi che il vostro `sdkconfig.defaults` contenga:

```
CONFIG_ESP32P4_SELECTS_REV_LESS_V3=y
```

Altrimenti durante il flash potreste vedere: `'bootloader/bootloader.bin' requires chip revision in range [v3.0 - v3.99] (this chip is revision v1.x)`

1. Compilare con `release.py`:

```shell
python ./scripts/release.py m5stack-tab5
```

Per compilazione manuale, consultare `m5stack-tab5/config.json` e modificare le opzioni in `menuconfig`.

2. Compilare e flashare:

```shell
idf.py flash monitor
```

> [!NOTE]
> Per entrare in modalità download: tenere premuto il tasto di reset (circa 2 secondi) finché il LED verde interno non lampeggia velocemente, quindi rilasciare.

## Log

@2025/05/17 Problemi riscontrati nei test

1. `listening...` impiega alcuni secondi prima che venga acquisito l'input vocale
2. Regolazione della luminosità non corretta
3. Regolazione del volume non corretta
