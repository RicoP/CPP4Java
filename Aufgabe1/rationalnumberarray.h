#ifndef RATIONALNUMBERARRAY_H 
#define RATIONALNUMBERARRAY_H 

#include "rationalnumber.h" 

struct RationalNumberArray; 

typedef void (*Callback)(char*);

RationalNumberArray* rnaCreate(); 
RationalNumberArray* rnaCreate(int capacity); 
RationalNumberArray* rnaCreate(int capacity, Callback callback); 
void rnaDelete(RationalNumberArray* rna);  
void rnaResize(RationalNumberArray* rna, int size);  
int rnaSize(RationalNumberArray const* const rna); 
int rnaCapacity(RationalNumberArray const* const rna); 
void rnaAdd(RationalNumberArray* rna, RationalNumber rn);
void rnaSet(RationalNumberArray* rna, int n, RationalNumber rn); 
RationalNumber rnaGet(RationalNumberArray const* const rna, int n); 
void rnaRemove(RationalNumberArray* rna, int from, int to); 
#endif 
