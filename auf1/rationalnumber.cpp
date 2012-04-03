#include "rationalnumber.h"

bool rnIsValid(RationalNumber n) {
    return n.denominator != 0;
}

bool rnIsNaN(RationalNumber n) {
    return !rnIsValid(n);
}

bool rnEqual(RationalNumber a, RationalNumber b) {
    return a.nominator * b.denominator == a.denominator * b.nominator;
}

bool rnLessThan(RationalNumber a, RationalNumber b) {    
    if(b.denominator > 0 && a.denominator > 0 || b.denominator < 0 && a.denominator < 0)
        return a.nominator * b.denominator < a.denominator * b.nominator;
    else
        return a.nominator * b.denominator > a.denominator * b.nominator;
}

RationalNumber rnMultiply(RationalNumber a, RationalNumber b) {
    RationalNumber e = {
        a.nominator * b.nominator,
        a.denominator * b.denominator
    };

    return e;
}

RationalNumber rnDivide(RationalNumber a, RationalNumber b) {
    RationalNumber e = {
        a.nominator * b.denominator,
        a.denominator * b.nominator
    };

    return e;
}

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

RationalNumber rnAdd(RationalNumber a, RationalNumber b) {
    int g = gcd(a.denominator, b.denominator);
    int newNomA = a.nominator * (g / a.denominator);
    int newNomB = b.nominator * (g / b.denominator);

    RationalNumber ret = {
        newNomA + newNomB,
        g
    };

    return ret;
}

RationalNumber rnSubtract(RationalNumber a, RationalNumber b) {
    RationalNumber c = { -b.nominator, b.denominator };
    return rnAdd(a, c);
}
