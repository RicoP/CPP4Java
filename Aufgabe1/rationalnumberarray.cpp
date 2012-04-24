#include "rationalnumberarray.h"
#include "rationalnumber.h" 
#include <stdlib.h>
#include <stdio.h> 
#include <assert.h>

#define MIN(a,b) ((a) > (b) ? (b) : (a)) 

struct RationalNumberArray {
    RationalNumber* data;
    int size;
    int capacity;
};

RationalNumberArray* rnaCreate() {
	return rnaCreate(10); 	
}

RationalNumberArray* rnaCreate(int capacity) {
	assert(capacity > 0); 

	RationalNumberArray* rna = (RationalNumberArray*) malloc(sizeof(RationalNumberArray)); 
	rna->data = (RationalNumber*) malloc(capacity * sizeof(RationalNumber)); 
	rna->size = 0; 
	rna->capacity = capacity; 

	return rna; 
}

void rnaDelete(RationalNumberArray* rna) {
	free(rna->data); 
	free(rna); 
}

void rnaResize(RationalNumberArray* rna, int size) {
	assert(rna); 
	assert(size > 0); 

	rna->data = (RationalNumber*) realloc(rna->data, size * sizeof(RationalNumber)); 	
	rna->capacity = size; 
	rna->size = MIN(rna->size, rna->capacity); 
}

int rnaSize(RationalNumberArray const* const rna) {
	return rna->size; 
}
 
int rnaCapacity(RationalNumberArray const* const rna) {
	return rna->capacity; 
}
 
void rnaSet(RationalNumberArray* rna, int n, RationalNumber rn) {
	int from, to; 

	if(n < rna->size) {
		rna->data[n] = rn; 
		return; 
	}
	
	if(n < rna->capacity) {
		RationalNumber zero = {0, 1}; 
		for(from = rna->size, to = n - 1; from < to; from++) {
			rna->data[from] = zero; 
		}
		rna->data[n] = rn;
		rna->size = n+1; 
		return; 
	}

	rnaResize(rna, n+1); 
	rnaSet(rna, n, rn); 
}

void rnaAdd(RationalNumberArray* rna, RationalNumber rn) {
	rnaSet(rna, rna->size, rn); 
}

RationalNumber rnaGet(RationalNumberArray const* const rna, int n) {
	assert(n >= 0 && n < rna->size); 

	return rna->data[n]; 
} 

void rnaRemove(RationalNumberArray* rna, int from, int to) {
	assert(from <= to); 
	assert(from >= 0); 
	assert(to < rna->size); 

	int i, j; 	
	for(i = from, j = to; j < rna->size; i++,j++) {
		rna->data[i] = rna->data[j]; 
	}

	rnaResize(rna, rna->size - (to - from)); 
}

