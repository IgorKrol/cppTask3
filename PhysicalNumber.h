// #pragma once

#include <iostream>
#include <sstream>
#include <string>
#include "Unit.h"


namespace ariel{
    class PhysicalNumber{

        double _num;
        Unit _type;

        public:
        PhysicalNumber(double, Unit);

        double getNum(){ return _num; }
        Unit getType(){ return _type; }

        /* Mathematical operators: +,-,=+,=-,(+),(-) */
        // Mathematical + operators:
        PhysicalNumber& operator+();
        PhysicalNumber& operator+(const PhysicalNumber&);
        PhysicalNumber& operator+=(const PhysicalNumber&);
        // Mathematical - operators:
        PhysicalNumber& operator-()const;
        PhysicalNumber& operator-(const PhysicalNumber&);
        PhysicalNumber& operator-=(const PhysicalNumber&);
        
        /* Mathematical comparison operators: <,>,<=,>=,!=,== */

        friend bool operator<(const PhysicalNumber&, const PhysicalNumber&);
        friend bool operator>(const PhysicalNumber&, const PhysicalNumber&);
        friend bool operator<=(const PhysicalNumber&, const PhysicalNumber&);
        friend bool operator>=(const PhysicalNumber&, const PhysicalNumber&);
        friend bool operator!=(const PhysicalNumber&, const PhysicalNumber&);
        friend bool operator==(const PhysicalNumber&, const PhysicalNumber&);

        /* prefix/postfix for ++/-- */
        // prefix
        PhysicalNumber& operator++();
        PhysicalNumber& operator--();
        // postfix
        const PhysicalNumber operator++(int);
        const PhysicalNumber operator--(int);
        
        /* IO operators */
        friend std::ostream& operator<<(std::ostream& os, const PhysicalNumber& pNum);
        friend std::istream& operator>>(std::istream& is, PhysicalNumber& pNum);

        // friend std::string unitType(const int unit);
        friend bool isSameDimension(const PhysicalNumber& pNum1,const PhysicalNumber& pNum2);
        friend double convert(const PhysicalNumber& pNum1,const PhysicalNumber& pNum2);
    };
}