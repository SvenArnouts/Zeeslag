/*
 * 
 *	@Author Sven Arnouts
 *  @Date 19-apr.-2016
 */

#include "Ship.h"

//Constructor
Ship::Ship(const string& name_i, const int& length, const vector <Coordinates>& location) {
	name = name_i;
	health = length;
	loc = location;
}

//Functie die checkt of het schip wordt geraakt.
bool Ship::wasHit(const Coordinates& bomb) {
	bool boolValue = false;

	for (int i = 0; i < health; i++){

		if (bomb.getX() == loc[i].getX() && bomb.getY() == loc[i].getY()){
			boolValue = true;
			loc.erase(loc.begin()+i);
			health -= 1;

			if (health == 0){ cout << "Het schip is gezonken.";}
		}
	}
	return boolValue;
}



