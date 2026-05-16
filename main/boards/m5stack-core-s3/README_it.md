# M5Stack Core S3 — Istruzioni rapide

## Compilazione

```bash
python ./scripts/release.py m5stack-core-s3
```

Per compilare manualmente, modificare `m5stack-core-s3/config.json` e usare `idf.py menuconfig`.

## Flash

```bash
idf.py flash
```

Nota: per entrare in modalità download tenere premuto il pulsante di reset per ~3s fino a che il LED interno diventa verde, quindi rilasciare.
