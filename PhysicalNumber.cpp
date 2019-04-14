

#include <iostream>
#include <sstream>
#include <string>
#include "PhysicalNumber.h"
#include "Unit.h"

using namespace ariel;

PhysicalNumber::PhysicalNumber(double num, Unit type)
:_num(num),_type(type){} 

bool isSameDimension(PhysicalNumber& pNum1, PhysicalNumber& pNum2);
double convert(PhysicalNumber& pNum1, PhysicalNumber& pNum2);

/* Math operators */
const PhysicalNumber& PhysicalNumber::operator+(){
    return *this;
}
const PhysicalNumber& PhysicalNumber::operator+(const PhysicalNumber& pNum){
        
    if(!isSameDimension(*this,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
    
    Unit nType = this._type;
    double sum = this->_num + convert(*this,pNum);
    return PhysicalNumber(sum,nType);

}
PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& pNum){
    if(!isSameDimension(*this,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
    double sum = this->_num + convert(*this,pNum);
	this->_num = sum;
	return *this;
}
const PhysicalNumber& PhysicalNumber::operator-(){
    return PhysicalNumber(-this->_num, this->_type);
}
const PhysicalNumber& PhysicalNumber::operator-(const PhysicalNumber& pNum){
    if(!isSameDimension(*this,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
    
    Unit nType = this._type;
    double sum = this->_num - convert(*this,pNum);
    return PhysicalNumber(sum,nType);
}
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& pNum){
    if(!isSameDimension(*this,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
    double sum = this->_num - convert(*this,pNum);
	this->_num = sum;
	return *this;
}

/* Comparor operators */
bool ariel::operator<(const PhysicalNumber& pNum1, const PhysicalNumber& pNum2){
    if(!isSameDimension(*this,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (pNum1._num < convert(pNum2)){
		return true;
	}
	else{
		return false;
	}

}
bool ariel::operator>(const PhysicalNumber& pNum1, const PhysicalNumber& pNum2){
    if(!isSameDimension(*this,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (pNum1._num > convert(pNum2)){
		return true;
	}
	else{
		return false;
	}
}
bool ariel::operator<=(const PhysicalNumber& pNum1, const PhysicalNumber& pNum2){
    if(!isSameDimension(*this,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (pNum1._num <= convert(pNum2)){
		return true;
	}
	else{
		return false;
	}
}
bool ariel::operator>=(const PhysicalNumber& pNum1, const PhysicalNumber& pNum2){
    if(!isSameDimension(*this,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (pNum1._num >= convert(pNum2)){
		return true;
	}
	else{
		return false;
	}
}
bool ariel::operator!=(const PhysicalNumber& pNum1, const PhysicalNumber& pNum2){
    if(!isSameDimension(*this,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (pNum1._num != convert(pNum2)){
		return true;
	}
	else{
		return false;
	}
}
bool ariel::operator==(const PhysicalNumber& pNum1, const PhysicalNumber& pNum2){
    if(!isSameDimension(*this,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (pNum1._num == convert(pNum2)){
		return true;
	}
	else{
		return false;
	}
}

/* Increase/Decrease operators */
PhysicalNumber& PhysicalNumber::operator++(){
	this->_num++;
    return *this;
}
PhysicalNumber& PhysicalNumber::operator--(){
    this->_num--;
    return *this;
}
const PhysicalNumber PhysicalNumber::operator++(int pNum){
	PhysicalNumber cpy(this._num,this._type);
	cpy._num++;
    return cpy;
}
const PhysicalNumber PhysicalNumber::operator--(int pNum){
    PhysicalNumber cpy(this._num,this._type);
	cpy._num--;
    return cpy;
}

/* I/O operators */
std::ostream& ariel::operator<<(std::ostream& os, const PhysicalNumber& pNum){
    string str = unitType(pNum->_type);
	os<<pNum->_num << "[" << str << "]";
    return os;
}
std::istream& ariel::operator>>(std::istream& is, PhysicalNumber& pNum){
    return is;
}

// Checks if the Unit is from the same dimension
bool isSameDimension(const PhysicalNumber& pNum1,const PhysicalNumber& pNum2){

	if((pNum1->unit / 3) == (pNum2->unit / 3)){
		return true;
	}
	return false;
}

// 	Returns a string according to the Unit's number
string unitType(Unit unit){
	string type;

	switch(unit){
		case 0: type = "CM";
		break;
		case 1: type = "M";
		break;
		case 2: type = "KM";
		break;
		case 3: type = "SEC";
		break;
		case 4: type = "MIN";
		break;
		case 5: type = "HOUR";
		break;
		case 6: type = "G";
		break;
		case 7: type = "KG";
		break;
		case 8: type = "TON";
		break;
	}
	return type;
}


double convert(const PhysicalNumber pNum1,const PhysicalNumber pNum2){

	int type = (pNum1->unit)-(pNum2->unit);
	int ans;

	switch(type){
		// Converts 3rd option to the 1st
		case -2: 
			if(pNum2->unit == 2) 
				return pNum2->num*100000;
	
			else if(pNum2->unit == 5) 
				return pNum2->_num*3600;
			
			else
				return pNum2->_num*100000;	
		break;

		// Converts 3rd type to the 2nd
		case -1: 
			if(pNum2->unit == 2)
				return pNum2->_num*1000;
		
			else if(pNum2->unit == 5)
				return pNum2->_num*60;
		
			else 
				return pNum2->num*1000;	
		break;

		// No need for conversion
		case 0: return pNum2->num;
		break;

		// Converts 2nd type to the 1st
		case 1: 
			if(pNum2->unit == 1)
				return pNum2->_num*1000;

			else if(pNum2->unit == 4)
				return pNum2->_num*60;
		
			else 
				return pNum2->num*1000;
		break;

		// Converts 1st type to  the 3rd
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