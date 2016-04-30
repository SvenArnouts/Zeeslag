/*
 * 
 *	@Author Sven Arnouts
 *  @Date 26-apr.-2016
 */

#include "Gameboard.h"

Gameboard::Gameboard() {
}

void Gameboard::setCoords(vector <Coordinates> shipLoc) {
	for (signed int i = 0; i < shipLoc.size(); i++) {
		allCoords.push_back(shipLoc[i]);
	}
}
/**Functie die kijkt of de ingegeven coordinaten voor een schip binnen het spelbord vallen
	en niet reeds ingenomen worden door een ander schip.
 */
bool Gameboard::validCoords(vector <Coordinates> shipLoc) {
	bool boolValue = true;											//Initialiseer de waarde op true

	for (int i = 0; i < shipLoc.size(); i++){						//for-loop die door alle nieuwe coordinaten loopt
		for (int j = 0; j < allCoords.size(); j++){					//for-loop die door alle reeds bestaande coordinaten loopt

			int xNew = shipLoc[i].getX();							//getter voor de nieuwe x-coordinaat
			int yNew = shipLoc[i].getY();							//getter voor de nieuwe y-coordinaat
			int x = allCoords[j].getX();							//getter voor de reeds bestaande x-coordinaat
			int y = allCoords[j].getY();							//getter voor de reeds bestaande y-coordinaat



			/* De boolValue wordt veranderd naar false indien de nieuwe x- of y-coordinaat groter is dan 10, of wanneer
			 * de coordinaten gelijk zijn aan een reeds bestaande coordinaat.
			 */
			if (xNew > 10 || yNew > 10 || (xNew == x && yNew == y)){
				boolValue = false;
			}
		}
	}
	return boolValue;
}











