#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <stdio.h>

typedef struct {
    int nominator;
    int denominator;
} RationalNumber;

char rnIsValid(RationalNumber n);
char rnIsNaN(RationalNumber n);
char rnEqual(RationalNumber a, RationalNumber b);
char rnLessThan(RationalNumber a, RationalNumber b);
RationalNumber rnMultiply(RationalNumber a, RationalNumber b);
RationalNumber rnDivide(RationalNumber a, RationalNumber b);
RationalNumber rnAdd(RationalNumber a, RationalNumber b);
RationalNumber rnSubtract(RationalNumber a, RationalNumber b);

#endif // RATIONALNUMBER_H
