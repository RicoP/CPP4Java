#ifndef RATIONALNUMBERARRAY_H 
#define RATIONALNUMBERARRAY_H 

#include "crationalnumber.h" 

class RationalNumberArray { 
	public:
	typedef void (*Callback)(char*);

	private: 
	RationalNumber* numbers; 
	int _size; 
	int _capacity; 
	Callback _callback; 

	public: 
	//Getter Setter 
	int size(); 
	int capacity(); 


	RationalNumberArray();
	RationalNumberArray(int capacity);               
	RationalNumberArray(int capacity, Callback callback);
	~RationalNumberArray();

	void resize(int size);  
	void add(RationalNumber& rn);
	void set(int n, RationalNumber& rn); 
	RationalNumber get(int n);
	void remove(int from, int to);
};
#endif 