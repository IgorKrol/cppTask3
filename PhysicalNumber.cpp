#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include "PhysicalNumber.h"
#include "Unit.h"

using namespace ariel;

PhysicalNumber::PhysicalNumber(double num, Unit type)
:_num(num),_type(type){} 


/* Math operators */
const PhysicalNumber& PhysicalNumber::operator+(){
    return *this;
}
const PhysicalNumber& PhysicalNumber::operator+(const PhysicalNumber& pNum){
    return *this;
}
PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& pNum){
    return *this;
}
const PhysicalNumber& PhysicalNumber::operator-(){
    return *this;
}
const PhysicalNumber& PhysicalNumber::operator-(const PhysicalNumber& pNum){
    return *this;
}
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& pNum){
    return *this;
}

/* Comparor operators */
bool ariel::operator<(const PhysicalNumber& pNum1, const PhysicalNumber& pNum2){
    return true;
}
bool ariel::operator>(const PhysicalNumber& pNum1, const PhysicalNumber& pNum2){
    return true;
}
bool ariel::operator<=(const PhysicalNumber& pNum1, const PhysicalNumber& pNum2){
    return true;
}
bool ariel::operator>=(const PhysicalNumber& pNum1, const PhysicalNumber& pNum2){
    return true;
}
bool ariel::operator!=(const PhysicalNumber& pNum1, const PhysicalNumber& pNum2){
    return true;
}
bool ariel::operator==(const PhysicalNumber& pNum1, const PhysicalNumber& pNum2){
    return true;
}

/* Increase/Decrease operators */
PhysicalNumber& PhysicalNumber::operator++(){
    return *this;
}
PhysicalNumber& PhysicalNumber::operator--(){
    return *this;
}
const PhysicalNumber PhysicalNumber::operator++(int pNum){
    return *this;
}
const PhysicalNumber PhysicalNumber::operator--(int pNum){
    return *this;
}

/* I/O operators */
std::ostream& ariel::operator<<(std::ostream& os, const PhysicalNumber& pNum){
    return os;
}
std::istream& ariel::operator>>(std::istream& is, PhysicalNumber& pNum){
    return is;
}

// Checks if the Unit is from the same dimension
bool isSameDimension(PhysicalNumber& pNum1, PhysicalNumber& pNum2){
	// int a = unitType(pNum1->unit);
	// int b = unitType(pNum2->unit);

	if((pNum1->unit / 3) == (pNum2->unit / 3)){
		return true;
	}
	return false;
}

// // 	Returns a number according to the Unit's type
// int unitType(Unit unit){
// 	int type;

// 	switch(unit){
// 		case CM: type = 0;
// 		break;
// 		case M: type = 1;
// 		break;
// 		case KM: type = 2;
// 		break;
// 		case SEC: type = 3;
// 		break;
// 		case MIN: type = 4;
// 		break;
// 		case HOUR: type = 5;
// 		break;
// 		case G: type = 6;
// 		break;
// 		case KG: type = 7;
// 		break;
// 		case TON: type = 8;
// 		break;
// 	}

// 	return type;
// }


double convert(PhysicalNumber pNum1, PhysicalNumber pNum2){
	// int a = unitType(pNum1->unit);
	// int b = unitType(pNum2->unit);

	int type = (pNum1->unit)-(pNum2->unit);
	int ans;

	switch(type){
		// need to convert 3rd option to the first
		case -2: 
			if(pNum2->unit == 2) 
				return pNum2->num*100000;
	
			else if(pNum2->unit == 5) 
				return pNum2->_num*3600;
			
			else
				return pNum2->_num*100000;	
			
		break;
		// need to convert 3rd option to 2nd
		case -1: 
			if(pNum2->unit == 2)
				return pNum2->_num*1000;
		
			else if(pNum2->unit == 5)
				return pNum2->_num*60;
		
			else 
				return pNum2->num*1000;
			
		break;

		// no need for conversion
		case 0: return pNum2->num;
		break;

		// need to convert 2nd option to 1st
		case 1: 
			if(pNum2->unit == 1)
				return pNum2->_num*1000;

			else if(pNum2->unit == 4)
				return pNum2->_num*60;
		
			else 
				return pNum2->num*1000;
		break;

		// need to convert 1st option to 3rd
		case 2:
			if(pNum2->unit == 0)
				return pNum2->num/100000;
		
			else if(pNum2->unit == 3)
				return pnum2->num/3600;
		
			else 
				return pNum2->num/100000;
		
		break;
	}
}