#include "rationalnumberarray.h"
#include "rationalnumber.h" 
#include <stdlib.h>
#include <stdio.h> 

#define MIN(a,b) ((a) > (b) ? (b) : (a)) 

#define _assert(rna, expr) \
	if(!(expr) && rna->callback) { \
		rna->callback(#expr); \
		exit(1); \
	}

struct RationalNumberArray {
    RationalNumber* data;
    int size;
    int capacity;
	Callback callback;  
};



RationalNumberArray* rnaCreate() {
	return rnaCreate(10, NULL); 	
}

RationalNumberArray* rnaCreate(int capacity) {
	return rnaCreate(capacity, NULL); 
}

RationalNumberArray* rnaCreate(int capacity, Callback callback) {
	RationalNumberArray* rna = (RationalNumberArray*) malloc(sizeof(RationalNumberArray)); 
	rna->data = (RationalNumber*) malloc(capacity * sizeof(RationalNumber)); 
	rna->size = 0; 
	rna->capacity = capacity; 
	rna->callback = callback; 

	return rna; 
}

void rnaDelete(RationalNumberArray* rna) {
	free(rna->data); 
	free(rna); 
}

void rnaResize(RationalNumberArray* rna, int size) {
	_assert(rna, rna != NULL); 
	_assert(rna, size > 0); 

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

	if(n >= rna->capacity) {	
		rnaResize(rna, n+1); 
	}
		
	RationalNumber zero = {0, 1}; 

	for(from = rna->size, to = n - 1; from < to; from++) {
		rna->data[from] = zero; 
	}
	rna->data[n] = rn;
	rna->size = n+1; 
}

void rnaAdd(RationalNumberArray* rna, RationalNumber rn) {
	rnaSet(rna, rna->size, rn); 
}

RationalNumber rnaGet(RationalNumberArray const* const rna, int n) {
	_assert(rna, n >= 0 && n < rna->size); 

	return rna->data[n]; 
} 

void rnaRemove(RationalNumberArray* rna, int from, int to) {
	_assert(rna, from <= to); 
	_assert(rna, from >= 0); 
	_assert(rna, to < rna->size); 

	int i, j; 	
	for(i = from, j = to; j < rna->size; i++,j++) {
		rna->data[i] = rna->data[j]; 
	}

	rnaResize(rna, rna->size - (to - from)); 
}

