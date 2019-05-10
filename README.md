# Vektoriaus klasė
## 1. 5 funkcijų aprašymas:
**Resize:**

![Resize](https://imgur.com/VMqP9ql.png)

Ką ši funkcija daro? Pakeičia konteinerio dydį pagal skaičių, kurį nurodome.

Kaip ji veikia? Iš pradžių tikriname ar mūsų nurodytas skaičius yra ne mažesnis už 0 (negali konteinerio dydis būti neigiamas).

Tada tikriname ar mūsų nurodytas skaičius yra mažesnis už dabartinį konteinerio dydį: jei taip - konteinerio dydį `sz` pakeičiame į savo nurodytą skaičių `kiek`. Jeigu mūsų nurodytas skaičius yra didesnis už dabartinį konteinerio dydį - sukuriame naują rodyklę į dinaminę atmintį ir išskyriame skaičiaus `kiek` vietos. Perkopijuojame visus elementus į savo naują sąrašą. Ištriname seną sujungtą sąrašą (atlaisvinama atmintis) ir šio sąrašo rodyklę nukreipiame į naująjį sąrašą.

**Shrink to fit:**

![shrink_to_fit](https://imgur.com/fAQ7LKZ.png)

Ši funkcija sumažina mūsų vektoriaus talpą `capacity` iki vektoriaus dydžio/elementų skaičiaus `sz`


**at:**

![at](https://imgur.com/Km7Zftu.png)

Ši funkcija gražina elementą tam tikroje pozicijoje, kurią mes nurodome (su `pos`).
Jeigu mūsų nurodytas elemento pozicijos indeksas yra didesnis už vektoriaus dydį - "išmetamas" išimties/prieštaravimo objektas, kuris neleidžia mums tęsti. Na, o jeigu indeksas yra mažesnis - iškviesta funkcija grąžina elemento reikšmę `pos` pozicijoje.

**erase:**

![erase](https://imgur.com/W0lNEXo.png)

Iterator funkcija, kurios parametrai yra 2 iteratoriai, kurie nurodo konteinerio elementų trinimo pradžios ir pabaigos intervalą.

`it` priskiriame nuorodą į sąrašo pražią (sakykime, kad sąrašas yra sudarytas iš 10 elementų, kurių indeksai 0-9). Ciklas iki `first` vietos sąraše, didinamos `i` ir `it` reikšmės. Kitas ciklas nuo `first` iki `last` pozicijų konteineryje (trynimo intervalas). Didinamos `i`, `it` ir `temp` reikšmės (`temp` reikšmė - elementų skaičius trynimo intervale). Paskutinis ciklas yra nuo trynimo vietos iki sąrašo pabaigos. Didinamos `i` ir `it` reikšmės. Ciklo viduje, trynimo intervale esantys elementai perrašomi į po `last` iteratoriaus rodyklės iki sąrašo galo esančiais elementais. Po šio ciklo mūsų konteinerio dydis sumažinamas tiek, kiek trynimo intervale buvo elementų `temp`.
Grąžinama pakeisto konteinerio `last` reikšmė (jei pvz. indeksas buvo 5 tai bus grąžinama naują reikšmė su indeksu 5).


**reserve:**

![reserve](https://imgur.com/xZC7IBb.png)

Atminties rezervacijos funkcija su parametru `kiek`. Ši funkcija padidina konteinerio talpą ir išskiria daugiau atminties. Iš pradžių tikrinama ar `kiek` skaičius yra ne didesnis nei `max_size()` skaičius, kurį gavau pasinaudojęs `std::vector` `max_size` gauta reikšme. Jeigu dydis `kiek` yra didesnis nei `cap` - talpa, tai talpai `cap` priskiriama `kiek` reikšmė ir išskiriama naujam sąrašui `kiek` dinaminės atminties vietos. Po to visi elementai iš `elem` perkopijuojami į `temp` ir pats `elem` yra ištrinamas - elem priskiriamas temp sąrašas.


## 2. Spartos analizė:

![main](https://imgur.com/ciX1Ff9.png)

| Elementų skaičius: | std::vector konteinerio vidutinis laikas: | Mano Vector konteinerio vidutinis laikas: |
| ----- | ---- | --- |
| 10000 | 0s | 0s |
| 100000 | 0s | 0s |
| 1000000 | 0s | 0s |
| 10000000 | 0.0937279s | 0.0937279s |
| 100000000 | 0.74462s | 0.57277s |

[testai](https://imgur.com/a/gdD4NqI)
