Ohjelman toiminta / sisältö

Ohjelma on hotellihuoneen varausjärjestelmä, jonka kautta voidaan joko varata huone tai tarkastella aikaisempaa varausta, sekä tämän kautta mahdollisesti poistaa vanha varaus.
Hotellissa on 200 huonetta, joista 1–100 on yhden hengen huoneita ja 101–200 on kahden hengen huoneita. Jokainen huone on structi, jolle on asetettu ns. ”oletusarvot” tyhjälle
huoneelle, muuttujat ovat sen sisällä ”muka-tyhjiä”. Tärkeintä on, että varaamaton huone ei sisällä mitään tietoja varauksesta, ei henkilötitetoja, sekä huone on vapaa varattavaksi.
Tämänkaltaisilla structeilla on täytetty array, joka on tässä tapauksessa koko hotelli, 200 huonetta.

Jotta vältyn liialta toistamiselta sanottakoot, että syötteen ja muuttujien virheentarkistusta on joka välissä, eri tavoin. Varausnumero ei voi olla sama kahdella eri varauksella.
Huoneella voi olla vain yksi varaus kerrallaan. Syötteiden oikea muoto tarkastetaan joka välissä, jotta ohjelma ei kaadu tai palauta odottamattomia arvoja. Ohjelma antaa myös palautetta
vääränlaisesta syötteestä. Eräässä vaiheessa random-generaattori palautti myös rangen ulkopuolisia arvoja, jonka vuoksi tein sillekin virhearvioinnin, palautteen sekä palautuksen aiempaan
pisteeseen ohjelmassa. Kun myöhemmin korjasin koodiani, tämä kohta tuli turhaksi, mutta mielestäni se oli silti perusteltua sisältää lopulliseen koodiin, ikään kuin ”varmuuden vuoksi”.
Vaikka kuinka yritin, en saanut rikottua ohjelmaani vääränlaisilla syötteillä missään ohjelman vaiheessa. Otan mielelläni palautetta vastaan, mikäli tämä onnistuu joltain käyttäjältä.
Varauksen luomisen jälkeen varausta voidaan hakea joko nimellä tai varausnumerolla. Kun huone on löytynyt, varaus voidaan joko poistaa tai säilyttää ennallaan. Poistaminen alustaa kyseisen
huoneen structin kaikki muuttujat takaisin oletusarvoiksi, sekä huoneen uudelleenvarattavaksi.

Olen halunnut pitää int main():n mahdollisimman minimaalisena, koska ainakin omille aivoilleni on helpompaa seurata yhden funktion sisälle syvälle menemistä, kuin pomppimista int main():n
ja funktioiden välillä. Ohjelman int main() onkin vain n. 60 riviä pitkä, eli n. 6% koko ohjelmasta. Tämä miellyttää itseäni.




Aliohjelmat:

Ohjelma sisältää int main():n lisäksi 8 aliohjelmaa. Nämä ohjelmat ovat:

int main_menu(); - Ohjelman päämenu, josta siirrytään oikeisiin toimintoihin. Tämä palauttaa int main():lle arvon 1-3. Arvolla 3 ohjelma päättyy, ja 1 tai 2 kutsuu yhtä seuraavasta kahdesta funktioista.
Rooms booking_menu(Rooms temp_room[]); - Tämä sisältää koko varauspuolen ohjelmasta. Tämän sisällä kutsutaan toki muita pienempiä funktioita, mutta kaikki tärkeimmät toiminnallisuudet on sisälletty tämän sisälle.
Rooms reservations_menu(Rooms room[]); - Tämä funktio taas käsittää kokonaisuudessaan olemassaolevan varauksen haun nimellä tai varausnumerolla, sekä kyseisen varauksen mahdollisen poistamisen. Kuten edellinen,
tämäkin sisältää kutsuja pienemmille funktioille.



Pienemmät aliohjelmat:

bool vacancyALL(Rooms room[]); - Tämä funktio tarkistaa vain, että kaikki hotellin huoneet eivät ole varattuja ennen eteenpäin päästämistä.
bool vacancy_one_bed(Rooms room[]); - Sama kuin yllä, mutta vain huoneille 1-100 (yhden hengen huoneet).
bool vacancy_two_bed(Rooms room[]); - Sama kuin yllä, mutta vain huoneille 101-200 (kahden hengen huoneet).

NOTE:
Edelliset kolme olisi voinut toteuttaa myös yhdellä aliohjelmalla, lähettämällä parametreja funktiolle joiden mukaan aliohjelma käy joko kaikki, tai vain tietyt huoneet läpi if:iä tai switch:iä käyttämällä.

float discount_randomizer(); - Yksinkertainen funktio, joka arpoo yhden kolmesta alennuskategoriasta jokaiselle varaukselle.
bool is_only_numbers(string string_test); - Koska jotkut numeromuotoiset inputit on asetettu string-tyyppisiksi (syötteentarkistuksen vuoksi), käy tämä funktio läpi stringin ja ilmoittaa onko siellä yhtään merkkiä,
joka ei olisi numero. Käytetty mm. tarkistamaan öiden määrän syötteen muotoa.

Ominaisuudet:

Muun muassa seuraavat ominaisuudet löytyvät ohjelmasta:
- Alennuksen random-generointi
- Varauksen random-generointi, sekä tarkistus ettei generoitua numero vielä käytössä
- Huoneita 200, 1–100 yhden hengen huoneita ja 101–200 kahden hengen huoneita
- Aiemmin tehdyn varauksen poisto
- Huonehinnat globaaleina vakioina 1hh 100 € ja 2hh 150 €
- Syötteentarkistuksia sekä ongelmatilanteiden ehkäisyä (en saanut rikottua ohjelmaani)
- Huonevalinta itse tai koneen arpomana



Aion jatkojalostaa tätä ohjelmaa, tavoitteena saada mm. tallennettua huoneiden ”tietokanta” tiedostoksi koneelle, esim. .xml-tiedostoksi, sekä sen mahdollisen importtaaminen ohjelmaan sisään.

Mika Miettinen
15.12.2022

