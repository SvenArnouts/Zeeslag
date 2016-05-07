/*
 * 
 *	@Author Sven Arnouts
 *  @Date 29-apr.-2016
 */

#include "Game.h"
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main() {

	//Initialiseren van variabelen voor opnieuw starten spel
	bool repeat = false;									//stel de boolwaarde voor herhalen in op false
	string answer = "";										//initialiseer het antwoord


	do {
		cout << "Welkom bij het spel zeeslag." << endl;
		srand(time(NULL));														//Stel een nieuwe random seed in

		//Vraag om het configuratiebestand
		cout << "Geef de naam van het configuratiebestand in: " << endl;
		string config_i = "";
		cin >> config_i;

		//Testen of de ingegeven naam correct is.
		ifstream config {config_i.c_str()};
		if(!config) {
			cerr << "Het bestand kon niet worden ingelezen: ingegeven naam incorrect. "
					"Herstart het programme manueel." << endl;
			return (1);
		}

		//Inleesvariabelen
		string name_i = "";
		int length_i = 0;
		int number_i = 0;

		//Variabelen die meegegeven moeten worden aan het game object
		int width = 0;
		int height = 0;

		vector <string> shipNames;
		vector <int> shipLenghts;
		vector <int> numberOfShips;

		//Inlezen bestand
		cout << "Inlezen configuratiebestand.." << endl;
		string tekstregel;
		stringstream tekst;
		int regelnummer = 1;

		while( getline(config, tekstregel )) {
			if (tekstregel[0] != '#' && !tekstregel.empty() && tekstregel[0] != ' ') {
				tekst << tekstregel << endl;
				if (regelnummer == 1 ){
					tekst >> width >> height;
					regelnummer++;
				}
				else {
					tekst >> name_i >> length_i >> number_i;
					shipNames.push_back(name_i);
					shipLenghts.push_back(length_i);
					numberOfShips.push_back(number_i);
					regelnummer++;
				}
			}
		}
		//Maak het spel aan.
		cout << "Aanmaken spelbord.." << endl;
		Game zeeslag(width, height, shipNames, shipLenghts, numberOfShips);
		cout << "Het spel wordt gestart." << endl;
		zeeslag.gameloop();

		//Vraag of het spel opnieuw moet worden opgestart.
		cout << "Wilt u nogmaals spelen? (ja/nee)" << endl;
		cin >> answer;

		//Test voor het opnieuw opstarten van het spel.
		if (answer == "Ja" || answer == "ja") {										//antwoord ja
			cout << "Het spel wordt opnieuw gestart. Veel succes!" << endl;
			repeat = true;}															//boolwaarde naar true
		else if (answer == "nee" || answer == "Nee") {								//antwoord nee
			cout << "Tot een volgende keer!" << endl;
			repeat = false;															//boolwaarde naar false
		}
		else {																		//ongeldig antwoord (niet ja/nee)
			cout <<"Dit is geen geldig antwoord. Indien u nogmaals wil spelen, gelieve het spel manueel te herstarten." << endl;
			repeat = false;															//boolwaaarde naar false
		}

	} while (repeat);
	//Einde van het spel.
	cout << "Spel beëindigd." << endl;
	return 0;
}

