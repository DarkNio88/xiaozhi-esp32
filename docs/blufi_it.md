# BluFi provisioning (integrazione con esp-wifi-connect)

Questo documento spiega come abilitare e utilizzare BluFi (provisioning Wi‑Fi via BLE) nel firmware Xiaozhi e come integrare il componente `esp-wifi-connect` del progetto per la connessione e la memorizzazione delle credenziali Wi‑Fi. Per il protocollo BluFi fare riferimento alla documentazione ufficiale Espressif: https://docs.espressif.com/projects/esp-idf/zh_CN/stable/esp32/api-guides/ble/blufi.html

## Prerequisiti

- Chip e configurazione firmware devono supportare il BLE.
- In `idf.py menuconfig` abilitare `WiFi Configuration Method -> Esp Blufi` (`CONFIG_USE_ESP_BLUFI_WIFI_PROVISIONING=y`). Se si vuole usare BluFi, disabilitare l'opzione Hotspot nello stesso menu; altrimenti il provisioning predefinito sarà Hotspot.
- Mantenere l'inizializzazione predefinita di NVS e del loop degli eventi (il progetto gestisce questo in `app_main`).
- Abilitare solo una delle macro `CONFIG_BT_BLUEDROID_ENABLED` o `CONFIG_BT_NIMBLE_ENABLED`; non entrambe.

## Flusso di lavoro

1) Il client mobile si connette al dispositivo tramite BluFi (ad esempio l'app ufficiale EspBlufi o un client personalizzato) e invia SSID/password; il client può ottenere la lista delle reti scansionate dal dispositivo tramite il protocollo BluFi.
2) Sul dispositivo, nell'evento `ESP_BLUFI_EVENT_REQ_CONNECT_TO_AP`, le credenziali vengono scritte in `SsidManager` (salvate in NVS, gestite dal componente `esp-wifi-connect`).
3) Successivamente viene avviato `WifiStation` per scansionare e connettersi; lo stato viene restituito tramite BluFi.
4) Se il provisioning ha successo, il dispositivo si connette automaticamente alla nuova rete; in caso di fallimento viene restituito lo stato di errore.

## Procedura d'uso

1. Configurazione: abilitare `Esp Blufi` in `menuconfig`. Compilare e flashare il firmware.
2. Innesco del provisioning: al primo avvio, se non sono presenti credenziali Wi‑Fi salvate, il dispositivo entrerà automaticamente in modalità provisioning.
3. Operazioni lato mobile: aprire EspBlufi App (o altro client BluFi), cercare e connettersi al dispositivo; scegliere se utilizzare cifratura, quindi inserire SSID/password e inviare.
4. Osservare il risultato:
   - Successo: BluFi segnala connessione riuscita e il dispositivo si connette automaticamente alla rete.
   - Fallimento: BluFi riporta lo stato di errore; riprovare o controllare il router.

## Note

- BluFi e Hotspot provisioning non possono essere attivati contemporaneamente. Se Hotspot è attivo, il provisioning predefinito sarà Hotspot. Mantenere una sola modalità in `menuconfig`.
- Per test ripetuti, è consigliabile cancellare o sovrascrivere gli SSID memorizzati (namespace `wifi`) per evitare interferenze di configurazioni precedenti.
- Se si utilizza un client BluFi personalizzato, attenersi al formato dei frame del protocollo ufficiale (vedere la documentazione Espressif).
- La documentazione ufficiale include il link per scaricare l'app EspBlufi.
- A causa di modifiche nell'API BluFi in IDF 5.5.2, nelle build con 5.5.2 il nome Bluetooth sarà "Xiaozhi-Blufi", mentre con 5.5.1 era "BLUFI_DEVICE".
