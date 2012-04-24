/*
   Simple Unit Test for type RationalNumber
*/

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "rationalnumber.h"
#include "rationalnumberarray.h"

int main()
{
    printf("Performing unit tests for RationalNumberArray...");
    //fflush(stdout);

    /* Part 1 - RationalNumber data type */
    RationalNumber  n1 = { 3, 4 },
                    n2 = { 6, 4 },
                    n3 = { 3, 2 },
                    n4 = { -9, -6 },
                    n5 = { 9, -6 },
                    n6 = { 9, 4 },
                    n0 = { 0, 4 },
                    nn = { 4, 0 };

/*
RationalNumberArray* rnaCreate(); 
RationalNumberArray* rnaCreate(int capacity); 
void rnaDelete(RationalNumberArray* rna);  
void rnaResize(RationalNumberArray* rna, int size);  
int rnaSize(RationalNumberArray* rna); 
int rnaCapacity(RationalNumberArray* rna); 
void rnaAdd(RationalNumberArray* rna, RationalNumber rn);
void rnaSet(RationalNumberArray* rna, int n, RationalNumber rn); 
RationalNumber rnaGet(RationalNumberArray* rna, int n); 
void rnaRemove(RationalNumberArray* rna, int from, int to); 
*/

	RationalNumberArray* rna = rnaCreate(); 
	assert(rnaSize(rna) == 0); 

	rnaResize(rna, 10); 
	RationalNumberArray* rna2 = rnaCreate(10); 

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

    printf(" successful!\n");

    return 0;
}
