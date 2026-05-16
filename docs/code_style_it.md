# Guida allo stile del codice

## Strumenti di formattazione

Il progetto utilizza `clang-format` per uniformare lo stile del codice. Nel repository è presente il file `.clang-format` basato sullo stile Google C++ con alcune personalizzazioni.

### Installazione di `clang-format`

- **Windows**:
  ```powershell
  winget install LLVM
  # oppure
  choco install llvm
  ```

- **Linux**:
  ```bash
  sudo apt install clang-format  # Ubuntu/Debian
  sudo dnf install clang-tools-extra  # Fedora
  ```

- **macOS**:
  ```bash
  brew install clang-format
  ```

### Uso

1. **Formattare un singolo file**:
   ```bash
   clang-format -i path/to/your/file.cpp
   ```

2. **Formattare l'intero progetto**:
   ```bash
   # dalla root del progetto
   find main -iname "*.h" -o -iname "*.cc" | xargs clang-format -i
   ```

3. **Controllare il formato prima del commit** (senza modificare i file):
   ```bash
   clang-format --dry-run -Werror path/to/your/file.cpp
   ```

### Integrazione con l'IDE

- **Visual Studio Code**:
  1. Installa l'estensione C/C++
  2. Imposta `C_Cpp.formatting` su `clang-format`
  3. Per formattare automaticamente al salvataggio: `editor.formatOnSave: true`

- **CLion**:
  1. Vai in `Editor > Code Style > C/C++`
  2. Seleziona `clang-format` come formatter
  3. Configura per usare il `.clang-format` presente nel progetto

### Regole principali

- Indentazione: 4 spazi
- Lunghezza massima riga: 100 caratteri
- Stile delle parentesi graffe: Attach (sulla stessa riga della struttura di controllo)
- Asterischi per puntatori/riferimenti allineati a sinistra
- Ordinamento automatico degli include
- Access specifier delle classi rientrati di -4 spazi

### Note

1. Prima di inviare una PR, assicurati che il codice sia formattato.  
2. Non riallineare manualmente codice già formattato.  
3. Per escludere sezioni dalla formattazione usare:
   ```cpp
   // clang-format off
   // codice da non formattare
   // clang-format on
   ```

### Problemi comuni

1. **Formattazione fallita**:
- Verificare la versione di `clang-format`  
- Assicurarsi che il file sia in UTF-8  
- Controllare la sintassi di `.clang-format`

2. **Formato diverso da quello atteso**:
- Assicurarsi di usare il `.clang-format` presente nella root del progetto  
- Verificare che non esistano altri `.clang-format` con priorità superiore

Per domande o suggerimenti, apri un issue o invia una pull request.
