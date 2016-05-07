/*
 * 
 *	@Author Sven Arnouts
 *  @Date 26-apr.-2016
 */

#ifndef GAME_H_
#define GAME_H_

#include "Coordinates.h"
#include "Graphics.h"
#include "Gameboard.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Game {

public:
	//Constructor
	Game(const int& width, const int& height,
			const vector <string>& names_i, const vector <int>& lenghts_i, const vector <int>& numbers_i);

	//Functie die het spel voorstelt.
	void gameloop();

	//Functie die coordinaten voor een schip creëert uit startcoordinaten, een lengte en een richting.
	vector <Coordinates> createCoords (Coordinates coord_i, int length, char direction);


private:

	Gameboard speler;
	Gameboard cpu;

	Graphics spelbord;

	vector <string> shipNames;
	vector <int> shipLenghts;
	vector <int> numberOfShips;
};

#endif /* GAME_H_ */
