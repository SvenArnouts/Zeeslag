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

	Ship(const string& name , const int& length, const char& direction);


	//getters & setters

	string getName() const {return name;}							//getter naam schip
	int getLength() const {return length;}							//getter lengte schip
	vector<Coordinates> getShipLoc() const {return ShipLoc;} 		//getter coordinaten schip

	void setName( string name_i) {name = name_i;}
	void setLength ( int length_i) {length = length_i;}
	bool validPlace(Coordinates beginCoord, int length, char direction);



private:

	string name;									//naam van het schip
	int length;										//lengte van het schip
													//ingegeven begincoordinaten
	char dir;										//richting waarin het ligt (horizontaal/verticaal)
	vector<Coordinates> ShipLoc;					//vector met de coordinaten

};

#endif /* SHIP_H_ */
