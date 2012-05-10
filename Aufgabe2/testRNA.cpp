/*
   Simple Unit Test for type RationalNumberArray
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "crationalnumber.h"
#include "crationalnumberarray.h"

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

	assert(rn2.equal( rna[2] )); 
	assert(rn3.equal( rna[3] )); 
	assert(rn4.equal( rna[4] )); 

	//This will fail.

	//rnaGet(rna, -1); 
	//rnaGet(rna, rnaSize(rna)); 
	//rnaRemove(rna, -1, 1); 
	//rnaRemove(rna, 0, -1);
	//rnaRemove(rna, 0, 9999999);  
	//rnaResize(rna, -10); 

    printf(" successful!\n");

    return 0;
}
