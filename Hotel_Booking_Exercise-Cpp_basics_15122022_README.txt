Ohjelman toiminta / sis�lt�

Ohjelma on hotellihuoneen varausj�rjestelm�, jonka kautta voidaan joko varata huone tai tarkastella aikaisempaa varausta, sek� t�m�n kautta mahdollisesti poistaa vanha varaus.
Hotellissa on 200 huonetta, joista 1�100 on yhden hengen huoneita ja 101�200 on kahden hengen huoneita. Jokainen huone on structi, jolle on asetettu ns. �oletusarvot� tyhj�lle
huoneelle, muuttujat ovat sen sis�ll� �muka-tyhji�. T�rkeint� on, ett� varaamaton huone ei sis�ll� mit��n tietoja varauksesta, ei henkil�titetoja, sek� huone on vapaa varattavaksi.
T�m�nkaltaisilla structeilla on t�ytetty array, joka on t�ss� tapauksessa koko hotelli, 200 huonetta.

Jotta v�ltyn liialta toistamiselta sanottakoot, ett� sy�tteen ja muuttujien virheentarkistusta on joka v�liss�, eri tavoin. Varausnumero ei voi olla sama kahdella eri varauksella.
Huoneella voi olla vain yksi varaus kerrallaan. Sy�tteiden oikea muoto tarkastetaan joka v�liss�, jotta ohjelma ei kaadu tai palauta odottamattomia arvoja. Ohjelma antaa my�s palautetta
v��r�nlaisesta sy�tteest�. Er��ss� vaiheessa random-generaattori palautti my�s rangen ulkopuolisia arvoja, jonka vuoksi tein sillekin virhearvioinnin, palautteen sek� palautuksen aiempaan
pisteeseen ohjelmassa. Kun my�hemmin korjasin koodiani, t�m� kohta tuli turhaksi, mutta mielest�ni se oli silti perusteltua sis�lt�� lopulliseen koodiin, ik��n kuin �varmuuden vuoksi�.
Vaikka kuinka yritin, en saanut rikottua ohjelmaani v��r�nlaisilla sy�tteill� miss��n ohjelman vaiheessa. Otan mielell�ni palautetta vastaan, mik�li t�m� onnistuu joltain k�ytt�j�lt�.
Varauksen luomisen j�lkeen varausta voidaan hakea joko nimell� tai varausnumerolla. Kun huone on l�ytynyt, varaus voidaan joko poistaa tai s�ilytt�� ennallaan. Poistaminen alustaa kyseisen
huoneen structin kaikki muuttujat takaisin oletusarvoiksi, sek� huoneen uudelleenvarattavaksi.

Olen halunnut pit�� int main():n mahdollisimman minimaalisena, koska ainakin omille aivoilleni on helpompaa seurata yhden funktion sis�lle syv�lle menemist�, kuin pomppimista int main():n
ja funktioiden v�lill�. Ohjelman int main() onkin vain n. 60 rivi� pitk�, eli n. 6% koko ohjelmasta. T�m� miellytt�� itse�ni.




Aliohjelmat:

Ohjelma sis�lt�� int main():n lis�ksi 8 aliohjelmaa. N�m� ohjelmat ovat:

int main_menu(); - Ohjelman p��menu, josta siirryt��n oikeisiin toimintoihin. T�m� palauttaa int main():lle arvon 1-3. Arvolla 3 ohjelma p��ttyy, ja 1 tai 2 kutsuu yht� seuraavasta kahdesta funktioista.
Rooms booking_menu(Rooms temp_room[]); - T�m� sis�lt�� koko varauspuolen ohjelmasta. T�m�n sis�ll� kutsutaan toki muita pienempi� funktioita, mutta kaikki t�rkeimm�t toiminnallisuudet on sis�lletty t�m�n sis�lle.
Rooms reservations_menu(Rooms room[]); - T�m� funktio taas k�sitt�� kokonaisuudessaan olemassaolevan varauksen haun nimell� tai varausnumerolla, sek� kyseisen varauksen mahdollisen poistamisen. Kuten edellinen,
t�m�kin sis�lt�� kutsuja pienemmille funktioille.



Pienemm�t aliohjelmat:

bool vacancyALL(Rooms room[]); - T�m� funktio tarkistaa vain, ett� kaikki hotellin huoneet eiv�t ole varattuja ennen eteenp�in p��st�mist�.
bool vacancy_one_bed(Rooms room[]); - Sama kuin yll�, mutta vain huoneille 1-100 (yhden hengen huoneet).
bool vacancy_two_bed(Rooms room[]); - Sama kuin yll�, mutta vain huoneille 101-200 (kahden hengen huoneet).

NOTE:
Edelliset kolme olisi voinut toteuttaa my�s yhdell� aliohjelmalla, l�hett�m�ll� parametreja funktiolle joiden mukaan aliohjelma k�y joko kaikki, tai vain tietyt huoneet l�pi if:i� tai switch:i� k�ytt�m�ll�.

float discount_randomizer(); - Yksinkertainen funktio, joka arpoo yhden kolmesta alennuskategoriasta jokaiselle varaukselle.
bool is_only_numbers(string string_test); - Koska jotkut numeromuotoiset inputit on asetettu string-tyyppisiksi (sy�tteentarkistuksen vuoksi), k�y t�m� funktio l�pi stringin ja ilmoittaa onko siell� yht��n merkki�,
joka ei olisi numero. K�ytetty mm. tarkistamaan �iden m��r�n sy�tteen muotoa.

Ominaisuudet:

Muun muassa seuraavat ominaisuudet l�ytyv�t ohjelmasta:
- Alennuksen random-generointi
- Varauksen random-generointi, sek� tarkistus ettei generoitua numero viel� k�yt�ss�
- Huoneita 200, 1�100 yhden hengen huoneita ja 101�200 kahden hengen huoneita
- Aiemmin tehdyn varauksen poisto
- Huonehinnat globaaleina vakioina 1hh 100 � ja 2hh 150 �
- Sy�tteentarkistuksia sek� ongelmatilanteiden ehk�isy� (en saanut rikottua ohjelmaani)
- Huonevalinta itse tai koneen arpomana



Aion jatkojalostaa t�t� ohjelmaa, tavoitteena saada mm. tallennettua huoneiden �tietokanta� tiedostoksi koneelle, esim. .xml-tiedostoksi, sek� sen mahdollisen importtaaminen ohjelmaan sis��n.

Mika Miettinen
15.12.2022

