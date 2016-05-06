/*
 * 
 *	@Author Sven Arnouts
 *  @Date 19-apr.-2016
 */

#ifndef SHIP_H_
#define SHIP_H

#include "Coordinates.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ship {
public:

	Ship(const string& name_i , const int& length, const vector <Coordinates>& location);


	//getters & setters

	string getName() const {return name;}							//getter naam schip
	int getHealth() const {return health;}							//getter lengte schip
	vector<Coordinates> getLoc() const {return loc;} 				//getter coordinaten schip

	void setName(const string& name_i) {name = name_i;}
	void setHealth (const int& health_i) {health = health_i;}
	void setLoc (const vector <Coordinates>& location) {loc = location;}

	bool wasHit(const Coordinates& bomb);

private:

	string name;									//naam van het schip
	int health;										//levens van het schip (wanneer 0 => schip gezonken)
	vector<Coordinates> loc;						//vector met de coordinaten

};

#endif /* SHIP_H_ */
