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

Antrojoje versijoje matome ir kelis pasikeitimus nuo v0.1 versijos:
- Sukurta failų generavimo funkcija, kuri sugeneruoja 1000, 10000, 100000, 1000000 ir 10000000 dydžio studentų failus.
- Sukurtas studentų išskaidymas į dvi grupes: vargšiukus (galutinis balas mažesnis nei 5) ir galvočius (galutinis balas nemažesnis nei 5).
- Įvykdytas kodo reorganizavimas.
- Dabar galima atlikti rikiavimą ir pagal galutinį balą.
- Atlikta programos spartos analizė.

Generavimo vidurkiai:
- 1000 įrašų failas sukuriamas per vidutiniškai 0.013 s.
- 10000 įrašų failas sukuriamas per vidutiniškai 0.023 s.
- 100000 įrašų failas sukuriamas per vidutiniškai 0.22 s.
- 1000000 įrašų failas sukuriamas per vidutiniškai 2.8 s.
- 10000000 įrašų failas sukuriamas per vidutiniškai 28.44 s.

# Versija v0.3

Rezultatai:

Surūšiavimas į dvi grupes:
|Įrašų skaičius|   Vector (s.)   |   List (s.)   |
|--------------|----------------:|--------------:|
|1 000         |      0.0003     |               |
|10 000        |      0.0026     |               |
|100 000       |      0.0243     |               |
|1 000 000     |      0.2776     |               |
|10 000 000    |      2.9258     |               |

Failų skaitymas:
|Įrašų skaičius|   Vector (s.)   |   List (s.)   |
|--------------|----------------:|--------------:|
|1 000         |      0.0075     |               |
|10 000        |      0.0386     |               |
|100 000       |      0.3294     |               |
|1 000 000     |      4.6707     |               |
|10 000 000    |     36.3395     |               |

Duomenų įrašymas į failą:
|Įrašų skaičius|   Vector (s.)   |   List (s.)   |
|--------------|----------------:|--------------:|
|1 000         |      0.0019     |               |
|10 000        |      0.0194     |               |
|100 000       |      0.1668     |               |
|1 000 000     |      1.7955     |               |
|10 000 000    |     20.1897     |               |

IŠVADOS: 

Kompiutrio parametrai, su kuriuo buvo atliktas testavimas: 
