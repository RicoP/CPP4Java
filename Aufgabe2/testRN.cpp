/*
   Simple Unit Test for type RationalNumber
*/

#include <cstdio>
#include <cstdbool>
#include <cassert>

#include "crationalnumber.h"

int main()
{


    printf("Performing unit tests for RationalNumber...");
    //fflush(stdout);

    /* Part 1 - RationalNumber data type */
    RationalNumber n1(3, 4),
                   n2(6, 4),
                   n3(3, 2),
                   n4(-9, -6),
                   n5(9, -6),
                   n6(9, 4),
                   n0(0, 4),
                   nn(4, 0);

    assert( n0.isValid() );
    assert( ! nn.isValid() );
    assert( nn.isNaN() );

    assert( n2 == n3 );
    assert( n2 == n4 );
    assert( n2.equal( n1.add(n1) ) );
    assert( n2.equal(n4) );
    assert( !n4.equal(n5) );
    assert( n5.lessThan(n3) );

    RationalNumber t1 = n1 + n2;
    RationalNumber t2 = n3 / n3;
    RationalNumber t3 = n2 / n2;
    RationalNumber t4 = n6 / n0;

    assert( t1.equal(n6) );
    assert( t2.equal(t3) );
    assert( n0.equal( n1 - n1 ) );
    assert( n6.equal(n3 * n3 ) );
    assert( t4.isNaN() );

    printf(" successful!\n");

    return 0;
}
