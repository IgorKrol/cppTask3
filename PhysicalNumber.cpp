#include <iostream>
#include <sstream>
#include <string>

#include "PhysicalNumber.h"
#include "Unit.h"

using namespace ariel;
using namespace std;

// Constructor
PhysicalNumber::PhysicalNumber(double num, Unit type)
:_num(num),_type(type){} 

/* Math operators */
// Unaric +
PhysicalNumber PhysicalNumber::operator+() const{
    return PhysicalNumber(this->_num,this->_type);
}
// Returns the sum of the data of two given objects as a new object
PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& pNum) const{
        
    if(!isSameDimension(*this,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
    double sum = this->_num + convert(*this,pNum);
    return PhysicalNumber(sum,this->_type);

}
// Stores the sum of the data of two given objects in the 1st of them
PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& pNum){
    if(!isSameDimension(*this,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
    double sum = this->_num + convert(*this,pNum);
	this->_num = sum;
	return *this;
}
// Unaric -
PhysicalNumber PhysicalNumber::operator-()const{
    return PhysicalNumber(-(this->_num), this->_type);
}
// Returns the subtraction result of the data of two given objects as a new object
PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& pNum) const{
    if(!isSameDimension(*this,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
    
    Unit nType = this->_type;
    double sum = this->_num - convert(*this,pNum);
    return *new PhysicalNumber(sum,nType);
}
// Stores the subtraction result of the data of two given objects in the 1st of them
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& pNum){
    if(!isSameDimension(*this,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
    double sum = this->_num - convert(*this,pNum);
	this->_num = sum;
	return *this;
}

/* Compare operators */
// Checks if the 1st operand's data is smaller than the 2nd's
bool PhysicalNumber::operator<(const PhysicalNumber& pNum){
	PhysicalNumber cpy(this->_num, this->_type);
    if(!isSameDimension(cpy,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (cpy._num < convert(cpy,pNum)){
		return true;
	}
	else{
		return false;
	}

}
// Checks if the 1st operand's data is bigger than the 2nd's
bool PhysicalNumber::operator>(const PhysicalNumber& pNum){
	PhysicalNumber cpy(this->_num, this->_type);
    if(!isSameDimension(cpy,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (cpy._num > convert(cpy,pNum)){
		return true;
	}
	else{
		return false;
	}
}
// Checks if the 1st operand's data is smaller than the 2nd's or equal to him
bool PhysicalNumber::operator<=(const PhysicalNumber& pNum){
	PhysicalNumber cpy(this->_num, this->_type);
    if(!isSameDimension(cpy,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (cpy._num <= convert(cpy,pNum)){
		return true;
	}
	else{
		return false;
	}
}
// Checks if the 1st operand's data is bigger than the 2nd's or equal to him
bool PhysicalNumber::operator>=(const PhysicalNumber& pNum){
	PhysicalNumber cpy(this->_num, this->_type);
    if(!isSameDimension(cpy,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (cpy._num >= convert(cpy,pNum)){
		return true;
	}
	else{
		return false;
	}
}
// Checks if the 1st operand's data is not equal to the 2nd's
bool PhysicalNumber::operator!=(const PhysicalNumber& pNum){
	PhysicalNumber cpy(this->_num, this->_type);
    if(!isSameDimension(cpy,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (cpy._num != convert(cpy,pNum)){
		return true;
	}
	else{
		return false;
	}
}
// Checks if the 1st operand's data is equal to the 2nd's
bool PhysicalNumber::operator==(const PhysicalNumber& pNum){
	PhysicalNumber cpy(this->_num, this->_type);
    if(!isSameDimension(cpy,pNum)) {
        throw std::string ("ERROR: Different dimensions");
    }
	if (cpy._num == convert(cpy,pNum)){
		return true;
	}
	else{
		return false;
	}
}

/* Increase/Decrease operators */
// PREFIX
PhysicalNumber& PhysicalNumber::operator++(){
	++this->_num;
    return *this;
}
PhysicalNumber& PhysicalNumber::operator--(){
    --this->_num;
    return *this;
}
//POSTFIX
const PhysicalNumber PhysicalNumber::operator++(int pNum){
	PhysicalNumber temp(this->_num,this->_type);
	this->_num+=1;
    return temp;
}
const PhysicalNumber PhysicalNumber::operator--(int pNum){
	PhysicalNumber temp(this->_num,this->_type);
	this->_num-=1;
    return temp;
}

/* I/O operators */
// Gets a Physical Number object, translate its data to a string and sends it as a stream
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
// Gets a stream and translate it to a Physical Number (saves the data on an PN object)
std::istream& ariel::operator>>(std::istream& is, PhysicalNumber& pNum){
	
	string str, str2;
	double temp;

	ios::pos_type start_pos = is.tellg();
	is>>temp;
	is>>str;

	if(temp < 0){		// Rewind on error
		is.clear();	
		is.seekg(start_pos);	
		is.setstate(ios::failbit);			
	}

	else if(str.front() != '[' && str.back() != ']'){		// Rewind on error
		is.clear();	
		is.seekg(start_pos);	
		is.setstate(ios::failbit);						
	}

	else{	// concat the data-type between '[' ']' and stores the data and type on the physical number object
		str2 = str.substr(1, str.length()-2);

			if(str2 == "cm") {pNum._num = temp; pNum._type = CM;}
			else if(str2 == "m") {pNum._num = temp; pNum._type = M;}
			else if(str2 == "km") {pNum._num = temp; pNum._type = KM;}
			else if(str2 == "sec") {pNum._num = temp; pNum._type = SEC;}
			else if(str2 == "min") {pNum._num = temp; pNum._type = MIN;}
			else if(str2 == "hour") {pNum._num = temp; pNum._type = HOUR;}
			else if(str2 == "g") {pNum._num = temp; pNum._type = G;}
			else if(str2 == "kg") {pNum._num = temp; pNum._type = KG;}
			else if(str2 == "ton") {pNum._num = temp; pNum._type = TON;}
			else {cerr << "Invalid input" << endl;}
		}
    return is;
}

// Checks if the Unit's type is from the same dimension
bool ariel::isSameDimension(const PhysicalNumber& pNum1,const PhysicalNumber& pNum2){

	if((pNum1._type / 3) == (pNum2._type / 3)){
		return true;
	}
	return false;
}


// Converts between members of the same dimension (Length: cm, m, km. Time: sec, min, hour. Mass: g, kg, ton.)
double ariel::convert(const PhysicalNumber& pNum1,const PhysicalNumber& pNum2){

	int elementConType = (pNum1._type)-(pNum2._type);

	switch(elementConType){	// The case's number, is the degree of jump you need to take from the current element
		case -2: 
			if(pNum2._type == KM) 
				return pNum2._num*100000;		
	
			else if(pNum2._type == HOUR) 			
				return pNum2._num*3600;
			
			else
				return pNum2._num*1000000;		// TON TO G
		break;

		case -1: 
			if(pNum2._type == M)			
				return pNum2._num*100;

			else if(pNum2._type == KM)			
				return pNum2._num*1000;		
		
			else if(pNum2._type == MIN || pNum2._type == HOUR)	
				return pNum2._num*60;
		
			else 
				return pNum2._num*1000;			// KG TO G OR TON TO KG

		break;

		// No need for conversion
		case 0: return pNum2._num;			
		break;

		case 1: 
			if(pNum2._type == CM) 		
				return pNum2._num/100;

			else if (pNum2._type == M)	
				return pNum2._num/1000;
			
			else if(pNum2._type == SEC || pNum2._type == MIN)			
				return pNum2._num/60;
		
			else 
				return pNum2._num/1000;					// G TO KG OR KG TO TON
		break;

		case 2:
			if(pNum2._type == CM)			
				return pNum2._num/100000;			
		
			else if(pNum2._type == SEC)		
				return pNum2._num/3600;				
		
			else 
				return pNum2._num/1000000;			// G TO TON
		break;
	}
	return 0;
}