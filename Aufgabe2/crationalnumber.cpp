#include "crationalnumber.h"

rnum::RationalNumber::RationalNumber() 
	: nominator(0), denominator(0)
{}

rnum::RationalNumber::RationalNumber(int n) 
	: nominator(n), denominator(1)
{}

rnum::RationalNumber::RationalNumber(int nom, int denom) 
	: nominator(nom), denominator(denom)
{}

char rnum::RationalNumber::isValid() {
    return denominator != 0;
}

char rnum::RationalNumber::isNaN() {
    return !this->isValid();
}

char rnum::RationalNumber::equal(rnum::RationalNumber const& b) {
    return this->nominator * b.denominator == this->denominator * b.nominator;
}

char rnum::RationalNumber::lessThan(rnum::RationalNumber const& b) {
    if( (b.denominator > 0 && this->denominator > 0) || (b.denominator < 0 && this->denominator < 0) )
        return this->nominator * b.denominator < this->denominator * b.nominator;
    else
        return this->nominator * b.denominator > this->denominator * b.nominator;
}

rnum::RationalNumber rnum::RationalNumber::multiply(rnum::RationalNumber const& b) {
    rnum::RationalNumber e(
        nominator * b.nominator,
        denominator * b.denominator
    );

    return e;
}

rnum::RationalNumber rnum::RationalNumber::divide(rnum::RationalNumber const& b){
    rnum::RationalNumber e(
        nominator * b.denominator,
        denominator * b.nominator
    );

    return e;
}

static 
int ggT(int a, int b) {
	if(a < 0) 
		return ggT(-a,b); 

	if(b < 0)
		return ggT(a,-b); 

    if(b==0)
        return a;
    else
        return ggT(b, a%b);   
}

rnum::RationalNumber rnum::RationalNumber::add(rnum::RationalNumber const& b) {
	int nom = nominator * b.denominator + denominator*b.nominator;
	int denom = denominator * b.denominator;

	int ggt = ggT(nom, denom); 

    rnum::RationalNumber ret(
		nom / ggt, 
		denom / ggt 
    );

    return ret;
}

rnum::RationalNumber rnum::RationalNumber::subtract(rnum::RationalNumber const& b) {
    rnum::RationalNumber c(-b.nominator, b.denominator);
	return this->add(c); 
}

rnum::RationalNumber rnum::RationalNumber::operator+(rnum::RationalNumber const& b) {
	return add(b);
}

rnum::RationalNumber rnum::RationalNumber::operator-(rnum::RationalNumber const& b) {
	return subtract(b);
}

rnum::RationalNumber rnum::RationalNumber::operator*(rnum::RationalNumber const& b) {
	return multiply(b);
}

rnum::RationalNumber rnum::RationalNumber::operator/(rnum::RationalNumber const& b) {
	return divide(b);
}

char rnum::RationalNumber::operator<(rnum::RationalNumber const& b) {
	return lessThan(b);
}

char rnum::RationalNumber::operator<=(rnum::RationalNumber const& b) {
	return equal(b) || lessThan(b) ;
}

char rnum::RationalNumber::operator>(rnum::RationalNumber const& b) {
	return !(*this <= b);
}

char rnum::RationalNumber::operator>=(rnum::RationalNumber const& b) {
	return (*this == b) || (*this > b); 
}


char rnum::RationalNumber::operator<(int const& b) {
	return (*this) < rnum::RationalNumber(b, 1); 
}
char rnum::RationalNumber::operator<=(int const& b) {
	return (*this) < b || (*this) == rnum::RationalNumber(b,1); 
}
char rnum::RationalNumber::operator>(int const& b) {
	return !( (*this) <= b );
}
char rnum::RationalNumber::operator>=(int const& b) {
	return !( (*this) < b );
}

char rnum::RationalNumber::operator<(double const& b) {
	return ((double)(*this)) < b; 
}
char rnum::RationalNumber::operator<=(double const& b) {
	return ((double)(*this)) <= b; 
}
char rnum::RationalNumber::operator>(double const& b) {
	return ((double)(*this)) > b; 
}
char rnum::RationalNumber::operator>=(double const& b) {
	return ((double)(*this)) >= b; 
}

char rnum::RationalNumber::operator==(rnum::RationalNumber const& b) {
	return equal(b);
}

char rnum::RationalNumber::operator==(double const& b) {
	return ((double)(*this)) == b; 
}

rnum::RationalNumber rnum::RationalNumber::operator+(int const& b) {
	return *this + rnum::RationalNumber(b, 1); 
}

rnum::RationalNumber rnum::RationalNumber::operator-(int const& b) {
	return *this - rnum::RationalNumber(b, 1); 
}

rnum::RationalNumber rnum::RationalNumber::operator*(int const& b) {
	return *this * rnum::RationalNumber(b, 1); 
}

rnum::RationalNumber rnum::RationalNumber::operator/(int const& b) {
	return *this / rnum::RationalNumber(b, 1); 
}

rnum::RationalNumber::operator double() const {
	return ((double)nominator) / ((double)denominator); 
}

rnum::RationalNumber rnum::RationalNumber::operator=(int const& b) {
	return rnum::RationalNumber(b, 1); 
}

rnum::RationalNumber rnum::RationalNumber::operator -() const {
	rnum::RationalNumber e(-nominator, denominator); 
	return e; 
}
