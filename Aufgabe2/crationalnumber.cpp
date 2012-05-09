#include "crationalnumber.h"

RationalNumber::RationalNumber(int nom, int denom) 
	: nominator(nom), denominator(denom)
{}

char RationalNumber::isValid() {
    return denominator != 0;
}

char RationalNumber::isNaN() {
    return !this->isValid();
}

char RationalNumber::equal(RationalNumber const& b) {
    return this->nominator * b.denominator == this->denominator * b.nominator;
}

char RationalNumber::lessThan(RationalNumber const& b) {
    if( (b.denominator > 0 && this->denominator > 0) || (b.denominator < 0 && this->denominator < 0) )
        return this->nominator * b.denominator < this->denominator * b.nominator;
    else
        return this->nominator * b.denominator > this->denominator * b.nominator;
}

RationalNumber RationalNumber::multiply(RationalNumber const& b) {
    RationalNumber e(
        nominator * b.nominator,
        denominator * b.denominator
    );

    return e;
}

RationalNumber RationalNumber::divide(RationalNumber const& b){
    RationalNumber e(
        nominator * b.denominator,
        denominator * b.nominator
    );

    return e;
}

static 
int gcd(int a, int b) {
    if(b == 0)
        return a;

    if (a == b)
        return a;

    if(b < a)
        return gcd(a - b, b);
    else
        return gcd(a, b - a);
}

RationalNumber RationalNumber::add(RationalNumber const& b) {
    int g = gcd(denominator, b.denominator);
    int newNomA = nominator * (g / denominator);
    int newNomB = b.nominator * (g / b.denominator);

    RationalNumber ret(
        newNomA + newNomB,
        g
    );

    return ret;
}

RationalNumber RationalNumber::subtract(RationalNumber const& b) {
    RationalNumber c(-b.nominator, b.denominator);
	return this->add(c); 
}

RationalNumber RationalNumber::operator+(RationalNumber const& b) {
	return add(b);
}

RationalNumber RationalNumber::operator-(RationalNumber const& b) {
	return subtract(b);
}

RationalNumber RationalNumber::operator*(RationalNumber const& b) {
	return multiply(b);
}

RationalNumber RationalNumber::operator/(RationalNumber const& b) {
	return divide(b);
}

char RationalNumber::operator==(RationalNumber const& b) {
	return equal(b);
}


