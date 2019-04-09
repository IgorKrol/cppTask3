#pragma once

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

        /* Mathematical operators: +,-,=+,=-,(+),(-) */
        // Mathematical + operators:
        const PhysicalNumber& operator+();
        const PhysicalNumber& operator+(const PhysicalNumber&);
        PhysicalNumber& operator+=(const PhysicalNumber&);
        // Mathematical - operators:
        const PhysicalNumber& operator-();
        const PhysicalNumber& operator-(const PhysicalNumber&);
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

    };
}