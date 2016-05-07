/*
 * 
 *	@Author Sven Arnouts
 *  @Date 26-apr.-2016
 */

#include "Game.h"

//Constructor
Game::Game(const int& width, const int& height,
		const vector <string>& names_i, const vector <int>& lenghts_i, const vector <int>& numbers_i){

	//De deelnemende schepen met hun lengtes en hun aantallen.

	shipNames = names_i;
	shipLenghts = lenghts_i;
	numberOfShips = numbers_i;

	//Zet de dimensies voor het gameboard van de speler en de cpu.
	speler.setWidth(width);
	speler.setHeight(height);
	cpu.setWidth(width);
	cpu.setHeight(height);

	//Zet de dimensies en roep de benodigde vectors op voor het tekenen van het spelbord.
	spelbord.setDimensions(width, height);
	spelbord.draw(speler.getCoords(), cpu.getHit(), cpu.getMissed(), speler.getHit(), speler.getMissed());
}

//Functie die ingegeven startcoordinaten, lengte en richting omzet in de coordinaten voor een schip.
vector <Coordinates> Game::createCoords( Coordinates coord, int length, char dir) {
	int x = coord.getX();									//getter x-coordinaat
	int y = coord.getY();									//getter y-coordinaat
	vector <Coordinates> shipLoc {};						//initialiseer lege vector om coordinaten in te stoppen

	if (dir == 'H' || dir == 'h') {					//Horizontale richting
		for (int i = 1; i <= length; i++) {			//For loop die telkens coordinaten in de shipLoc vector steekt
			shipLoc.push_back(Coordinates(x, y));	//steeds met een increment van 1 voor x (horizontale richting)
			x++;
		}
	}
	else if (dir == 'V' || dir == 'v') {				//Verticale richting
		for (int i = 1; i <= length; i++) {				//For loop die telkens coordinaten in de shipLoc vector steekt
			shipLoc.push_back(Coordinates(x, y));		//steeds met een increment van 1 voor y (verticale richting)
			y++;
		}
	}
	return shipLoc;
}

void Game::gameloop() {

	cout << "De grootte van het spelbord bedraagd " << speler.getWidth() << " op " << speler.getHeight() << "." << endl;
	cout << "Volgende schepen nemen deel aan het spel:" << endl;
	for (unsigned int i = 0; i < shipNames.size(); i++) {
		cout << shipNames[i] << "\t \t \t met lengte " << shipLenghts[i] << ": \t \t \t aantal " << numberOfShips[i] << endl;
	}

}
