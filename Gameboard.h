/*
 * 
 *	@Author Sven Arnouts
 *  @Date 26-apr.-2016
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include "Coordinates.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Gameboard {

public:
	//Constructor
	Gameboard();

	//getters & setters
	vector <Coordinates> getWasHit() { return wasHit;}			//getter wasHit
	vector <Coordinates> getWasMissed() {return wasMissed;}		//getter wasMissed
	vector <Coordinates> getShips() {return ships;}				//getter Ships

	void addHit (Coordinates Hit) { wasHit.push_back (Hit); }		//voegt een hit toe
	void addMiss (Coordinates Miss) {wasMissed.push_back (Miss);}	//voegt een mis toe


private:
	vector <Coordinates> wasHit;			//coordinaten waar de speler geraakt is
	vector <Coordinates> wasMissed;			//coordinaten waar de speler werd gemist
	vector <Coordinates> ships;				//vector die de schepen van de schepen bevat
};

#endif /* GAMEBOARD_H_ */
