/*
   Simple Unit Test for type RationalNumber
*/

#include <cstdio>
#include <cstdbool>
#include <cassert>

#include "crationalnumber.h"

using namespace rnum;

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

	RationalNumber a(1,2); 
	RationalNumber x(6,4); 

	assert(a + x == RationalNumber(2, 1)); 
	assert(x - a == RationalNumber(4, 4)); 

	//Aus der PDF 
	RationalNumber b(0,1), c(2,3), d(9,3), e(-4,2), f(17,3);
	a = b + c*d - e/f;
	x = -f + RationalNumber(3,4);

	assert( a == RationalNumber( 720,306 ) );
	assert( x == RationalNumber( -59,12 ) );

	assert(2 * RationalNumber(3,2) == RationalNumber(6,2)); 
	assert(RationalNumber(11,3) - 3 == RationalNumber(2,3)); 
	assert(RationalNumber(20,3) / 2 == RationalNumber(10,3)); 

	//---
	{
		int i=5, j=4;
		RationalNumber a(1,2), b(7,3);
		RationalNumber aa = i*a, bb = b/j;
		RationalNumber ia (i);
		RationalNumber ja = j;
	
		assert(ja == j);
		assert(ia <= i);		
		assert(ja < i);
		assert(ia > j);
	}

	{
		double i=5.0, j=4.0;
		RationalNumber a(1,2), b(7,3);
		RationalNumber aa = i*a, bb = b/j;
		RationalNumber ia (i);
		RationalNumber ja = j;
	
		assert(ja == j);
		assert(ia <= i);		
		assert(ja < i);
		assert(ia > j);
	}

    printf(" successful!\n");

    return 0;
}
