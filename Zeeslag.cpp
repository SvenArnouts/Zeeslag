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


	bool repeat = false;
	string answer;

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

