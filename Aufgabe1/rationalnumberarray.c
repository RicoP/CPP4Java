#include "rationalnumberarray.h"
#include "rationalnumber.h" 
#include <stdlib.h>
#include <stdio.h> 

struct _RationalNumberArray {
    RationalNumber* data;
    int size;
    int capacity;
};

static 
void ERROR(char* str) {
	fprintf(stderr, "ERROR %s\n", str); 
}

RationalNumberArray* rnaCreate() {
	RationalNumberArray* rna = malloc(sizeof(RationalNumberArray)); 
	rna->data = NULL; 
	rna->size = 0; 
	rna->capacity = 0; 

	return rna; 
}

RationalNumberArray* rnaCreate(int capacity) {
	RationalNumberArray* rna = malloc(sizeof(RationalNumberArray)); 
	rna->data = malloc(capacity * sizeof(RationalNumber)); 
	rna->size = 0; 
	rna->capacity = capacity; 

	return rna; 
}

void rnaDelete(RationalNumberArray* rna) {
	free(rna->data); 
	free(rna); 
}

void rnaResize(RationalNumberArray* rna, int size) {
	if(!rna) {
		ERROR("Try to resize NULL."); 
	}
	rna->data = realloc(rna->data, size * sizeof(RationalNumber)); 	
	rna->capacity = size; 
}
