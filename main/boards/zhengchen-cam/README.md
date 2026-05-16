# Siti web correlati al prodotto

## Introduzione
La AI camera di Zhengchen Technology è una versione modificata del progetto Xiaozhi AI, con numerose innovazioni e ottimizzazioni.

## Versione integrata (merge)
Il codice della versione integrata è mantenuto all'interno del progetto principale Xiaozhi AI e segue gli aggiornamenti di versione del progetto, facilitando l'estensione da parte degli utenti e l'integrazione di firmware di terze parti. Supporta wake word, interruzione vocale, OTA e altre funzionalità.

## Versione modificata (mod)
La versione modificata (mod) include cambiamenti di basso livello significativi; il codice è mantenuto separatamente e viene periodicamente unito al progetto principale.

Prodotti correlati:
https://e.tb.cn/h.6Gl2LC7rsrswQZp?tk=qFuaV9hzh0k CZ356

```
[Taobao] "Xiaozhi AI con fotocamera, supporto riconoscimento oggetti, doppio microfono con interruzione - scheda di sviluppo ESP32S3N16R8 (pacchetto emoticon)"
https://e.tb.cn/h.hBc8Gcx9cUluJJO?tk=YW5C4LPixKg

```

## Comandi di configurazione e compilazione

Poiché questo progetto richiede la configurazione di numerose opzioni di `sdkconfig`, si consiglia di utilizzare lo script di compilazione.

**Compilazione**

```bash
python ./scripts/release.py zhengchen-cam
```

Per compilazione manuale, consultare `zhengchen-cam/config.json` per modificare le opzioni corrispondenti in `menuconfig`.

**Flash**

```bash
idf.py flash


```

Comandi MCP:
self.get_device_status
self.audio_speaker.set_volume
self.screen.set_brightness
self.screen.set_theme
self.gif.set_gif_mode
self.display.set_mode
self.camera.take_photo
self.AEC.set_mode
self.AEC.get_mode
self.res.esp_restart