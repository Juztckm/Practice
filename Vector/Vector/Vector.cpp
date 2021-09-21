#include "Vector.h"

void Vector::increaseCapacity()
{
	capacityOfVector *= 2;
	int* newarray = new int[capacityOfVector];
	for (int i = 0; i < sizeOfVector; i++)
	{
		newarray[i] = array[i];
	}
	delete[] array;
	array = newarray;
}

bool Vector::checkSizeAndCapacity()
{
	return (sizeOfVector == capacityOfVector - 1) ? true : false;
}

Vector::~Vector()
{
	delete[] array;
}

Vector::Vector()
	:sizeOfVector(0),
	capacityOfVector(5),
	array(new int[capacityOfVector])
{
}

Vector::Vector(const Vector& v)
		:sizeOfVector(0),
		 capacityOfVector(v.size()+5),
		 array(new int[capacityOfVector])
{
	for (int i = 0; i < v.size(); i++)
	{
		push_back(v.array[i]);
	}
}

Vector::Vector(const int noOfTimes, const int value)
		:sizeOfVector(0),
		 capacityOfVector(noOfTimes + 5),
		 array(new int[capacityOfVector])
{
	for (int i = 0; i < noOfTimes; i++)
	{
		push_back(value);
	}
}

Vector::Vector(const std::initializer_list<int>& list)
		:sizeOfVector(0),
		 capacityOfVector(list.size() + 5),
		 array(new int[capacityOfVector])
{
	for(auto x : list)
	{
		push_back(x);
	}
}

bool Vector::operator==(const Vector& rhs) const
{
	if (sizeOfVector != rhs.sizeOfVector) return false;
	for (int i = 0; i < sizeOfVector; i++)
	{
		if (array[i] != rhs.array[i]) return false;
	}
	return true;
}

bool Vector::operator!=(const Vector& rhs) const
{
	return !(*this == rhs);
}

Vector& Vector::operator=(const Vector& rhs)
{
	if (rhs.sizeOfVector > sizeOfVector)
	{
		delete[] array;
		array = new int[rhs.sizeOfVector + 5];
		capacityOfVector = rhs.sizeOfVector + 5;
	}
	for (int i = 0; i < rhs.sizeOfVector; i++)
	{
		push_back(rhs.array[i]);
	}
	sizeOfVector = rhs.sizeOfVector;

	return *this;
}

int& Vector::operator[](const int index) const
{
	return array[index];
}

int Vector::size() const
{
	return sizeOfVector;
}

int Vector::capacity() const
{
	return capacityOfVector;
}

bool Vector::empty() const
{
	return sizeOfVector == 0;
}

void Vector::clear()
{
	sizeOfVector = 0;
	delete[] array;
}

void Vector::push_back(int value)
{
	if (checkSizeAndCapacity())
	{
		increaseCapacity();
	}
	array[sizeOfVector] = value;
	sizeOfVector++;
}

void Vector::pop_back()
{
	if (!empty())
	{
		sizeOfVector--;
	}
}

int& Vector::front() const
{
	return array[0];
}

int& Vector::back() const
{
	return array[sizeOfVector-1];
}

std::ostream& operator<<(std::ostream& ostr, const Vector& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		ostr << v.array[i] << ' ';
	}
	return ostr;
}
