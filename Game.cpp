/*
 * 
 *	@Author Sven Arnouts
 *  @Date 26-apr.-2016
 */

#include "Ship.h"
#include "Coordinates.h"
#include "Game.h"
#include "Graphics.h"
#include "Gameboard.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Constructor
Game::Game(int height_i, int width_i) {
	boardHeight = height_i;
	boardWidth = width_i;

	Graphics spelbord;
	spelbord.setDimensions(10, 10);
	spelbord.draw(speler.getShips(), cpu.getWasHit(), cpu.getWasMissed(), speler.getWasHit(), speler.getWasMissed());
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
				cout << x << endl;
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
