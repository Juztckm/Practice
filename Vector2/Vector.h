#pragma once
#include <bits/stdc++.h>
class Vector
{
private:
	int sizeOfVector;
	int capacityOfVector;
	int* array;
	void increaseCapacity();
	bool checkSizeAndCapacity();
public:
	//Constructors
	Vector();
	//Copy Constructor
	Vector(const Vector& v);
	Vector(const int noOfTimes, const int value = 0);
	Vector(const std::initializer_list<int>& list);

	//Destroctor
	~Vector();

	//Operator Overloading
	bool operator==(const Vector& rhs) const;
	bool operator!=(const Vector& rhs) const;
	Vector& operator=(const Vector& rhs);
	int& operator[](const int index) const;

	friend std::ostream& operator<<(std::ostream& ostr, const Vector& v);

	//Utility Function
	int size() const;
	int capacity() const;
	bool empty() const;
	void clear();
	void push_back(int value);


	/*
	begin(); //Returns an iterator pointing to the first element in the vector
	end(); //Returns an iterator pointing to the theoretical element that follows the last element in the vector
	rbegin(); //Returns a reverse iterator pointing to the last element in the vector(reverse beginning).It moves from last to first element
	rend(); //Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector(considered as reverse end)
	cbegin(); //Returns a constant iterator pointing to the first element in the vector.
	cend(); //Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
	crbegin(); //Returns a constant reverse iterator pointing to the last element in the vector(reverse beginning).It moves from last to first element
	crend(); //Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector(considered as reverse end)
	size(); //Returns the number of elements in the vector.
	capacity(); //Returns the size of the storage space currently allocated to the vector expressed as number of elements.
	resize(n); //Resizes the container so that it contains ‘n’ elements.
	empty(); //Returns whether the container is empty.
	reserve(); //Requests that the vector capacity be at least enough to contain n elements.
	at(g); //Returns a reference to the element at position ‘g’ in the vector
	front(); //Returns a reference to the first element in the vector
	back(); //Returns a reference to the last element in the vector
	data(); //Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
	assign(); //It assigns new value to the vector elements by replacing old ones
	push_back(); //It push the elements into a vector from the back
	pop_back(); //It is used to pop or remove elements from a vector from the back.
	insert(); //It inserts new elements before the element at the specified position
	erase(); //It is used to remove elements from a container from the specified position or range.
	swap(); //It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
	clear(); //It is used to remove all the elements of the vector container
	emplace(); //It extends the container by inserting new element at position
	emplace_back(); //It is used to insert a new element into the vector container, the new element is added to the end of the vector
	*/
};

