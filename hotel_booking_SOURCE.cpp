#include<iostream>
#include<string> // getlineja sekä muita string-juttuja varten, mukaan lukien STOI
#include<iomanip> // Jotta saa coutiin printattua oikean määrän desimaaleja
#include<cmath> // Pyöristystä varten






using namespace std;

const float one_bed = 100.00, two_bed = 150.00; // Määritetään huoneiden per-yö-hinnat const floateiksi joiden arvot pysyvät kiinteinä
// Näin niitä on helppo myöhemmin muuttaa tai vaikkapa lisätä uudenlaisia eri hintaisia huoneita


// Esitellään yksittäinen Structi "Rooms" ja asetetaan oletusarvot sen muuttujille

struct Rooms
{
	int room_size_struct = 0;
	int room_number_struct = 0;
	string name = "N/A";
	float cost_per_night = 0;
	float cost_final = 0;
	float discount_percentage = 0;
	bool vacant = true;
	int nights = 0;
	int reservation_number = 0;

};


// Alustetaan 200 huoneen array edellämainituilla arvoilla

Rooms room[200];


// Esitellään käytettävät funktiot

int main_menu();

Rooms booking_menu(Rooms temp_room[]);

Rooms reservations_menu(Rooms room[]);


bool vacancyALL(Rooms room[]);
bool vacancy_one_bed(Rooms room[]);
bool vacancy_two_bed(Rooms room[]);


float discount_randomizer();

bool is_only_numbers(string string_test);






int main() {



	setlocale(LC_ALL, "fi_FI"); // Enabloidaan ääkköset tulosteisiin valitsemalla suomenkielinen merkistö

	cout << "Tervetuloa Scandal-hotellin huonevarausjärjestelmään!\n\n";



	while (true)
	{
		switch (main_menu())
		{

		case 1:

			// Tarkista ensin onko ollenkaan vapaata hotellissa
			if (vacancyALL(room) == true)
			{



				//Kutsutaan varausmenu-funktiota
				booking_menu(room);


				break;

			}

			else
			{
				cout << "Ei vapaita huoneita saatavilla. :(";
				break;
			}

			break;

		case 2:

			reservations_menu(room); // Kutsutaan varauksen tarkastelu-funktiota


			break;


		case 3:

			cout << "\nIstunto päätetty, näkemiin!\n"; // Päätetään ohjelma
			return 0;


		}
	}





	return 0;
}







//----------------------------------------------------------------------------------------------------------



// Määritellään funktiot:


	// Päämenunäkymä ja toiminnon valinta

int main_menu() {

	string action = "0"; //String-tyyppinen jotta ymmärtää verrata esim 1 != 1d


	cout << "\nValitse haluamasi toiminto (1 - 3) ja paina Enter: "
		<< endl
		<< "1. Tee uusi varaus"
		<< endl
		<< "2. Hae / poista varaus"
		<< endl
		<< "3. Poistu ohjelmasta"
		<< endl
		<< endl
		<< "Valintasi: ";

	cin >> action;

	if (action == "1")
	{
		return 1;

	}

	else if (action == "2")
	{

		return 2;

	}


	else if (action == "3")
	{
		return 3;
	}

	else
	{
		cin.clear(); // Tyhjennetään cin bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoretaan aiempi syöte kokonaan

		cout << "\nVirheellinen syöte! Käytä vain numeronäppäimiä (1-3).\n\n\n";

		return 0;
	}



}




//----------------------------------------------------------------------------------------------------------


	// Varausmenu-funktio (valinta 1)

Rooms booking_menu(Rooms temp_room[]) {



	string b_action = "0"; //String-tyyppinen jotta ymmärtää verrata esim 1 != 1d
	string string_test = "";
	int room_choice = 0, room_number = 0;

	while (true)
	{

		cout << "\nHaluatko varata yhden vai kahden hengen huoneen? (1-2)?" << endl
			<< "(1) Yhden hengen huoneeen: 100 euroa / yö" << endl
			<< "(2) Kahden hengen huoneen hinta 150 euroa / yö" << endl << endl
			<< "Valintasi: ";
		cin >> b_action;


		// VALITTUNA YHDEN HENGEN HUONE


		if (b_action == "1")
		{
			// Tarkista, onko tämän tyyppisiä huoneita vapaana

			if (vacancy_one_bed(room)) // Jos vapaita huoneita jäljellä, päästä eteenpäin
			{

				cout << "\nHaluatko valita huoneen numero itse (1) vai ottaa satunnaisen yhden hengen huoneen (2)?" << endl << endl
					<< "Valintasi: ";
				cin >> b_action;


				if (b_action == "1") // Annetaan valita huonenumero itse
				{

					cout << "\nValitse huonenumero (1 - 100): ";
					cin >> room_choice;

					if (room_choice > 0 && room_choice <= 100) // Tarkistetaan onko syöte oikeanlainen
					{

						if (temp_room[room_choice - 1].vacant == true) // Tarkistetaan tietyn huoneen vapaus
						{

							room_number = room_choice;



							goto input_reservation_data; // Hypätään nested-looppien ulkopuolelle, goto on tähän kätevin ja selkein tapa
							// input_reservation_data - kohdassa (tämän funktion lopussa) vasta otetaan varauksen tietoja vastaan,
							// kun varmistuttu huoneesta ja sen vapaudesta


						}



						else
						{
							cout << "\nIkävä kyllä kyseinen huone on jo varattu. :(  Ole Hyvä ja valitse toinen huone.\n";

						}
					}


					else
					{

						cin.clear(); // Tyhjennetään cin bad input flag
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoretaan aiempi syöte kokonaan

						cout << "\nVirheellinen syöte! Valitse huone väliltä 1 - 100. Käytä vain numeronäppäimiä.\n\n\n";

					}
				}


				else if (b_action == "2") // Järjestelmä valitsee huoneen randomilla
				{
					do // Tarkistetaan random-huoneiden saatavuutta kunnes vapaa huone löytyy
					{
						srand((unsigned)time(NULL));


						room_choice = 1 + rand() % 100;


					} while (temp_room[room_choice - 1].vacant == false);


					room_number = room_choice;

					cout << "\nHuonenumerosi on: " << room_number << endl << endl;



					goto input_reservation_data; // Hypätään nested-looppien ulkopuolelle, goto on tähän kätevin ja selkein tapa
					// input_reservation_data - kohdassa (tämän funktion lopussa) vasta otetaan varauksen tietoja vastaan,
					// kun varmistuttu huoneesta ja sen vapaudesta



				}

				else
				{
					cin.clear(); // Tyhjennetään cin bad input flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoretaan aiempi syöte kokonaan

					cout << "\nVirheellinen syöte! Käytä vain numeronäppäimiä.\n\n\n";
				}

			}

			else
			{
				cout << "\nIkävä kyllä kaikki yhden hengen huoneet ovat jo varattuja. :( Ole hyvä, ja valitse toisenlainen huone.\n";
			}



		}


		// VALITTUNA KAHDEN HENGEN HUONE


		else if (b_action == "2")
		{
			if (vacancy_two_bed(room) == true) // Jos vapaita huoneita jäljellä, päästä eteenpäin
			{

				cout << "\nHaluatko valita huoneen numero itse (1) vai ottaa satunnaisen kahden hengen huoneen (2)?" << endl << endl
					<< "Valintasi: ";
				cin >> b_action;


				if (b_action == "1") // Annetaan valita huonenumero itse
				{

					cout << "\nValitse huonenumero (101 - 200): ";
					cin >> room_choice;

					if (room_choice > 100 && room_choice <= 200) // Tarkistetaan onko syöte oikeanlainen
					{

						if (temp_room[room_choice - 1].vacant == true) // Tarkistetaan tietyn huoneen vapaus
						{

							room_number = room_choice;


							goto input_reservation_data; // Hypätään nested-looppien ulkopuolelle, goto on tähän kätevin ja selkein tapa
							// input_reservation_data - kohdassa (tämän funktion lopussa) vasta otetaan varauksen tietoja vastaan,
							// kun varmistuttu huoneesta ja sen vapaudesta



						}



						else
						{
							cout << "\nIkävä kyllä kyseinen huone on jo varattu. :(  Ole Hyvä ja valitse toinen huone.\n";

						}
					}


					else
					{

						cin.clear(); // Tyhjennetään cin bad input flag
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoretaan aiempi syöte kokonaan

						cout << "\nVirheellinen syöte! Valitse huone väliltä 101 - 200. Käytä vain numeronäppäimiä.\n\n\n";

					}
				}


				else if (b_action == "2") // Järjestelmä valitsee huoneen randomilla
				{

					do // Tarkistetaan random-huoneiden saatavuutta kunnes vapaa huone löytyy
					{
						srand((unsigned)time(NULL));


						room_choice = 1 + rand() % 100;
						room_choice += 100;


					} while (temp_room[room_choice - 1].vacant == false);


					room_number = room_choice;

					cout << "\nHuonenumerosi on: " << room_number << endl << endl;





					goto input_reservation_data; // Hypätään nested-looppien ulkopuolelle, goto on tähän kätevin ja selkein tapa
					// input_reservation_data - kohdassa (tämän funktion lopussa) vasta otetaan varauksen tietoja vastaan,
					// kun varmistuttu huoneesta ja sen vapaudesta


				}

				else
				{
					cin.clear(); // Tyhjennetään cin bad input flag
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoretaan aiempi syöte kokonaan

					cout << "\nVirheellinen syöte! Käytä vain numeronäppäimiä.\n\n\n";
				}





			}

			else
			{
				cout << "\nIkävä kyllä kaikki kahden hengen huoneet ovat jo varattuja. :( Ole hyvä, ja valitse toisenlainen huone.\n";
			}


		}

		else
		{
			cin.clear(); // Tyhjennetään cin bad input flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoretaan aiempi syöte kokonaan

			cout << "\nVirheellinen syöte! Hotellissa on vain yhden ja kahden hengen huoneita. Käytä vain numeronäppäimiä.\n\n\n";
		}

	}


	// VARAUKSEN SYÖTTÖ TEMP-STRUCTIIN


input_reservation_data: // Vasta täällä syötetään data varaukselle
	int room_index = (room_number - 1);


	if (room_number > 0 && room_number <= 100)
	{
		temp_room[room_index].room_size_struct = 1;
		temp_room[room_index].cost_per_night = one_bed;
	}

	else if (room_number > 100 && room_number <= 200)
	{
		temp_room[room_index].room_size_struct = 2;
		temp_room[room_index].cost_per_night = two_bed;
	}

	else
	{
		cout << "\n\nTapahtui odottamaton virhe (huonenumeron arvo alle 1 tai yli 200), palataan päänäkymään.\n\n";
		return temp_room[room_index];
	}

	while (true)
	{


		cout << "\nSyötä öiden määrä varaukselle: ";
		cin >> string_test;


		if (is_only_numbers(string_test) == true)
		{
			if (string_test.length() < 10)

			{
				if (string_test == "0")
				{

					cout << "\nIkävä kyllä voit yöpyä meillä vähintään 1 yön per varaus. Ole hyvä ja valitse suurempi luku.\n\n";

				}
				else
				{
					temp_room[room_index].nights = stoi(string_test); // STOI (string to int) tulkitsee stringing numerot inteiksi,
					// ja tässä tapauksessa asettaa numeroksi todennetun arvon öiden määräksi ja breakkaa

					break;
				}
			}


			else
			{
				cout << "\nIkävä kyllä voit yöpyä meillä vain 999999999 yötä per varaus. Ole hyvä ja valitse pienempi luku.\n\n";
			}
			false;
		}

		else
		{
			cout << "\nVirheellinen syöte! Käytä vain numeronäppäimiä.\n\n\n";
			false;
		}


	}

	temp_room[room_index].discount_percentage = discount_randomizer();

	cout << "\nPärstäkertoimen perusteella olemme myöntäneet sinulle " << fixed << setprecision(0) << (temp_room[room_index].discount_percentage * 100)
		<< " % alennuksen. Olet sen ansainnut.";


	temp_room[room_index].cost_final = temp_room[room_index].cost_per_night * temp_room[room_index].nights * (1.00 - temp_room[room_index].discount_percentage);

	temp_room[room_index].discount_percentage = temp_room[room_index].discount_percentage * 100;

	cout << "\nLopullinen hinta varauksellesi olisi: " << fixed << setprecision(2) << temp_room[room_index].cost_final << " euroa." << endl
		<< "\nValitse '1' jatkaaksesi tai mitä tahansa muuta palataksesi päänäkymään: ";
	cin >> b_action;


	if (b_action == "1")
	{
		string nameTEMP = "";
		cout << "\nKenen nimellä varaus tehdään? (Etunimi Sukunimi): ";
		cin.ignore();
		getline(cin, temp_room[room_index].name);


		temp_room[room_index].room_number_struct = room_number;

		temp_room[room_index].vacant = false;

		string vacancyYNfunc;

		if (temp_room[room_index].vacant == false)
		{
			vacancyYNfunc = "Varattu";
		}
		else
		{
			vacancyYNfunc = "Vapaa";
		}

		int random_reservation_number = 0;

		srand((unsigned)time(NULL));

		random_reservation_number = 10000 + rand() % 99999;

		for (int i = 0; i < 200; i++) // Tarkistetaan, löytyykö kyseistä varausnumeroa vielä muista varauksista/huoneista, vasta kun ei löydy, se asetetaan indexin varausnumeroksi
		{

			if (temp_room[i].reservation_number == random_reservation_number)
			{
				random_reservation_number = 10000 + rand() % 99999;

				i = 0;
			}


		}

		temp_room[room_index].reservation_number = random_reservation_number;



		cout << "\n****************************************************\n";

		cout << endl << "Varauksesi tiedot:" << endl << endl
			<< "Varaajan nimi: " << temp_room[room_index].name << endl
			<< "Huonekoko: " << temp_room[room_index].room_size_struct << ":n hengen huone" << endl
			<< "Huonenumero: " << temp_room[room_index].room_number_struct << endl
			<< "Hinta per yö: " << temp_room[room_index].cost_per_night << endl
			<< "Öiden määrä: " << temp_room[room_index].nights << endl
			<< "Alennusprosentti: " << temp_room[room_index].discount_percentage << endl
			<< "Loppusumma: " << temp_room[room_index].cost_final << endl
			<< "Varaustilanne: " << vacancyYNfunc << endl
			<< "Varausnumero: " << temp_room[room_index].reservation_number << endl;

		cout << "\n****************************************************\n";



		cout << "\nTervetuloa viettämään kanssamme " << temp_room[room_index].nights << " ihanaa yötä! :)\n";
		cout << "\n--------------------------------------------------------------------\n\n";

		//room[(temp_room.room_number_struct - 1)] = temp_room;
		return temp_room[room_index];
	}


	else
	{
		cin.clear(); // Tyhjennetään cin bad input flag
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoretaan aiempi syöte kokonaan

		cout << "\nPalataan päänäkymään.";
		cout << "\n--------------------------------------------------------------------\n\n";

		return temp_room[room_index];
	}




}






//----------------------------------------------------------------------------------------------------------


	// Varauksen tarkastelu-funktio (valinta 2)




Rooms reservations_menu(Rooms temp_room[]) {

	int reservation_number_choice = 0;
	string name_choice = "", r_action = "", string_test = ""; //String-tyyppinen r_action jotta ymmärtää verrata esim 1 != 1d


	while (true)
	{
		cout << "\nHaluatko hakea varausta varausnumerolla (1) vai nimellä (2)?: ";
		cin >> r_action;


		if (r_action == "1")
		{

			while (true)
			{
				cout << "\nSyötä varausnumero numeronäppäimillä (10000-99999): ";
				cin >> string_test;

				if (is_only_numbers(string_test) == true) // Tarkistetaan onko syöte pelkkiä numeroita funtion kautta
				{


					if (stoi(string_test) >= 10000 && stoi(string_test) <= 99999) // Tarkistetaan myös onko annettu numeroarvo hyväksyttyjen raamien sisällä

					{
						reservation_number_choice = stoi(string_test); // STOI (string to int) tulkitsee stringing numerot inteiksi, 
						// ja tässä tapauksessa asettaa numeroksi todennetun arvon öiden määräksi ja breakkaa
						break;
					}
					else
					{
						cout << "\nVirheellinen syöte! Varausnumero on numerosarja välillä 10000-99999.\n\n\n";
						false;
					}
				}

				else
				{
					cout << "\nVirheellinen syöte! Käytä vain numeronäppäimiä.\n\n\n";
					false;
				}

			}



			for (int i = 0; i < 200; i++) // Käy läpi kaikki huoneet josko löytyisi varaus kyseisellä varausnumerolla
			{
				if (temp_room[i].reservation_number == reservation_number_choice) // Jos löytyy niin printtaa varauksen tiedot ja päästää poistovalintaan
				{
					int r_room_index = i;

					string vacancyYNfunc;

					if (temp_room[r_room_index].vacant == false)
					{
						vacancyYNfunc = "Varattu";
					}
					else
					{
						vacancyYNfunc = "Vapaa";
					}

					cout << "\n****************************************************\n";

					cout << endl << "\n\nVarauksesi tiedot:" << endl << endl
						<< "Varaajan nimi: " << temp_room[r_room_index].name << endl
						<< "Huonekoko: " << temp_room[r_room_index].room_size_struct << ":n hengen huone" << endl
						<< "Huonenumero: " << temp_room[r_room_index].room_number_struct << endl
						<< "Hinta per yö: " << temp_room[r_room_index].cost_per_night << endl
						<< "Öiden määrä: " << temp_room[r_room_index].nights << endl
						<< "Alennusprosentti: " << temp_room[r_room_index].discount_percentage << endl
						<< "Loppusumma: " << temp_room[r_room_index].cost_final << endl
						<< "Varaustilanne: " << vacancyYNfunc << endl
						<< "Varausnumero: " << temp_room[r_room_index].reservation_number << endl;

					cout << "\n****************************************************\n";


					cout << "\n\nHaluatko poistaa varauksesi? (1 = Kyllä / 2 = Ei): ";
					cin >> r_action;


					if (r_action == "1") // Jos valitaan poisto, huoneen structi alustetaan uudestaan oletusarvoilla (tyhjillä), mukaan lukien varaustilanne vapaaksi 
					{
						temp_room[r_room_index].room_size_struct = 0;
						temp_room[r_room_index].room_number_struct = 0;
						temp_room[r_room_index].name = "N/A";
						temp_room[r_room_index].cost_per_night = 0;
						temp_room[r_room_index].cost_final = 0;
						temp_room[r_room_index].discount_percentage = 0;
						temp_room[r_room_index].vacant = true;
						temp_room[r_room_index].nights = 0;
						temp_room[r_room_index].reservation_number = 0;

						cout << "\nVaraus poistettu! Palataan päänäkymään.\n\n";
						cout << "\n--------------------------------------------------------------------\n\n";

						return temp_room[r_room_index];

					}

					else if (r_action == "2")
					{
						cout << "\nVarausta ei poistettu! Palataan päänäkymään.\n\n";
						cout << "\n--------------------------------------------------------------------\n\n";
						return temp_room[r_room_index];
						break;
					}
				}

			}

			cout << "\nVarausta ei löytynyt. Palataan päänäkymään.\n\n";
			cout << "\n--------------------------------------------------------------------\n\n";
			return temp_room[200];
			break;



		}

		else if (r_action == "2")
		{
			cout << "\nSyötä nimi, jolla varaus on tehty (muista isot alkukirjaimet): ";
			cin.ignore();
			getline(cin, name_choice);

			for (int i = 0; i < 200; i++) // Käy läpi kaikki huoneet josko löytyisi varaus kyseisellä nimellä
			{
				if (temp_room[i].name == name_choice) // Jos löytyy niin printtaa varauksen tiedot ja päästää poistovalintaan
				{
					int r_room_index = i;

					string vacancyYNfunc;

					if (temp_room[r_room_index].vacant == false)
					{
						vacancyYNfunc = "Varattu";
					}
					else
					{
						vacancyYNfunc = "Vapaa";
					}

					cout << "\n****************************************************\n";

					cout << endl << "Varauksesi tiedot:" << endl
						<< "Varaajan nimi: " << temp_room[r_room_index].name << endl
						<< "Huonekoko: " << temp_room[r_room_index].room_size_struct << ":n hengen huone" << endl
						<< "Huonenumero: " << temp_room[r_room_index].room_number_struct << endl
						<< "Hinta per yö: " << temp_room[r_room_index].cost_per_night << endl
						<< "Öiden määrä: " << temp_room[r_room_index].nights << endl
						<< "Alennusprosentti: " << temp_room[r_room_index].discount_percentage << endl
						<< "Loppusumma: " << temp_room[r_room_index].cost_final << endl
						<< "Varaustilanne: " << vacancyYNfunc << endl
						<< "Varausnumero: " << temp_room[r_room_index].reservation_number << endl;

					cout << "\n****************************************************\n";


					cout << "\n\nHaluatko poistaa varauksesi? (1 = Kyllä / 2 = Ei): ";
					cin >> r_action;


					if (r_action == "1") // Jos valitaan poisto, huoneen structi alustetaan uudestaan oletusarvoilla (tyhjillä), mukaan lukien varaustilanne vapaaksi 
					{
						temp_room[r_room_index].room_size_struct = 0;
						temp_room[r_room_index].room_number_struct = 0;
						temp_room[r_room_index].name = "N/A";
						temp_room[r_room_index].cost_per_night = 0;
						temp_room[r_room_index].cost_final = 0;
						temp_room[r_room_index].discount_percentage = 0;
						temp_room[r_room_index].vacant = true;
						temp_room[r_room_index].nights = 0;
						temp_room[r_room_index].reservation_number = 0;

						cout << "\nVaraus poistettu! Palataan päänäkymään.\n\n";
						cout << "\n--------------------------------------------------------------------\n\n";
						return temp_room[r_room_index];

					}

					else if (r_action == "2")
					{
						cout << "\nVarausta ei poistettu! Palataan päänäkymään.\n\n";
						cout << "\n--------------------------------------------------------------------\n\n";
						return temp_room[r_room_index];
						break;
					}
				}


			}

			// Jos varausta ei löydy, palataan takaisin päämenuun

			cout << "\nVarausta ei löytynyt. Palataan päänäkymään.\n\n";
			cout << "\n--------------------------------------------------------------------\n\n";
			return temp_room[200];
			break;


		}


		else
		{
			cin.clear(); // Tyhjennetään cin bad input flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoretaan aiempi syöte kokonaan

			cout << "\nVirheellinen syöte! Valitse joko 1 tai 2. Käytä vain numeronäppäimiä.\n\n\n";

		}

	}


	return temp_room[200];
}







//----------------------------------------------------------------------------------------------------------



// Randomisoi alennuksen määrän





float discount_randomizer() {


	int random = 0;

	float discount = 0;

	srand((unsigned)time(NULL));


	random = 1 + rand() % 3;

	switch (random)
	{
	case 1:
		discount = 0.00;
		break;

	case 2:
		discount = 0.10;
		break;

	case 3:
		discount = 0.20;
		break;
	}

	return discount;

}





//----------------------------------------------------------------------------------------------------------


//Käy läpi kaikkien huoneiden varaustilanteet




bool vacancyALL(Rooms room[]) {

	for (int i = 0; i < 200; i++)
	{
		if (room[i].vacant == true)
		{
			return true;
			break;
		}

		else
		{
			return false;
		}

	}
}



//----------------------------------------------------------------------------------------------------------


// Käy läpi yhden hengen huoneiden varaustilanteet


bool vacancy_one_bed(Rooms room[]) {

	for (int i = 0; i < 100; i++)
	{
		if (room[i].vacant == true)
		{
			return true;
			break;
		}

		else
		{
			return false;
		}

	}
}



//----------------------------------------------------------------------------------------------------------

// Käy läpi kahden hengen huoneiden varaustilanteet


bool vacancy_two_bed(Rooms room[]) {

	for (int i = 100; i < 200; i++)
	{
		if (room[i].vacant == true)
		{
			return true;
			break;
		}

		else
		{
			return false;
		}

	}
}



//----------------------------------------------------------------------------------------------------------



//Funktio, joka käy yksitellen stringing (inputin) joka kohdan ja tarkistaa sisältääkö pelkästään numeroita, estää laittamasta kirjaimia numeroiden sekaan




bool is_only_numbers(string string_test) {
	for (int i = 0; i < string_test.length(); i++)
		if (isdigit(string_test[i]) == false)
		{
			return false; // Jos löytyy jokin muu merkki kuin numero, palauttaa falsen tarkistuksesta
		}

	return true; // Muuten palauttaa truen
}