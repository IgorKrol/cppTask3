#include <iostream>
#include "Unit.h"

using namespace ariel;
using namespace std;

// Checks if the Unit's type is from the same dimension
bool isSameDimension(const Unit& unit,const Unit& unit2){
	if((unit / 3) == (unit2 / 3)){
		return true;
	}
	return false;
}