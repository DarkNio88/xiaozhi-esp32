## EDA-Robot-Pro (robot quadrupede)

### Documentazione del progetto
- [Documentazione EDA-Robot-Pro](https://wiki.lceda.cn/zh-hans/course-projects/smart-internet/eda-robot/eda-robot-introduce.html)

### Configurazione di compilazione
Adatta la dimensione del Flash in base al modulo ESP32S3 utilizzato.  
Esempio: se il modulo dispone di 8MB di Flash:

```
Partition Table  --->
  Partition Table (Custom partition table CSV)  --->
  (partitions/v2/8m.csv) Custom partition CSV file
```
