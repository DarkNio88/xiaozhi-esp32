# Zhengchen AI Camera (ML307)

## Introduzione

Zhengchen AI Camera è un progetto modificato di XiaoZhi AI con numerose ottimizzazioni e funzionalità aggiuntive (wake‑word, interruzione vocale, OTA, ecc.). Esiste una versione integrata seguita direttamente dal progetto principale e una versione "magica" (fork) mantenuta separatamente per grandi modifiche hardware.

## Compilazione

Si consiglia lo script di rilascio per impostare automaticamente le opzioni `sdkconfig`:

```bash
python ./scripts/release.py zhengchen-cam-ml307
```

Per compilare manualmente, adattare le opzioni in `idf.py menuconfig` seguendo `zhengchen-cam-ml307/config.json`.

## Flash

```bash
idf.py flash
```

## Note sul controllo via MCP

Funzioni esposte (esempi):
- `self.get_device_status`
- `self.audio_speaker.set_volume`
- `self.screen.set_brightness`
- `self.camera.take_photo`
- `self.AEC.set_mode`
