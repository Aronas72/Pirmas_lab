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

v0.3 versijoje taip pat atlikti keli pakeitimai:
- Pridėtas pasirinkimas kokiame konteineryje norima talpinti studento duomenis (Vector arba List).
- Rankiniu būdu įvedus duomenis galima pamatyti objekto saugojimo atmintyje adresą.
- Atlikta spartos analizė su Vector ir List konteineriais.

Analizė: buvo matuojami 3 parametrai: nuskaitymas iš failo ir talpinimas pasirinktame konteineryje, rūšiavimas į dvi grupes (vargšiukai ir galvočiai), duomenų įrašymas į failą. Analizė atlikta su iš anksto sugeneruotais failais. Visi testai buvo atlikti 5 kartus ir gauti rezultatai surašyti į lenteles.

Rezultatai:

Surūšiavimas į dvi grupes:
|Įrašų skaičius|   Vector (s.)    |   List (s.)  |
|--------------|-----------------:|-------------:|
|1 000         |      0.0003      |     0.0002   |
|10 000        |      0.0026      |     0.0024   |
|100 000       |      0.0243      |     0.0232   |
|1 000 000     |      0.2776      |     0.2757   |
|10 000 000    |      2.9258      |     3.0777   |

Failų skaitymas:
|Įrašų skaičius|   Vector (s.)    |   List (s.)   |
|--------------|-----------------:|--------------:|
|1 000         |      0.0075      |     0.0052    |
|10 000        |      0.0386      |     0.0357    |
|100 000       |      0.3294      |     0.3273    |
|1 000 000     |      4.6707      |     4.6867    |
|10 000 000    |     36.3395      |    37.7434    |

Duomenų įrašymas į failą:
|Įrašų skaičius|   Vector (s.)    |   List (s.)   |
|--------------|-----------------:|--------------:|
|1 000         |      0.0019      |     0.0019    |
|10 000        |      0.0194      |     0.0177    |
|100 000       |      0.1668      |     0.1738    |
|1 000 000     |      1.7955      |     1.8345    |
|10 000 000    |     20.1897      |     21.602    |

IŠVADOS: iš rezultatų matome, kad labai didelių skirtumų tarp konteinerių nėra. Su duomenų kiekiais iki 1000000 įskaitant dirbama labai panašiu tempu, tik galima išskirti 1000000 duomenų įrašymą į failą, kur rezultatas truputį aiškesnis. Nuo 10000000 matome jau Vector konteinerio pranašumą visose testavimo kategorijose, kai skirtumas siekia 1-1.5 sekundės.

Kompiutrio parametrai, su kuriuo buvo atliktas testavimas: 8 GB RAM, SSD 251 GB, procesorius gali būti iki 3.49 GHz.
