/*
 * 
 *	@Author Sven Arnouts
 *  @Date 26-apr.-2016
 */

#ifndef GAMEBOARD_H_
#define GAMEBOARD_H_

#include "Coordinates.h"
#include "Ship.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Gameboard {

public:
	//Default constructor
	Gameboard() : boardWidth(10), boardHeight(10) {}
	//Constructor
	Gameboard(const int& width, const int& height) : boardWidth (width), boardHeight (height) {}

	//getters & setters
	vector <Coordinates> getHit() { return hit;}					//getter hits
	vector <Coordinates> getMissed() {return missed;}				//getter misses
	vector <Coordinates> getCoords() {return allCoords;}			//getter schipcoordinaten
	int getWidth() {return boardWidth;}								//getter breedte spelbord
	int getHeight() {return boardHeight;}							//getter hoogte spelbord

	void setWidth(const int& width) {boardWidth = width;}			//setter breedte spelbord
	void setHeight(const int& height) {boardHeight = height;}		//setter hoogte spelbord

	bool validBomb (const Coordinates& bomb);							//bom-coordinaten nog niet gebruikt/binnen het spelbord?
	bool isAHit (const Coordinates& bomb);								//Checkt of een bom een hit of een miss is.
	void addMiss (const Coordinates& bomb) {missed.push_back (bomb);}	//voegt een mis toe
	void addHit (const Coordinates& bomb);								//voegt een hit toe

	bool validShip(const vector <Coordinates>& ship);				//schip-coordinaten nog niet gebruikt/binnen het spelbord?
	void addShip(const string& name, const int& lenght,				//voegt schipcoordinaten toe aan spelbord, voegt schip toe aan vector
			const vector <Coordinates>& location);

	bool gameOver();						//Checkt of alle schepen gezonken zijn, ifso => game is over
private:
	vector <Coordinates> hit;				//coordinaten waar de speler geraakt is
	vector <Coordinates> missed;			//coordinaten waar de speler werd gemist
	vector <Coordinates> allCoords;			//vector die alle coordinaten van de schepen bevat

	int boardWidth;							//breedte van het spelbord (x-coordinaat)
	int boardHeight;						//hoogte van het spelbord (y-coordinaat)

	vector <Ship> ships;					//Bevat de schepen
};

#endif /* GAMEBOARD_H_ */
