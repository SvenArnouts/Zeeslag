/*
 * 
 *	@Author Sven Arnouts
 *  @Date 26-apr.-2016
 */

#ifndef GAME_H_
#define GAME_H_

#include "Ship.h"
#include "Coordinates.h"
#include "Graphics.h"
#include "Gameboard.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Game {

public:
	Game(int boardHeight, int boardWidth);

	vector <Coordinates> createCoords (Coordinates coord_i, int length, char direction);


private:
	int boardHeight;
	int boardWidth;

	Gameboard speler;
	Gameboard cpu;

};

#endif /* GAME_H_ */
