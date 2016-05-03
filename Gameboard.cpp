/*
 * 
 *	@Author Sven Arnouts
 *  @Date 26-apr.-2016
 */

#include "Gameboard.h"

//Functie die coordinaten toevoegt aan het spelbord
void Gameboard::addShip(string name, vector <Coordinates> ship) {
	ships.push_back(name);

	for (unsigned int i = 0; i < ship.size(); i++) {
		allCoords.push_back(ship[i]);
	}
}
/**Functie die kijkt of de ingegeven coordinaten voor een schip binnen het spelbord vallen
	en niet reeds ingenomen worden door een ander schip.
 */
bool Gameboard::validShip(vector <Coordinates> ship) {
	bool boolValue = true;											//Initialiseer de waarde op true

	for (unsigned int i = 0; i < ship.size(); i++){					//for-loop die door alle nieuwe coordinaten loopt

		//Check of de coordinaten binnen het spelbord vallen.
		if (ship[i].getX() > boardWidth || ship[i].getY() > boardHeight){
			boolValue = false;
		}
		else {
			for (unsigned int j = 0; j < allCoords.size(); j++){		//for-loop die door alle reeds bestaande coordinaten loopt

				//Check of de coordinaten niet reeds worden ingenomen door een ander schip.
				if (ship[i].getX() == allCoords[j].getX() && ship[i].getY() == allCoords[j].getY()) {
					boolValue = false;
				}
			}
		}
	}
	return boolValue;												//Geef de boolwaarde terug
}

//Functie die checkt of een bom op een valabele plaats geplaatst wordt
bool Gameboard::validBomb(Coordinates bomb) {
	bool boolValue = true;											//Initialiseer de waarde op true

	if (bomb.getX() > boardWidth || bomb.getY() > boardHeight){		//Check of de ingegeven coordinaat binnen het spelbord valt
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







