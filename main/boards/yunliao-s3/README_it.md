# XiaoZhi Yunliao S3

## Introduzione

XiaoZhi Yunliao S3 è una versione modificata del progetto XiaoZhi AI con display IPS 2.8", caratteri grandi e batteria da 2000 mAh; include molte ottimizzazioni e funzionalità (wake‑word, interruzione vocale, OTA, cambio 4G/Wi‑Fi, ecc.).

## Operazioni con il pulsante
- **Accensione**: da spento, tenere premuto il pulsante 1s e rilasciare per accendere.
- **Spegnimento**: da acceso, tenere premuto 1s e rilasciare; attendere il messaggio "请稍候" e lo spegnimento automatico.
- **Risveglio/Interruzione**: clic singolo durante una sessione.
- **Switch 4G/Wi‑Fi**: doppio clic entro 1s durante l'avvio o nella schermata di configurazione (richiede modulo 4G).
- **Cambio modalità AEC/Interruzione vocale**: doppio clic in standby per ciclare le modalità.
- **Reset rete (reconfigurazione)**: tre clic veloci entro 1s per riavviare e entrare in modalità di configurazione Wi‑Fi.

## Compilazione

Clonare e entrare nel progetto:

```bash
git clone https://github.com/78/xiaozhi-esp32.git
cd xiaozhi-esp32
```

Impostare il target su ESP32S3 e aprire `menuconfig`:

```bash
idf.py set-target esp32s3
idf.py menuconfig
```

Selezionare la board:

```text
Xiaozhi Assistant -> Board Type -> 小智云聊-S3  (Enable Device-Side AEC)
```

Compilare:

```bash
idf.py build
```

Per flash e monitor dei log:

```bash
idf.py build flash monitor
```
