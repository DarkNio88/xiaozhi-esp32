# Guida per sviluppare una scheda personalizzata

Questa guida spiega come creare un nuovo driver di board (initialization) per il progetto Xiaozhi AI. Xiaozhi supporta oltre 70 schede della famiglia ESP32; il codice di inizializzazione di ciascuna scheda è collocato nella rispettiva cartella sotto `main/boards/`.

## Avvertenza importante

> **Attenzione**: per le schede personalizzate, se la mappatura degli IO differisce da una board esistente, non sovrascrivere la configurazione di una board già presente. È necessario creare una nuova voce board o usare il file `config.json` con build separati (campo `builds`) per distinguere `name` e macro `sdkconfig`. Per compilare e creare il pacchetto firmware usare `python scripts/release.py [nome_cartella_board]`.
>
> Se sovrascrivete una board esistente, un successivo aggiornamento OTA potrebbe riportare la board allo stato standard e sovrascrivere la vostra personalizzazione, rendendo il dispositivo non funzionante. Ogni board ha un identificativo e un canale di aggiornamento propri; mantenete quindi l'identificativo unico.

## Struttura della directory

Una tipica cartella di board contiene:

- `xxx_board.cc` — codice di inizializzazione specifico della board
- `config.h` — definizioni dei pin e impostazioni hardware
- `config.json` — configurazione di build usata da `scripts/release.py`
- `README.md` — documentazione della board

## Passi per creare una board personalizzata

### 1. Creare la cartella della board

Esempio:

```bash
mkdir main/boards/my-custom-board
```

### 2. Definire i file di configurazione

#### `config.h`

Definire in `config.h` tutte le configurazioni hardware: sample rate audio, pin I2S, indirizzo codec I2C, pin pulsanti e LED, parametri display, ecc. Esempio tratto dalla board `lichuang-c3-dev` (omesso qui per brevità — conservare i blocchi di esempio presenti nel file originale).

#### `config.json`

Usato dallo script `release.py` per automatizzare la compilazione:

```json
{
    "target": "esp32s3",
    "builds": [
        {
            "name": "my-custom-board",
            "sdkconfig_append": [
                "CONFIG_ESPTOOLPY_FLASHSIZE_8MB=y",
                "CONFIG_PARTITION_TABLE_CUSTOM_FILENAME=\"partitions/v2/8m.csv\""
            ]
        }
    ]
}
```

Spiegazione:
- `target`: chip target (esp32, esp32s3, esp32c3, esp32c6, esp32p4, ...)
- `name`: nome del pacchetto firmware (consigliato uguale al nome della cartella)
- `sdkconfig_append`: array di opzioni `sdkconfig` da aggiungere

Esempi di `sdkconfig_append`: impostazione flash e partizionamento, lingua, opzioni wake-word e AEC.

### 3. Scrivere il codice di inizializzazione della board

Creare `my_custom_board.cc` implementando la classe derivata da `WifiBoard` o `Ml307Board` e sovrascrivendo i metodi necessari (`GetAudioCodec()`, `GetDisplay()`, `GetBacklight()`, ecc.). Includere l'inizializzazione di I2C, SPI, pulsanti, display e registrare la board con `DECLARE_BOARD(MyCustomBoard);`.

Esempio riassuntivo (vedere il file originale per l'implementazione completa):

- Inizializzare I2C per il codec audio
- Inizializzare SPI per il display
- Configurare i pulsanti con callback
- Creare oggetto `SpiLcdDisplay` per il pannello e impostare parametri come mirror/swap
- Inizializzare gli strumenti MCP se necessari

### 4. Aggiungere la board a Kconfig.projbuild

Aprire `main/Kconfig.projbuild` e aggiungere una voce nel `choice BOARD_TYPE`, es.:

```kconfig
config BOARD_TYPE_MY_CUSTOM_BOARD
    bool "My Custom Board (我的自定义开发板)"
    depends on IDF_TARGET_ESP32S3
```

Note:
- Il nome della opzione in Kconfig deve essere tutto maiuscolo e usare underscore
- `depends on` limita la scelta al target CPU corretto

### 5. Aggiornare `CMakeLists.txt`

Nella sezione che valuta `CONFIG_BOARD_TYPE_*` aggiungere il mapping:

```cmake
elseif(CONFIG_BOARD_TYPE_MY_CUSTOM_BOARD)
    set(BOARD_TYPE "my-custom-board")
    set(BUILTIN_TEXT_FONT font_puhui_basic_20_4)
    set(BUILTIN_ICON_FONT font_awesome_20_4)
    set(DEFAULT_EMOJI_COLLECTION twemoji_64)
endif()
```

Regole per tipologia font e risoluzioni:
- OLED 128x64 → `font_puhui_basic_14_1`
- 240x240 → `font_puhui_basic_16_4`
- 240x320 → `font_puhui_basic_20_4`
- grandi schermi → `font_puhui_basic_30_4`

Collezioni emoji: `twemoji_32`, `twemoji_64`.

### 6. Compilare

Metodo manuale (idf.py):

```bash
# impostare target
idf.py set-target esp32s3
idf.py fullclean
idf.py menuconfig   # scegliere la board sotto Xiaozhi Assistant -> Board Type
idf.py build
idf.py flash monitor
```

Metodo automatico (consigliato) con `scripts/release.py`:

```bash
python scripts/release.py my-custom-board
```

Lo script applicherà le opzioni di `config.json`, compilerà e impacchetterà il firmware.

### 7. Creare `README.md`

Descrivere caratteristiche hardware, requisiti, istruzioni di compilazione e flashing.

## Componenti comuni delle board

### Display

Il progetto supporta vari controller display, ad esempio ST7789 (SPI), ecc. Consultare gli esempi e le implementazioni presenti nel repository.
