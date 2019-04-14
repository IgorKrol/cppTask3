#include <iostream>
#include <sstream>
#include <string>

#include "PhysicalNumber.h"
#include "Unit.h"

using namespace ariel;
using namespace std;

PhysicalNumber::PhysicalNumber(double num, Unit type)
:_num(num),_type(type){} 

// bool isSameDimension(PhysicalNumber& pNum1, PhysicalNumber& pNum2);
// double convert(PhysicalNumber& pNum1, PhysicalNumber& pNum2);

/* Math operators */
const PhysicalNumber& PhysicalNumber::operator+(){
    return *this;
}
const PhysicalNumber& PhysicalNumber::operator+(const PhysicalNumber& pNum){
        
    if(!isSameDimension(*this,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
    
    Unit nType = this->_type;
    double sum = this->_num + convert(*this,pNum);
    return *new PhysicalNumber(sum,nType);

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
    return *new PhysicalNumber(-this->_num, this->_type);
}
const PhysicalNumber& PhysicalNumber::operator-(const PhysicalNumber& pNum){
    if(!isSameDimension(*this,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
    
    Unit nType = this->_type;
    double sum = this->_num - convert(*this,pNum);
    return *new PhysicalNumber(sum,nType);
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
    if(!isSameDimension(pNum1,pNum2)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (pNum1._num < convert(pNum1,pNum2)){
		return true;
	}
	else{
		return false;
	}

}
bool ariel::operator>(const PhysicalNumber& pNum1, const PhysicalNumber& pNum2){
    if(!isSameDimension(pNum1,pNum2)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (pNum1._num > convert(pNum1,pNum2)){
		return true;
	}
	else{
		return false;
	}
}
bool ariel::operator<=(const PhysicalNumber& pNum1, const PhysicalNumber& pNum2){
    if(!isSameDimension(pNum1,pNum2)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (pNum1._num <= convert(pNum1,pNum2)){
		return true;
	}
	else{
		return false;
	}
}
bool ariel::operator>=(const PhysicalNumber& pNum1, const PhysicalNumber& pNum2){
    if(!isSameDimension(pNum1,pNum2)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (pNum1._num >= convert(pNum1,pNum2)){
		return true;
	}
	else{
		return false;
	}
}
bool ariel::operator!=(const PhysicalNumber& pNum1, const PhysicalNumber& pNum2){
    if(!isSameDimension(pNum1,pNum2)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (pNum1._num != convert(pNum1,pNum2)){
		return true;
	}
	else{
		return false;
	}
}
bool ariel::operator==(const PhysicalNumber& pNum1, const PhysicalNumber& pNum2){
    if(!isSameDimension(pNum1,pNum2)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (pNum1._num == convert(pNum1,pNum2)){
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
	PhysicalNumber cpy(this->_num,this->_type);
	cpy._num++;
    return cpy;
}
const PhysicalNumber PhysicalNumber::operator--(int pNum){
    PhysicalNumber cpy(this->_num,this->_type);
	cpy._num--;
    return cpy;
}

/* I/O operators */
std::ostream& ariel::operator<<(std::ostream& os, const PhysicalNumber& pNum){
	string sType;
	switch(pNum._type){
		case 0: sType = "cm";
		break;
		case 1: sType = "m";
		break;
		case 2: sType = "km";
		break;
		case 3: sType = "sec";
		break;
		case 4: sType = "min";
		break;
		case 5: sType = "hour";
		break;
		case 6: sType = "g";
		break;
		case 7: sType = "kg";
		break;
		case 8: sType = "ton";
		break;
	}
	os<<pNum._num << "[" << sType << "]";
    return os;
}
std::istream& ariel::operator>>(std::istream& is, PhysicalNumber& pNum){
	
	string temp, temp2;
	double t;

	input>>t;
	input>>temp;

	if(t < 0){
		cerr << "This number is invalid";
	}
	else if(temp.front() != '[' && temp.back() != ']'){
		cerr << "Invalid input";
	}

	else{
		temp2 = temp.substr(1, s.length()-2);

		switch(temp2){
			case(temp2 == "cm"): {pNum._num = t; pNum._type = CM; break;}
			case(temp2 == "m"): {pNum._num = t; pNum._type = M; break;}
			case(temp2 == "km"): {pNum._num = t; pNum._type = KM; break;}
			case(temp2 == "sec"): {pNum._num = t; pNum._type = SEC; break;}
			case(temp2 == "min"): {pNum._num = t; pNum._type = MIN; break;}
			case(temp2 == "hour"): {pNum._num = t; pNum._type = HOUR; break;}
			case(temp2 == "g"): {pNum._num = t; pNum._type = G; break;}
			case(temp2 == "kg"): {pNum._num = t; pNum._type = KG; break;}
			case(temp2 == "ton"): {pNum._num = t; pNum._type = TON; break;}
			default: {cerr << "Invalid input"; break;}
		}
	}
    return is;
}

// Checks if the Unit is from the same dimension
bool ariel::isSameDimension(const PhysicalNumber& pNum1,const PhysicalNumber& pNum2){

	if((pNum1._type / 3) == (pNum2._type / 3)){
		return true;
	}
	return false;
}

// 	Returns a string according to the Unit's number
// string ariel::unitType(const int unit){

// 	switch(unit){
// 		case 0: return "CM";
// 		break;
// 		case 1: return "M";
// 		break;
// 		case 2: return "KM";
// 		break;
// 		case 3: return "SEC";
// 		break;
// 		case 4: return "MIN";
// 		break;
// 		case 5: return "HOUR";
// 		break;
// 		case 6: return "G";
// 		break;
// 		case 7: return "KG";
// 		break;
// 		case 8: return "TON";
// 		break;
// 	}
// 	return "";
// }


double ariel::convert(const PhysicalNumber& pNum1,const PhysicalNumber& pNum2){

	int type = (pNum1._type)-(pNum2._type);
	int ans;

	switch(type){
		// Converts 3rd option to the 1st
		case -2: 
			if(pNum2._type == 2) 
				return pNum2._num*100000;
	
			else if(pNum2._type == 5) 
				return pNum2._num*3600;
			
			else
				return pNum2._num*100000;	
		break;

		// Converts 3rd type to the 2nd
		case -1: 
			if(pNum2._type == 2)
				return pNum2._num*1000;
		
			else if(pNum2._type == 5)
				return pNum2._num*60;
		
			else 
				return pNum2._num*1000;	
		break;

		// No need for conversion
		case 0: return pNum2._num;
		break;

		// Converts 2nd type to the 1st
		case 1: 
			if(pNum2._type == 1)
				return pNum2._num*1000;

			else if(pNum2._type == 4)
				return pNum2._num*60;
		
			else 
				return pNum2._num*1000;
		break;

		// Converts 1st type to  the 3rd
		case 2:
			if(pNum2._type == 0)
				return pNum2._num/100000;
		
			else if(pNum2._type == 3)
				return pNum2._num/3600;
		
			else 
				return pNum2._num/100000;
		break;
	}
	return 0;
}