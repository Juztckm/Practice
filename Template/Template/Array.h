#pragma once

template <typename T>
class Array
{
public:
	Array(T *arr, int sz);
	~Array();
	void print() const;
private:
	int sz;
	T* arr;
};

template<typename T>
Array<T>::Array(T* arr, int sz) :sz(sz), arr(new T[sz])
{
	for (int i = 0; i < sz; i++)
	{
		this->arr[i] = arr[i];
	}
}

template<typename T>
Array<T>::~Array()
{
	delete[] arr;
}

template<typename T>
void Array<T>::print() const
{
	for (int i = 0; i < sz; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}