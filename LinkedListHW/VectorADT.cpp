#include "VectorADT.h"

VectorADT::~VectorADT()
{
	delete[] array;
	array = nullptr;
}

VectorADT::VectorADT()
{
	size = 0;
	capacity = 0;
	this->resize(5);
	size = 0;
}

VectorADT::VectorADT(const int size, const int capacity)
{
	array = new double[capacity];
	if (array)
	{
		this->size = size;
		this->capacity = capacity;

		for (int i = 0; i < capacity; i++) {
			array[i] = 0.0;
		}
	}
}
VectorADT& VectorADT::operator= (const VectorADT & clone)
{
	array = new double[clone.capacity];
	if (array)
	{
		this->size = clone.size;
		this->capacity = clone.capacity;

		for (int i = 0; i < capacity; i++) {
			array[i] = clone.array[i];
		}
	}
	return *this;
}

VectorADT::VectorADT(const VectorADT & clone)
{
	array = new double[clone.capacity];
	if (array)
	{
		this->size = clone.size;
		this->capacity = clone.capacity;

		for (int i = 0; i < capacity; i++) {
			array[i] = clone.array[i];
		}
	}
}

void VectorADT::push_back(double val)
{
	if (size >= capacity)
	{
		resize(size + 1);
		array[size - 1] = val;
	}
	else
	{
		array[size++] = val;
	}
}

void VectorADT::resize(int newSize)
{
	if (newSize > capacity)
	{
		capacity = 2 * newSize;
		double *newarray = new double[capacity];
		if (newarray)
		{
			if (size)
			{
				for (int i = 0; i < size; i++)
				{
					newarray[i] = array[i];
				}
				delete[] array;
			}
			for (int i = size; i < capacity; i++)
			{
				newarray[i] = 0.0;
			}
			array = newarray;
		}
	}
	size = newSize;
}

void VectorADT::pop_back()
{
	if (size > 0) {
		size--;
	}

}

double VectorADT::operator[](const int index) const
{
	double retVal = -1;
	if (index < size && index >= 0)
	{
		retVal = array[index];
	}
	return retVal;
}

VectorADT operator+(const VectorADT &rhs, const VectorADT &lhs) 
{
	VectorADT sum;
	if (rhs.length() == lhs.length())
	{
		for (int i = 0; i < rhs.length(); i++)
		{
			double val1 = rhs[i];
			double val2 = lhs[i];
			sum.push_back(val1 + val2);
		}
	}
	return sum;

}

std::ostream& operator<< (std::ostream& stream, const VectorADT& rhs)
{
	if (rhs.length() == 0)
	{
		stream << "no values found " << endl;
	}
	else
	{
		for (int i = 0; i < rhs.length(); i++)
		{
			double val = rhs[i];
			if (i == rhs.length() - 1)
			{
				stream << val << '.' << endl;
			}
			else
			{
				stream << val << ', ';
			}
		}
	}
	return stream;
}

int VectorADT::length() const
{
	return size;
}

int VectorADT::curr_capacity() const
{
	return capacity;
}