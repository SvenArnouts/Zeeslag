/*
 * 
 *	@Author Sven Arnouts
 *  @Date 26-apr.-2016
 */

#include "Gameboard.h"


/**Functie die kijkt of de ingegeven coordinaten voor een schip binnen het spelbord vallen
	en niet reeds ingenomen worden door een ander schip.
 */
bool Gameboard::validShip(const vector <Coordinates>& ship) {
	bool boolValue = true;															//Initialiseer de waarde op true

	if (ship.size() == 0){															//Checkt of de ingegeven richting wel correct is.
		boolValue = false;
		cout << "De ingegeven richting van het schip is incorrect (niet gelijk aan V of H). "
				"Geef opnieuw coordinaten in." << endl;
	}

	for (unsigned int i = 0; i < ship.size(); i++){					//for-loop die door alle nieuwe coordinaten loopt
		while (boolValue == true) {
			//Check of de coordinaten binnen het spelbord vallen.
			if (ship[i].getX() > boardWidth || ship[i].getY() > boardHeight
					|| ship[i].getX() < 0 || ship[i].getY() < 0){
				boolValue = false;
				cout << "Het schip kan niet worden geplaatst. "
						"Coordinaten van het schip bevinden zich buiten het spelbord. Geef opnieuw coordinaten in." << endl;
			}
			else {
				for (unsigned int j = 0; j < allCoords.size(); j++){		//for-loop die door alle reeds bestaande coordinaten loopt

					//Check of de coordinaten niet reeds worden ingenomen door een ander schip.
					if (ship[i].getX() == allCoords[j].getX() && ship[i].getY() == allCoords[j].getY()) {
						boolValue = false;
						cout << "Het schip kan niet worden geplaatst. "
								"Coordinaten van het schip worden reeds ingenomen door een ander schip. "
								"Geef opnieuw coordinaten in." << endl;
					}
				}
			}
		}
	}
	return boolValue;												//Geef de boolwaarde terug
}

//Functie die coordinaten toevoegt aan het spelbord
void Gameboard::addShip(const string& name, const int& length, const vector <Coordinates>& location) {
	Ship ship(name, length, location);
	ships.push_back(ship);

	for (unsigned int i = 0; i < location.size(); i++) {
		allCoords.push_back(location[i]);
	}
}

//Functie die checkt of een bom op een valabele plaats geplaatst wordt
bool Gameboard::validBomb(const Coordinates& bomb) {
	bool boolValue = true;											//Initialiseer de waarde op true

	if (bomb.getX() > boardWidth || bomb.getY() > boardHeight		//Check of de ingegeven coordinaat binnen het spelbord valt
			|| bomb.getX() < 0 || bomb.getY() < 0){
		boolValue = false;
	}

	//Volgende 2 for loops checken of er niet reeds gevuurd (hit of miss) is op de coordinaat.
	for (unsigned int i = 0; i < hit.size(); i++) {

		if ((bomb.getX() == hit[i].getX()) && (bomb.getY() == hit[i].getY())) {
			boolValue = false;
		}
	}

	for (unsigned int i = 0; i < missed.size(); i++) {

		if ((bomb.getX() == missed[i].getX()) && (bomb.getY() == missed[i].getY())) {
			boolValue = false;
		}
	}
	return boolValue;
}
//Functie die checkt of een schot raak is of niet.
bool Gameboard::isAHit(const Coordinates& bomb){
	bool boolValue = false;												//Stel boolwaarde in op false

	for (unsigned int i = 0; i < allCoords.size(); i++) {				//For-loop over de coordinaten van alle schepen
		if (bomb.getX() == allCoords[i].getX() 							//Check of de bomlocatie gelijk is aan die van een schip
				&& bomb.getY() == allCoords[i].getY()) {
			boolValue = false;											// if so, boolwaarde => true
		}
	}
	return boolValue;
}

//Functie die een hit toevoegt aan het spelbord en over de schepen loopt om te kijken of het
void Gameboard::addHit (const Coordinates& bomb) {
	hit.push_back(bomb);												//Voeg een hit toe

	for (Ship x : ships) {												//Check of een schip gezonken is
		x.wasHit(bomb);
	}
}

//Functie die checkt of alle schepen gezonken zijn
bool Gameboard :: gameOver() {
	bool boolValue = false;												//Stel boolwaarde in op false

	if (hit.size() == allCoords.size()) {boolValue = true;}

	return boolValue;
}




