#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <stdio.h>

namespace rnum { 
class RationalNumber {
	private: 
	int nominator;
    int denominator;

	public: 
	RationalNumber(); 
	RationalNumber(int); 
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

	RationalNumber operator+(int const& b);
	RationalNumber operator-(int const& b);
	RationalNumber operator/(int const& b);
	RationalNumber operator*(int const& b);

	RationalNumber operator -() const;

	char operator>(RationalNumber const& b);
	char operator>=(RationalNumber const& b);
	char operator<(RationalNumber const& b);
	char operator<=(RationalNumber const& b);

	char operator> (int const& b);
	char operator>=(int const& b);
	char operator< (int const& b);
	char operator<=(int const& b);

	char operator> (double const& b);
	char operator>=(double const& b);
	char operator< (double const& b);
	char operator<=(double const& b);

	char operator==(RationalNumber const& b);
	char operator==(double const& b);
	RationalNumber operator=(int const& b);
	operator double() const;
};
}
#endif // RATIONALNUMBER_H
