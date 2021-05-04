// author: Grzegorz Prowadzacy

#include "vector.h"

Vector::Vector(int s) : data(0)
{
	this->data = new Fraction[s];
	capacity = s;
	size = 0;
}


Vector::~Vector()
{
	delete [] data;
	capacity = 0;
	size = 0;
}

Vector::Vector(const Vector&& v1)
{
	this->data = new Fraction[v1.capacity];
	this->capacity = v1.capacity;
	this->size = v1.size;
}

void Vector::push_back(Fraction u)
{
	
	if (this->Capacity() < (this->Size() + 1))
	{
		this->data = (Fraction*)realloc(this->data, this->Capacity() + 1);
		this->capacity++;
	}
	this->size++;
	this->data[this->size - 1] = u;
}


Fraction Vector::operator[](size_t index)
{
	if (index >= this->size) 
	{
		throw std::out_of_range("index out of range");
	}
	return this->data[index];
}