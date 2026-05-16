# Uso del protocollo MCP per il controllo IoT

Questo documento descrive come usare il protocollo MCP (Model Context Protocol) per il controllo IoT di dispositivi ESP32. Per i dettagli del protocollo vedere anche `mcp-protocol_zh.md`.

## Introduzione

MCP è il protocollo consigliato per il controllo IoT: usa JSON‑RPC 2.0 per esporre e invocare "tool" (strumenti) che permettono al backend di scoprire e comandare le funzionalità del dispositivo.

## Flusso tipico

1. Il dispositivo si connette al backend tramite WebSocket/MQTT.
2. Il backend inizializza la sessione con il metodo MCP `initialize`.
3. Il backend chiama `tools/list` per ottenere la lista dei tool supportati dal dispositivo.
4. Il backend invoca `tools/call` per eseguire tool specifici e comandare il dispositivo.

Per i formati e i dettagli delle interazioni consultare `mcp-protocol_zh.md`.

## Registrare tool sul dispositivo

Sul dispositivo i tool vengono registrati tramite `McpServer::AddTool`. Firma tipica:

```cpp
void AddTool(
    const std::string& name,           // nome univoco del tool, es. self.dog.forward
    const std::string& description,    // descrizione naturale per il modello/utente
    const PropertyList& properties,    // lista di parametri (bool/int/string)
    std::function<ReturnValue(const PropertyList&)> callback // callback di esecuzione
);
```

- `name`: identificativo unico, preferibile usare nomenclatura a punti (modulo.funzione)
- `description`: descrizione in linguaggio naturale
- `properties`: parametri con tipi, range e valori di default
- `callback`: logica eseguita al ricevimento della chiamata; può restituire bool/int/string

## Esempio di registrazione

```cpp
void InitializeTools() {
    auto& mcp_server = McpServer::GetInstance();
    // esempio 1: senza parametri
    mcp_server.AddTool("self.dog.forward", "Muove il robot in avanti", PropertyList(), [this](const PropertyList&) -> ReturnValue {
        servo_dog_ctrl_send(DOG_STATE_FORWARD, NULL);
        return true;
    });

    // esempio 2: impostare colore RGB
    mcp_server.AddTool("self.light.set_rgb", "Imposta colore RGB", PropertyList({
        Property("r", kPropertyTypeInteger, 0, 255),
        Property("g", kPropertyTypeInteger, 0, 255),
        Property("b", kPropertyTypeInteger, 0, 255)
    }), [this](const PropertyList& properties) -> ReturnValue {
        int r = properties["r"].value<int>();
        int g = properties["g"].value<int>();
        int b = properties["b"].value<int>();
        led_on_ = true;
        SetLedColor(r, g, b);
        return true;
    });
}
```

## Esempi di chiamate JSON‑RPC

1. **Ottenere la lista dei tool**
```json
{
  "jsonrpc": "2.0",
  "method": "tools/list",
  "params": { "cursor": "" },
  "id": 1
}
```

2. **Comando per muovere il telaio in avanti**
```json
{
  "jsonrpc": "2.0",
  "method": "tools/call",
  "params": { "name": "self.chassis.go_forward", "arguments": {} },
  "id": 2
}
```

3. **Cambiare modalità luci**
```json
{
  "jsonrpc": "2.0",
  "method": "tools/call",
  "params": { "name": "self.chassis.switch_light_mode", "arguments": { "light_mode": 3 } },
  "id": 3
}
```

4. **Invertire la telecamera**
```json
{
  "jsonrpc": "2.0",
  "method": "tools/call",
  "params": { "name": "self.camera.set_camera_flipped", "arguments": {} },
  "id": 4
}
```

## Note finali

- I nomi, i parametri e i valori di ritorno devono corrispondere a quanto registrato con `AddTool` sul dispositivo.  
- Si raccomanda di adottare MCP per nuovi progetti IoT.  
- Per il protocollo completo e gli scenari avanzati vedere `mcp-protocol_zh.md`.
