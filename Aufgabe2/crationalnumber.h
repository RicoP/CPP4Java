#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <stdio.h>

class RationalNumber {
	private: 
	int nominator;
    int denominator;

	public: 
	RationalNumber(int, int); 

	char isValid();
	char isNaN();
	char equal(RationalNumber const& b);
	char lessThan(RationalNumber const& b);
	RationalNumber multiply(RationalNumber const& b);
	RationalNumber divide(RationalNumber const& b);
	RationalNumber add(RationalNumber const& b);
	RationalNumber subtract(RationalNumber const& b);

	//Operatoren
	RationalNumber operator+(RationalNumber const& b);
	RationalNumber operator-(RationalNumber const& b);
	RationalNumber operator/(RationalNumber const& b);
	RationalNumber operator*(RationalNumber const& b);
	char operator==(RationalNumber const& b);
};

#endif // RATIONALNUMBER_H
