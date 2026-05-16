# Zhengchen AI Camera

## Introduzione

Zhengchen AI Camera è una versione modificata del progetto XiaoZhi AI, con ottimizzazioni e funzionalità aggiuntive. Il codice è disponibile sia in una versione "integrata" sincronizzata con il progetto principale, sia in una versione fork con modifiche più invasive.

## Compilazione

Si consiglia di utilizzare lo script di rilascio per impostare automaticamente le opzioni `sdkconfig`:

```bash
python ./scripts/release.py zhengchen-cam
```

Per compilare manualmente, fare riferimento a `zhengchen-cam/config.json` e adattare le opzioni in `idf.py menuconfig`.

## Flash

```bash
idf.py flash
```

## Note sul controllo (MCP)

Esempi di comandi MCP esposti:
- `self.get_device_status`
- `self.audio_speaker.set_volume`
- `self.screen.set_brightness`
- `self.camera.take_photo`
