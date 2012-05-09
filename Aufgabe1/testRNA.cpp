/*
   Simple Unit Test for type RationalNumber
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "rationalnumber.h"
#include "rationalnumberarray.h"

void fail(char* message) {
	printf("ERROR: %s\n", message); 
	exit(1);
}

int main()
{
    printf("Performing unit tests for RationalNumberArray...");

    RationalNumber  n1 = { 3, 4 },
                    n2 = { 6, 4 },
                    n3 = { 3, 2 },
                    n4 = { -9, -6 },
                    n5 = { 9, -6 },
                    n6 = { 9, 4 },
                    n0 = { 0, 4 },
                    nn = { 4, 0 };

	RationalNumberArray* rna = rnaCreate(10, fail); 
	assert(rnaSize(rna) == 0); 

	rnaResize(rna, 10); 
	RationalNumberArray* rna2 = rnaCreate(10, fail); 

	assert(rnaCapacity(rna) == rnaCapacity(rna2)); 
	assert(rnaSize(rna) == rnaSize(rna2)); 

	RationalNumber rn1 = {1,1}; 
	RationalNumber rn2 = {2,1}; 
	RationalNumber rn3 = {3,1}; 
	RationalNumber rn4 = {4,1}; 
	RationalNumber rn5 = {5,1}; 

	rnaAdd(rna, rn1);
	rnaAdd(rna, rn2);
	rnaAdd(rna, rn3);
	rnaAdd(rna, rn4);
	rnaAdd(rna, rn5);
	
	assert(rnaSize(rna) == 5); 

	assert(rnEqual(rnaGet(rna, 0), rn1)); 

	rnaRemove(rna, 1, 4); 

	assert(rnEqual(rnaGet(rna, 0), rn1)); 
	assert(rnEqual(rnaGet(rna, 1), rn5)); 

	assert(rnaSize(rna) == 2); 

	rnaAdd(rna, rn2);
	rnaAdd(rna, rn3);
	rnaAdd(rna, rn4);

	assert(rnaSize(rna) == 5); 

	assert(rnEqual( rnaGet(rna, 2), rn2)); 
	assert(rnEqual( rnaGet(rna, 3), rn3)); 
	assert(rnEqual( rnaGet(rna, 4), rn4)); 

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
