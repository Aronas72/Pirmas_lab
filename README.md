# Pirmas laboratorinis darbas
# Versija v0.1
Sukurta pirma versija v0.1, kurioje:

- Sukurta struktūra Studentas, kurioje kaupiami duomenys apie studentą: vardas, pavardė, pažymiai, vidurkis, mediana.
- Iš pradžių išvedamas tik vidurkis, vėliau prijungtas ir skaičiavimas pagal medianą.
- Galimas ir nežinomas namų darbų kiekis, todėl galima ir nežinant tikslaus skaičiaus namų darbų, įvesti jų pažymius.
- Pasirinkimas, kad rodytų galutinį balą pagal vidurkį arba tik pagal medianą arba rodytų abu.
- Pažymių atsitiktinis generavimas.
- Duomenų nuskaitymas iš failo ir išvedimas į rezultatų tekstinį failą.
- Rikiavimo funkcija, kuri surikiuoja studentus pagal vardą arba pavardę.
- Parašius kodą buvo keblumų dėl tam tikrų detalių, kaip o kas jeigu vietoj pažymio būtų įvedama raidė. Tuo atveju programa lūžo, bet pastebėjus tai, ši klaida buvo ištaisyta pačiu paskutiniu commit'u.

Kodą rasti: lab->lab->programa.cpp.

# Versija v0.2

Vidurkiai:
- 1000 įrašų failas nuskaitomas vidutiniškai per 0.015 s., rūšiaviams atliekamas per vidutiniškai 0.0005 s., dalijimas i dvi grupes per 0.0003 s., sukuriamas per vidutiniškai 0.013 s.
- 10000 įrašų failas nuskaitomas vidutiniškai per 0.046 s., rūšiaviams atliekamas per vidutiniškai 0.003 s., dalijimas i dvi grupes per 0.0025 s., sukuriamas per vidutiniškai 0.023 s.
- 100000 įrašų failas nuskaitomas vidutiniškai per 0.36 s., rūšiaviams atliekamas per vidutiniškai 0.022 s., dalijimas i dvi grupes per 0.024 s., sukuriamas per vidutiniškai 0.22 s.
- 1000000 įrašų failas nuskaitomas vidutiniškai per 4.54 s., rūšiaviams atliekamas per vidutiniškai 0.264 s., dalijimas i dvi grupes per 0.3 s., sukuriamas per vidutiniškai 2.8 s.
- 10000000 įrašų failas nuskaitomas vidutiniškai per 36.36 s., rūšiaviams atliekamas per vidutiniškai 2.73 s., dalijimas i dvi grupes per 3.11 s., sukuriamas per vidutiniškai 28.44 s.

# Versija v0.3

Rezultatai:

Surūšiavimas į dvi grupes:
|Įrašų skaičius|   Vector (s.)   |   List (s.)   |
|--------------|----------------:|--------------:|
|1000          |                 |               |
|10000         |                 |               |
|100000        |                 |               |
|1000000       |                 |               |
|10000000      |                 |               |

Išrikiavimas pagal galutinį balą:
|Įrašų skaičius|   Vector (s.)   |   List (s.)   |
|--------------|----------------:|--------------:|
|1000          |                 |               |
|10000         |                 |               |
|100000        |                 |               |
|1000000       |                 |               |
|10000000      |                 |               |

Duomenų įrašymas į failą:
|Įrašų skaičius|   Vector (s.)   |   List (s.)   |
|--------------|----------------:|--------------:|
|1000          |                 |               |
|10000         |                 |               |
|100000        |                 |               |
|1000000       |                 |               |
|10000000      |                 |               |
