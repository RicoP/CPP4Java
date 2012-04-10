#ifndef RATIONALNUMBERARRAY_H 
#define RATIONALNUMBERARRAY_H 

#include "rationalnumber.h" 

struct _RationalNumberArray; 
typedef struct _RationalNumberArray RationalNumberArray; 

RationalNumberArray* rnaCreate(); 
RationalNumberArray* rnaCreate(int capacity); 
void rnaDelete(RationalNumberArray* rna);  
void rnaResize(RationalNumberArray* rna, int size);  
int rnaSize(RationalNumberArray* rna); 
int rnaCapacity(RationalNumberArray* rna); 

#endif 
