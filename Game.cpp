/*
 * 
 *	@Author Sven Arnouts
 *  @Date 26-apr.-2016
 */

#include "Game.h"

//Constructor
Game::Game(int width, int height) {

	//Zet de dimensies voor het gameboard van de speler en de cpu.
	speler.setWidth(width);
	speler.setHeight(height);
	cpu.setWidth(width);
	cpu.setHeight(height);

	speler.addShip("a", createCoords(Coordinates(6,10), 5, 'H'));
	speler.addHit(Coordinates(6, 10));

	//Zet de dimensies en roep de benodigde vectors op voor het tekenen van het spelbord.
	spelbord.setDimensions(width, height);
	spelbord.draw(speler.getCoords(), cpu.getHit(), cpu.getMissed(), speler.getHit(), speler.getMissed());
}

//Functie die ingegeven startcoordinaten, lengte en richting omzet in de coordinaten voor een schip.
vector <Coordinates> Game::createCoords( Coordinates coord, int length, char dir) {
	int x = coord.getX();									//getter x-coordinaat
	int y = coord.getY();									//getter y-coordinaat
	vector <Coordinates> shipLoc {};						//initialiseer lege vector om coordinaten in te stoppen

	if (dir != 'V' && dir != 'v' && dir != 'H' && dir != 'h'){						//Checkt of de ingegeven richting wel correct is.
		cout << "De ingegeven richting van het schip is incorrect (V of H)." << endl;
	}

	else {
		if (dir == 'H' || dir == 'h') {					//Horizontale richting
			for (int i = 1; i <= length; i++) {			//For loop die telkens coordinaten in de shipLoc vector steekt
				shipLoc.push_back(Coordinates(x, y));	//steeds met een increment van 1 voor x (horizontale richting)
				x++;
			}
		}
		else {												//Verticale richting
			for (int i = 1; i <= length; i++) {				//For loop die telkens coordinaten in de shipLoc vector steekt
				shipLoc.push_back(Coordinates(x, y));		//steeds met een increment van 1 voor y (verticale richting)
				y++;
			}
		}
	}

	return shipLoc;
}

void Game::Gameloop() {
	if (speler.validShip(createCoords(Coordinates(1,10), 5, 'V')) == true) {
	speler.addShip("vliegdekschip", createCoords(Coordinates(1,1), 5, 'V'));
}
else {
	cout << "Het schip kan niet worden geplaatst."
			<<"\n Het bevindt zich niet binnen het spelbord of valt samen met een reeds bestaand schip."
			<< "\n Geef opnieuw coordinaten in." << endl;

}
}
