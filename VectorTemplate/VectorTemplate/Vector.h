#pragma once

template<typename T>
class Vector
{
public:
	Vector();
	Vector(const Vector& rhs);
	Vector(const Vector&& rhs);
	constexpr size_t Size()const;
	constexpr size_t Capacity()const;
	void PushBack(const T& value);
	constexpr T& operator [](size_t pos) const;
	T& operator [](size_t pos);
	Vector<T>& operator=(const Vector<T>& rhs);
	void Clear();
	void PopBack();
	~Vector();

private:
	void Realloc(size_t newCapacity);
private:
	T* m_data = nullptr;
	size_t m_size = 0;
	size_t m_capacity = 0;
};

template<typename T>
inline Vector<T>::Vector()
	:m_data(nullptr),m_size(0)
{
	Realloc(5);
}

template<typename T>
inline Vector<T>::Vector(const Vector& rhs)
{
	for (size_t i = 0; i < rhs.Size(); i++)
	{
		PushBack(rhs.m_data[i]);
	}
}

template<typename T>
inline Vector<T>::Vector(const Vector&& rhs)
{
	for (size_t i = 0; i < rhs.Size(); i++)
	{
		PushBack(rhs.m_data[i]);
	}
}

template<typename T>
inline constexpr size_t Vector<T>::Size() const
{
	return m_size;
}

template<typename T>
inline constexpr size_t Vector<T>::Capacity() const
{
	return m_capacity;
}

template<typename T>
inline void Vector<T>::PushBack(const T& value)
{
	if (m_size >= m_capacity)
	{
		if (m_capacity == 0)m_capacity = 1;
		Realloc(m_capacity*2);
	}
	m_data[m_size++] = value;
}

template<typename T>
inline constexpr T& Vector<T>::operator[](size_t pos) const
{
	return m_data[pos];
}

template<typename T>
inline T& Vector<T>::operator[](size_t pos)
{
	return m_data[pos];
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
{
	for (size_t i = 0; i < rhs.Size(); i++)
	{
		PushBack(rhs.m_data[i]);
	}
	return *this;
}

template<typename T>
inline void Vector<T>::Clear()
{
	delete[] m_data;
	m_size = 0;
	m_capacity = m_capacity / 2;
}

template<typename T>
inline void Vector<T>::PopBack()
{
	m_size--;
}

template<typename T>
inline Vector<T>::~Vector()
{
	delete[] m_data;
}

template<typename T>
inline void Vector<T>::Realloc(size_t newCapacity)
{
	T* newData = new T[newCapacity];
	m_capacity = newCapacity;
	for (size_t i = 0; i < m_size; i++)
	{
		newData[i] = std::move(m_data[i]);
	}
	delete[] m_data;
	m_data = newData;
}
