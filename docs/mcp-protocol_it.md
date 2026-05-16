# MCP (Model Context Protocol) — Flusso di interazione

AVVISO: la documentazione è stata generata con supporto AI; durante l'implementazione del backend verificare i dettagli direttamente nel codice.

Nel progetto MCP viene usato per la comunicazione tra il backend (client MCP) e il dispositivo ESP32 (server MCP), permettendo al backend di scoprire e invocare le funzionalità (tool) esposte dal dispositivo.

## Formato del protocollo

Secondo il codice (`main/protocols/protocol.cc`, `main/mcp_server.cc`), i messaggi MCP sono incapsulati nel payload del protocollo di trasporto (WebSocket o MQTT). La struttura interna segue la specifica JSON‑RPC 2.0.

Esempio di messaggio complessivo:

```json
{
  "session_id": "...",
  "type": "mcp",
  "payload": {
    "jsonrpc": "2.0",
    "method": "...",
    "params": { ... },
    "id": ..., 
    "result": { ... },
    "error": { ... }
  }
}
```

La parte `payload` è un tipico messaggio JSON‑RPC 2.0:

- `jsonrpc`: stringa fissa "2.0"  
- `method`: nome del metodo (request)  
- `params`: parametri della chiamata (oggetto)  
- `id`: identificativo della richiesta (per correlare request/response)  
- `result`: risultato in caso di successo  
- `error`: dettagli dell'errore in caso di fallimento

## Flusso di interazione e tempistiche

Lo scopo principale di MCP è consentire al backend di scoprire ed eseguire i tool forniti dal dispositivo.

1. **Connessione e annuncio capacità**

   - Quando il dispositivo si connette al backend, invia un messaggio `hello` (transport layer) che può includere le capacità, ad esempio `"mcp": true`.

   - Esempio (messaggio di livello base, non payload MCP):

   ```json
   {
     "type": "hello",
     "version": ..., 
     "features": { "mcp": true, ... },
     "transport": "websocket",
     "audio_params": { ... },
     "session_id": "..."
   }
   ```

2. **Initialize (inizializzazione MCP)**

   - In genere il backend invia `initialize` dopo aver rilevato che il dispositivo supporta MCP.
   - Esempio richiesta MCP (`initialize`):

   ```json
   {
     "jsonrpc": "2.0",
     "method": "initialize",
     "params": {
       "capabilities": {
         "vision": { "url": "...", "token": "..." }
       }
     },
     "id": 1
   }
   ```

   - Risposta dispositivo:

   ```json
   {
     "jsonrpc": "2.0",
     "id": 1,
     "result": {
       "protocolVersion": "2024-11-05",
       "capabilities": { "tools": {} },
       "serverInfo": { "name": "...", "version": "..." }
     }
   }
   ```

3. **Scoperta dei tool (`tools/list`)**

   - Il backend richiede la lista dei tool supportati dal dispositivo usando `tools/list` (supporta paginazione con `cursor`).

   - Richiesta:
   ```json
   { "jsonrpc": "2.0", "method": "tools/list", "params": { "cursor": "" }, "id": 2 }
   ```

   - Risposta (esempio):
   ```json
   {
     "jsonrpc": "2.0",
     "id": 2,
     "result": {
       "tools": [
         { "name": "self.get_device_status", "description": "...", "inputSchema": { ... } },
         { "name": "self.audio_speaker.set_volume", "description": "...", "inputSchema": { ... } }
       ],
       "nextCursor": "..."
     }
   }
   ```

   - Se `nextCursor` non è vuoto il client invia nuovamente `tools/list` passando quel cursor.

4. **Chiamare un tool (`tools/call`)**

   - Quando il backend deve eseguire una funzione sul dispositivo invia `tools/call`:
   ```json
   {
     "jsonrpc": "2.0",
     "method": "tools/call",
     "params": { "name": "self.audio_speaker.set_volume", "arguments": { "volume": 50 } },
     "id": 3
   }
   ```

   - Risposta in caso di successo:
   ```json
   {
     "jsonrpc": "2.0",
     "id": 3,
     "result": { "content": [{ "type": "text", "text": "true" }], "isError": false }
   }
   ```

   - Risposta in caso di errore:
   ```json
   { "jsonrpc": "2.0", "id": 3, "error": { "code": -32601, "message": "Unknown tool: self.non_existent_tool" } }
   ```

5. **Notifiche inviate dal dispositivo (Notification)**

   - Il dispositivo può inviare notifiche spontanee (senza `id`) per informare il backend di eventi interni (es. stato cambiato). Esempio:

   ```json
   { "jsonrpc": "2.0", "method": "notifications/state_changed", "params": { "newState": "idle", "oldState": "connecting" } }
   ```

   - Il backend riceve la notifica e la gestisce senza inviare risposta.

## Diagramma di interazione

Il diagramma di sequenza (semplificato) mostra le principali fasi: Hello → Initialize → tools/list → tools/call → response/notification.

## Note finali

Questa panoramica copre il flusso MCP usato nel progetto. Per i dettagli implementativi consultare `main/mcp_server.cc` (es. `McpServer::AddCommonTools`) e le implementazioni dei singoli tool.
