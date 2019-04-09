
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
