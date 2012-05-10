#include "crationalnumberarray.h"
#include "crationalnumber.h" 
#include <cstdlib>
#include <cstdio> 

#define MIN(a,b) ((a) > (b) ? (b) : (a)) 

#define xassert(rna, expr) \
	if(!(expr) && rna->_callback) { \
		rna->_callback(#expr); \
	}

RationalNumberArray::RationalNumberArray() 
	: _size(0), _capacity(0), _callback(NULL) {
	this->numbers = (RationalNumber*) malloc(_capacity * sizeof(RationalNumber)); 
}

RationalNumberArray::RationalNumberArray(int capacity) 
	: _size(0), _capacity(capacity), _callback(NULL) {
	this->numbers = (RationalNumber*) malloc(capacity * sizeof(RationalNumber)); 
}

RationalNumberArray::RationalNumberArray(int capacity, Callback callback) 
	: _size(0), _capacity(capacity), _callback(callback) {
	this->numbers = (RationalNumber*) malloc(capacity * sizeof(RationalNumber)); 
}

RationalNumberArray::~RationalNumberArray() {
	free(this->numbers); 
}

void RationalNumberArray::resize(int size) {
	xassert(this, size > 0); 

	this->numbers = (RationalNumber*) realloc(numbers, size * sizeof(RationalNumber)); 	
	this->_capacity = size; 
	this->_size = MIN(_size, _capacity); 
}

int RationalNumberArray::size() {
	return this->_size; 
}

int RationalNumberArray::capacity() {
	return this->_capacity; 
}
 
void RationalNumberArray::set(int n, RationalNumber& rn) {
	int from, to; 

	if(n < _size) {
		numbers[n] = rn; 
		return; 
	}

	if(n >= _capacity) {	
		this->resize(n+1); 
	}
		
	RationalNumber zero(0, 1); 

	for(from = _size, to = n - 1; from < to; from++) {
		numbers[from] = zero; 
	}
	numbers[n] = rn;
	_size = n+1; 
}

void RationalNumberArray::add(RationalNumber& rn) {
	set(size(), rn); 
}

RationalNumber RationalNumberArray::get(int n) {
	xassert(this, n >= 0 && n < _size); 

	return this->numbers[n]; 
} 

void RationalNumberArray::remove(int from, int to) {
	xassert(this, from <= to); 
	xassert(this, from >= 0); 
	xassert(this, to < _size); 

	int i, j; 	
	for(i = from, j = to; j < size(); i++,j++) {
		this->numbers[i] = this->numbers[j]; 
	}

	resize(this->_size - (to - from)); 
}

RationalNumber RationalNumberArray::operator[](int n) const {
	xassert(this, n >= 0 && n < _size); 

	return this->numbers[n]; 
}

RationalNumber& RationalNumberArray::operator[](int n) {
	xassert(this, n >= 0 && n < _size); 

	return this->numbers[n]; 
}
