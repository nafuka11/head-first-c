1. Download files
   ```bash
   curl -O http://dogriffiths.github.io/HeadFirstC/map.html
   curl -O http://dogriffiths.github.io/HeadFirstC/spooky.csv
   ```
2. Compile c file
   ```bash
   gcc bermuda.c -o bermuda
   ```
3. Generate output.json
   ```bash
   (./bermuda | ../geo2json/geo2json) < spooky.csv > output.json
   ```
