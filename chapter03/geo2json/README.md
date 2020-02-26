1. Download files
   ```bash
   curl -O http://dogriffiths.github.io/HeadFirstC/map.html
   curl -o output_org.json http://dogriffiths.github.io/HeadFirstC/output.json
   ```
2. Compile c file
   ```bash
   gcc geo2json.c -o geo2json
   ```
3. Generate output.json
   ```bash
   ./geo2json < gpsdata.csv > output.json
   ```
