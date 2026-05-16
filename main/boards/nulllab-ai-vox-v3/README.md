# NULLLAB-AI-VOX3

## Panoramica

AI-VOX3 è la versione aggiornata di AI VOX: una scheda di sviluppo embedded ad alte prestazioni progettata per applicazioni di interazione vocale. È basata sul chip ESP32-S3-R8 e dispone di 16 MB di memoria Flash a bordo. Integra numerose risorse hardware per consentire uno sviluppo rapido e un'ampia espandibilità. Riunisce più funzioni in un unico dispositivo (chat AI / orologio meteo / interfono wireless / lettore MP3 / radio internet), supporta wake-word locale, riconoscimento dei comandi vocali e sintesi vocale, ed è adatta per applicazioni in domotica, dispositivi didattici e terminali IoT. Il PCB è compatibile con i perni LEGO e può essere montato su blocchi di tipo C per progetti DIY; è disponibile una scheda di espansione AI-VOX3 e la scheda driver MD40 per il controllo dei motori, che facilitano la prototipazione rapida e l'estensione delle funzionalità tramite le numerose interfacce, riducendo i tempi di sviluppo.

## Caratteristiche

- Basata su ESP32-S3R8: processore Xtensa LX7 dual-core a 32 bit, fino a 240 MHz
- Supporta Wi‑Fi 2.4 GHz (802.11 b/g/n) e Bluetooth 5 (LE) con antenna integrata
- Il chip ESP32-S3R8 integra 512 KB di SRAM e 384 KB di ROM; la scheda dispone di 8 MB di PSRAM e 16 MB di memoria Flash
- Connettore Type-C per programmazione, alimentazione e ricarica della batteria; compatibile con ambienti di sviluppo comuni
- Tasto Power che unisce reset e accensione: breve pressione per accensione o reset, pressione prolungata per spegnimento
- Supporto per display SPI ST7789 1.54" 240×240 per interazione grafica
- Predisposizione per connettore LCD e porta OLED, è possibile scegliere tra LCD o OLED
- Codec audio ES8311 integrato e amplificatore audio 3W (NS4150B); richiede altoparlante esterno per l'audio
- Design a doppio microfono: microfono analogico onboard con possibilità di microfono esterno e supporto per single-mic interrupt
- Slot per scheda SD per espansione di memoria
- Pulsante BOOT, 2 pulsanti (GPIO46/45) e LED WS2812B per debugging e indicazione di stato
- Header a 8 pin per GPIO (GPIO43/44/42/48/4/3/2/1) per collegamento di periferiche
- Connettore PH2.0 a 4 pin per alimentazione o comunicazione con altri controller
- Scheda di espansione AI-VOX3 disponibile per funzionalità aggiuntive
- Scheda driver MD40 disponibile per pilotare più motori
- Circuito integrato di ricarica e boost 5V 2.4A; supporto per batteria Li-ion e monitoraggio batteria tramite ADC IO18
- Supporta ESP-IDF, Arduino IDE e AilyBlockly

## Descrizione tasto Power

AI-VOX3 ha rimosso il tradizionale tasto Reset in favore di un unico tasto Power che gestisce le operazioni principali: una breve pressione accende o esegue il reset del sistema, una pressione prolungata spegne il dispositivo.
