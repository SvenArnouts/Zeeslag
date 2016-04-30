/*
 * 
 *	@Author Sven Arnouts
 *  @Date 26-apr.-2016
 */

#include "Game.h"

//Constructor
Game::Game(int height_i, int width_i) {

	boardHeight = height_i;
	boardWidth = width_i;

	speler.setCoords(createCoords(Coordinates(1,1), 5, 'V'));

	spelbord.setDimensions(10, 10);
	spelbord.draw(speler.getCoords(), cpu.getWasHit(), cpu.getWasMissed(), speler.getWasHit(), speler.getWasMissed());
}


vector <Coordinates> Game::createCoords( Coordinates coord, int length, char dir) {
	int x = coord.getX();
	int y = coord.getY();
	vector <Coordinates> shipLoc {};

	if (dir != 'V' && dir != 'v' && dir != 'H' && dir != 'h'){
		cout << "De ingegeven richting van het schip is incorrect (V of H)." << endl;
	}

	else {
		if (dir == 'H' || dir == 'h') {
			for (int i = 1; i <= length; i++) {
				shipLoc.push_back(Coordinates(x, y));
				x++;
			}
		}
		else {
			for (int i = 1; i <= length; i++) {
				shipLoc.push_back(Coordinates(x, y));
				y++;
			}
		}
	}

	return shipLoc;
}
