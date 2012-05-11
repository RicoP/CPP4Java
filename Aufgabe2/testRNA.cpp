/*
   Simple Unit Test for type RationalNumberArray
*/

#define private public 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "crationalnumber.h"
#include "crationalnumberarray.h"

using namespace rnum; 

void fail(char* message) {
	printf("ERROR: %s\n", message); 
	exit(1);
}

int main()
{
    printf("Performing unit tests for RationalNumberArray...");

    RationalNumber n1(3, 4),
                   n2(6, 4),
                   n3(3, 2),
                   n4(-9, -6),
                   n5(9, -6),
                   n6(9, 4),
                   n0(0, 4),
                   nn(4, 0);

	float n3f = (float)n3; 
	assert( (n3f - 1.5) < 0.001 && (n3f - 1.5) > -0.001 );

	assert(n0 == 0.0); 

	assert(n1 < n2);
	assert(n2 > n1);	
	assert(n0 <= n2);
	assert(n2 >= n0);

	RationalNumberArray rna(10, fail); 
	assert(rna.size() == 0); 

	rna.resize(10); 
	RationalNumberArray rna2(10, fail); 

	assert(rna.capacity() == rna2.capacity()); 
	assert(rna.size() == rna2.size()); 

	RationalNumber rn1(1,1); 
	RationalNumber rn2(2,1); 
	RationalNumber rn3(3,1); 
	RationalNumber rn4(4,1); 
	RationalNumber rn5(5,1); 

	rna.add(rn1);
	rna.add(rn2);
	rna.add(rn3);
	rna.add(rn4);
	rna.add(rn5);
	
	assert(rna.size() == 5); 

	assert(rn1.equal( rna[0] )); 

	rna.remove(1, 4); 

	assert(rn1.equal(rna[0])); 
	assert(rn5.equal(rna[1])); 

	assert(rna.size() == 2); 

	rna.add(rn2);
	rna.add(rn3);
	rna.add(rn4);

	assert(rna.size() == 5); 

	assert(rn2 == rna[2]); 

	rna[2] = rna[4]; 
	assert(rna[2] == rna[4]); 

	//This will invoke the failmethod. 
	//x = rna[-1]; 
	//rna[-1] = x; 
	//x = rna[99999]; 
	//rna.remove(-1, 1); 
	//rna.remove(1, 0); 
	//rna.remove(0, 999999); 
	//rna.resize(-1); 

    printf(" successful!\n");

    return 0;
}

