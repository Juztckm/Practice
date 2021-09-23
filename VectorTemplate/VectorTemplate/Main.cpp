#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Vector.h"


struct Vector3
{
	Vector3() :x(0), y(0), z(0) {}
	Vector3(float scaler) :x(scaler), y(scaler), z(scaler) {}
	Vector3(float a, float b, float c) :x(a), y(b), z(c) {}
	Vector3(const Vector3& other)
		:x(other.x),y(other.y),z(other.z)
	{
		std::cout << "Copy\n";
	}

	Vector3(const Vector3&& other) noexcept 
		:x(other.x), y(other.y), z(other.z) 
	{ 
		std::cout << "Move\n"; 
	}

	~Vector3()
	{
		std::cout << "Destroyed\n";
	}

	Vector3& operator=(const Vector3& other) noexcept
	{
		std::cout << "Copy\n";
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	Vector3& operator=(const Vector3&& other) noexcept
	{
		std::cout << "Move\n";
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	void PrintVector() const noexcept
	{
		std::cout << x << ' ' << y << ' ' << z << '\n';
	}
//private:
	float x = 0.0f, y = 0.0f, z = 0.0f;
};

template<typename T>
void PrintVector(const Vector<T>& v)
{
	for (size_t i = 0; i < v.Size(); i++)
	{
		std::cout << v[i] << '\n';
	}
	std::cout << "_______________________________________\n";
}

void PrintVector(const Vector<Vector3>& v) 
{
	for (size_t i = 0; i < v.Size(); i++)
	{
		std::cout << v[i].x << ' ' << v[i].y << ' ' << v[i].z << '\n';
	}
}

void PrintVector(const Vector<Vector3>&& v)
{
	for (size_t i = 0; i < v.Size(); i++)
	{
		std::cout << v[i].x << ' ' << v[i].y << ' ' << v[i].z << '\n';
	}
}

uint32_t main()
{
	Vector<int> v_int{1,2,3,4,5,6,7,8,9,0};
	PrintVector(v_int);
	Vector<Vector3> v3;
	v3.PushBack(Vector3());
	v3.PushBack(Vector3(1.2));
	v3.PushBack(Vector3(1,2,3));
	PrintVector(v3);
	v3.PopBack();
	PrintVector(v3);
	v3.EmplaceBack();
	v3.EmplaceBack(1.4f);
	PrintVector(v3);
	v3.PopBack();
	v3.Clear();
	PrintVector(v3);
	v3.EmplaceBack(7,4,6);
	PrintVector(v3);
	std::cout << "-----------------------------------------------------\n";
#if 0
	Vector<int> v_int;
	for (size_t i = 0; i < 5; i++)
	{
		v_int.PushBack(i);
	}

	PrintVector(v_int);
	
	Vector<std::string> v_string;
	v_string.PushBack("CKM");
	v_string.PushBack("Chandan");
	v_string.PushBack("C++");
	v_string.PushBack("Zip");

	PrintVector(v_string);

	Vector<std::string> v_string1(v_string);
	PrintVector(v_string1);
	v_string1.PopBack();
	PrintVector(v_string1);
	v_string1.PushBack("C++aaa");
	v_string1.PushBack("Zihjp");
	PrintVector(v_string1);

	Vector<int> v_int1 = Vector<int>(v_int);
	v_int1 = v_int;

	PrintVector(v_int1);
#endif
	return 0;
}