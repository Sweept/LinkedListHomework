#pragma once
#include <iostream>
#include <vector>
using namespace std;

class VectorADT
{
private:
	double * array;
	int size;
	int capacity;

public:
	~VectorADT();
	VectorADT();
	VectorADT( const int size, const int capacity);
	VectorADT(const VectorADT & clone);
	VectorADT& operator= (const VectorADT & clone);

	void push_back(double val);

	void resize(int newSize);

	void pop_back();

	double operator[]( const int index) const;
	
	friend VectorADT operator+ ( const VectorADT &rhs, const VectorADT &lhs);

	friend std::ostream& operator<< (std::ostream& stream, const VectorADT& rhs);

	int length() const;

	int curr_capacity() const;

};
