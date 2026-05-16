# Un chatbot basato su MCP

(Italiano | [中文](README_zh.md) | [English](README.md) | [日本語](README_ja.md))

## Introduzione

👉 [Umano: installare una telecamera sull'AI vs AI: scopre che il proprietario non si lava i capelli da tre giorni【bilibili】](https://www.bilibili.com/video/BV1bpjgzKEhd/)

👉 [Costruire la tua AI girlfriend manualmente, tutorial per principianti【bilibili】](https://www.bilibili.com/video/BV1XnmFYLEJN/)

Xiaozhi AI chatbot funge da interfaccia di interazione vocale: sfrutta le capacità di grandi modelli come Qwen / DeepSeek e utilizza il protocollo MCP per controllo multi-end.

<img src="docs/mcp-based-graph.jpg" alt="Controllo tramite MCP" width="320">

### Note sulla versione

La versione attuale v2 non è compatibile con la tabella delle partizioni della versione v1, quindi non è possibile aggiornare da v1 a v2 tramite OTA. Per i dettagli sulla tabella delle partizioni, vedere [partitions/v2/README.md](partitions/v2/README.md).

Tutti gli hardware compatibili con la versione v1 possono essere aggiornati a v2 eseguendo il flashing manuale del firmware.

La versione stabile di v1 è la 1.9.2; per passare a v1 eseguire `git checkout v1`. Questo ramo sarà mantenuto fino a febbraio 2026.

### Funzionalità implementate

- Wi‑Fi / ML307 Cat.1 4G
- Wake‑word vocale offline ([ESP-SR](https://github.com/espressif/esp-sr))
- Supporto per due protocolli di comunicazione ([Websocket](docs/websocket_zh.md) o MQTT+UDP)
- Codec audio OPUS
- Interazione vocale basata su ASR in streaming + LLM + TTS
- Riconoscimento dello speaker (voiceprint) [3D Speaker](https://github.com/modelscope/3D-Speaker)
- Display OLED / LCD con supporto per emoji
- Visualizzazione della carica e gestione dell'alimentazione
- Supporto multilingue (cinese, inglese, giapponese)
- Supporto per piattaforme ESP32‑C3, ESP32‑S3, ESP32‑P4
- Controllo del dispositivo tramite MCP lato dispositivo (volume, luci, motori, GPIO, ecc.)
- Estensione delle capacità LLM via MCP lato cloud (domotica, controllo desktop, ricerca, email, ecc.)
- Personalizzazione di wakeword, font, emoji e sfondi di chat; modifica online via web ([strumento generator di assets](https://github.com/78/xiaozhi-assets-generator))

## Hardware

### Pratica su breadboard

Vedi la guida su Feishu:

👉 [«Enciclopedia del chatbot AI Xiaozhi»](https://ccnphfhqs21z.feishu.cn/wiki/F5krwD16viZoF0kKkvDcrZNYnhb?from=from_copylink)

Esempio di assemblaggio su breadboard:

![Esempio breadboard](docs/v1/wiring2.jpg)

### Supporto per oltre 70 hardware open‑source (solo alcuni esempi)

- <a href="https://oshwhub.com/li-chuang-kai-fa-ban/li-chuang-shi-zhan-pai-esp32-s3-kai-fa-ban" target="_blank" title="立创·实战派 ESP32-S3 开发板">立创·实战派 ESP32-S3 开发板</a>
- <a href="https://github.com/espressif/esp-box" target="_blank" title="乐鑫 ESP32-S3-BOX3">乐鑫 ESP32-S3-BOX3</a>
- <a href="https://docs.m5stack.com/zh_CN/core/CoreS3" target="_blank" title="M5Stack CoreS3">M5Stack CoreS3</a>
- <a href="https://docs.m5stack.com/en/atom/Atomic%20Echo%20Base" target="_blank" title="AtomS3R + Echo Base">M5Stack AtomS3R + Echo Base</a>
- <a href="https://gf.bilibili.com/item/detail/1108782064" target="_blank" title="神奇按钮 2.4">神奇按钮 2.4</a>
- <a href="https://www.waveshare.net/shop/ESP32-S3-Touch-AMOLED-1.8.htm" target="_blank" title="微雪电子 ESP32-S3-Touch-AMOLED-1.8">微雪电子 ESP32-S3-Touch-AMOLED-1.8</a>
- <a href="https://github.com/Xinyuan-LilyGO/T-Circle-S3" target="_blank" title="LILYGO T-Circle-S3">LILYGO T-Circle-S3</a>
- <a href="https://oshwhub.com/tenclass01/xmini_c3" target="_blank" title="虾哥 Mini C3">虾哥 Mini C3</a>
- <a href="https://oshwhub.com/movecall/cuican-ai-pendant-lights-up-y" target="_blank" title="Movecall CuiCan ESP32S3">璀璨·AI 吊坠</a>
- <a href="https://github.com/WMnologo/xingzhi-ai" target="_blank" title="无名科技Nologo-星智-1.54">无名科技 Nologo-星智-1.54TFT</a>
- <a href="https://www.seeedstudio.com/SenseCAP-Watcher-W1-A-p-5979.html" target="_blank" title="SenseCAP Watcher">SenseCAP Watcher</a>
- <a href="https://www.bilibili.com/video/BV1BHJtz6E2S/" target="_blank" title="ESP-HI 超低成本机器狗">ESP-HI 超低成本机器狗</a>

<div style="display: flex; justify-content: space-between;">
  <a href="docs/v1/lichuang-s3.jpg" target="_blank" title="立创·实战派 ESP32-S3 开发板">
    <img src="docs/v1/lichuang-s3.jpg" width="240" />
  </a>
  <a href="docs/v1/espbox3.jpg" target="_blank" title="乐鑫 ESP32-S3-BOX3">
    <img src="docs/v1/espbox3.jpg" width="240" />
  </a>
  <a href="docs/v1/m5cores3.jpg" target="_blank" title="M5Stack CoreS3">
    <img src="docs/v1/m5cores3.jpg" width="240" />
  </a>
  <a href="docs/v1/atoms3r.jpg" target="_blank" title="AtomS3R + Echo Base">
    <img src="docs/v1/atoms3r.jpg" width="240" />
  </a>
  <a href="docs/v1/magiclick.jpg" target="_blank" title="神奇按钮 2.4">
    <img src="docs/v1/magiclick.jpg" width="240" />
  </a>
  <a href="docs/v1/waveshare.jpg" target="_blank" title="微雪电子 ESP32-S3-Touch-AMOLED-1.8">
    <img src="docs/v1/waveshare.jpg" width="240" />
  </a>
  <a href="docs/v1/lilygo-t-circle-s3.jpg" target="_blank" title="LILYGO T-Circle-S3">
    <img src="docs/v1/lilygo-t-circle-s3.jpg" width="240" />
  </a>
  <a href="docs/v1/xmini-c3.jpg" target="_blank" title="虾哥 Mini C3">
    <img src="docs/v1/xmini-c3.jpg" width="240" />
  </a>
  <a href="docs/v1/movecall-cuican-esp32s3.jpg" target="_blank" title="CuiCan">
    <img src="docs/v1/movecall-cuican-esp32s3.jpg" width="240" />
  </a>
  <a href="docs/v1/wmnologo_xingzhi_1.54.jpg" target="_blank" title="无名科技Nologo-星智-1.54">
    <img src="docs/v1/wmnologo_xingzhi_1.54.jpg" width="240" />
  </a>
  <a href="docs/v1/sensecap_watcher.jpg" target="_blank" title="SenseCAP Watcher">
    <img src="docs/v1/sensecap_watcher.jpg" width="240" />
  </a>
  <a href="docs/v1/esp-hi.jpg" target="_blank" title="ESP-HI 超低成本机器狗">
    <img src="docs/v1/esp-hi.jpg" width="240" />
  </a>
</div>

## Software

### Flash del firmware

Per i principianti si consiglia di non configurare un ambiente di sviluppo: usare il firmware pronto da flashare.

Il firmware si collega per impostazione predefinita al server ufficiale `xiaozhi.me`; gli utenti registrati possono utilizzare gratuitamente il modello Qwen in tempo reale.

👉 [Guida al flashing per principianti](https://ccnphfhqs21z.feishu.cn/wiki/Zpz4wXBtdimBrLk25WdcXzxcnNS)

### Ambiente di sviluppo

- Cursor o VSCode
- Installa il plugin ESP‑IDF e scegli SDK versione 5.4 o superiore
- Linux è preferibile a Windows: compilazione più rapida e meno problemi con i driver
- Il progetto usa lo stile Google C++: assicurati che il codice rispetti le regole prima di inviare PR

### Documentazione per sviluppatori

- [Guida per creare schede personalizzate](docs/custom-board_zh.md)
- [Uso del protocollo MCP per il controllo IoT](docs/mcp-usage_zh.md)
- [Flusso del protocollo MCP](docs/mcp-protocol_zh.md)
- [Documento sul protocollo MQTT + UDP](docs/mqtt-udp_zh.md)
- [Documento dettagliato sul protocollo WebSocket](docs/websocket_zh.md)

## Configurazione dei modelli

Se hai un dispositivo Xiaozhi connesso al server ufficiale, puoi configurarlo dal pannello di controllo su `xiaozhi.me`.

👉 [Video tutorial per il backend (interfaccia legacy)](https://www.bilibili.com/video/BV1jUCUY2EKM/)

## Progetti open‑source correlati

Se vuoi distribuire il server sul tuo PC, puoi consultare i seguenti progetti:

- [xinnan-tech/xiaozhi-esp32-server](https://github.com/xinnan-tech/xiaozhi-esp32-server) — server Python
- [joey-zhou/xiaozhi-esp32-server-java](https://github.com/joey-zhou/xiaozhi-esp32-server-java) — server Java
- [AnimeAIChat/xiaozhi-server-go](https://github.com/AnimeAIChat/xiaozhi-server-go) — server Golang
- [hackers365/xiaozhi-esp32-server-golang](https://github.com/hackers365/xiaozhi-esp32-server-golang) — server Golang

Client di terze parti che usano il protocollo Xiaozhi:

- [huangjunsen0406/py-xiaozhi](https://github.com/huangjunsen0406/py-xiaozhi) — client Python
- [TOM88812/xiaozhi-android-client](https://github.com/TOM88812/xiaozhi-android-client) — client Android
- [100askTeam/xiaozhi-linux](http://github.com/100askTeam/xiaozhi-linux)
- [78/xiaozhi-sf32](https://github.com/78/xiaozhi-sf32)
- [QuecPython/solution-xiaozhiAI](https://github.com/QuecPython/solution-xiaozhiAI)

## Informazioni sul progetto

Progetto open source pubblicato da 虾哥 (Xiaoge) sotto licenza MIT: libero per uso, modifica e scopi commerciali.

L'obiettivo è aiutare a comprendere lo sviluppo hardware AI e applicare i grandi modelli al mondo reale.

Per suggerimenti o idee, apri una Issue o unisciti al canale Discord: https://discord.gg/C759fGMBcZ o al gruppo QQ: 1011329060

## Star History

<a href="https://star-history.com/#78/xiaozhi-esp32&Date">
 <picture>
   <source media="(prefers-color-scheme: dark)" srcset="https://api.star-history.com/svg?repos=78/xiaozhi-esp32&type=Date&theme=dark" />
   <source media="(prefers-color-scheme: light)" srcset="https://api.star-history.com/svg?repos=78/xiaozhi-esp32&type=Date" />
   <img alt="Star History Chart" src="https://api.star-history.com/svg?repos=78/xiaozhi-esp32&type=Date" />
 </picture>
</a>
