#pragma once

template<typename Vector>
class VectorIterator
{
public:
	using ValueType = typename Vector::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;
public:
	VectorIterator(PointerType ptr):m_ptr(ptr){}
	VectorIterator& operator++()
	{
		m_ptr++;
		return *this;
	}
	VectorIterator operator++(int)
	{
		VectorIterator iterator = *this;
		++(*this);
		return iterator;
	}
	VectorIterator& operator--()
	{
		m_ptr--;
		return *this;
	}
	VectorIterator operator--(int)
	{
		VectorIterator iterator = *this;
		--(*this);
		return iterator;
	}

	ReferenceType operator[](int index)
	{
		return *(m_ptr + index);
	}

	PointerType operator->()
	{
		return m_ptr;
	}
	ReferenceType operator*()
	{
		return *m_ptr;
	}

	bool operator==(const VectorIterator& right) const
	{
		return m_ptr == right.m_ptr;
	}
	bool operator!=(const VectorIterator& right) const
	{
		return !(*this == right);
	}

private:
	PointerType m_ptr;
};

template<typename T>
class Vector
{
public:
	using ValueType = T;
	using Iterator = VectorIterator<Vector<T>>;
public:
	Vector();
	Vector(const Vector& rhs);
	Vector(const Vector&& rhs);
	constexpr size_t Size()const;
	constexpr size_t Capacity()const;
	void PushBack(const T& value);
	void PushBack(const T&& value);
	constexpr T& operator [](size_t pos) const;
	T& operator [](size_t pos);
	Vector<T>& operator=(const Vector<T>& rhs);
	void Clear();
	void PopBack();
	~Vector();
	Iterator begin()
	{
		return Iterator(m_data);
	}
	Iterator end()
	{
		return Iterator(m_data + m_size);
	}
public:

	Vector(const std::initializer_list<T>& list)
	{
		for (auto x : list)
		{
			PushBack(x);
		}
	}

	Vector(const T& noOfTimes, const T& value)
	{
		for (size_t i = 0; i < noOfTimes; i++)
		{
			PushBack(value);
		}
	}

	template<typename... Args>
	T& EmplaceBack(Args && ...args)
	{
		if (m_size >= m_capacity)
		{
			if (m_capacity == 0)m_capacity = 1;
			Realloc(m_capacity * 2);
		}
		new(&m_data[m_size]) T(std::forward<Args>(args)...);
		//m_data[m_size] = T(std::forward<Args>(args)...);
		return m_data[m_size++];
	}

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
		//if (m_capacity == 0)m_capacity = 1;
		Realloc(m_capacity + m_capacity/2 + 1);
	}
	m_data[m_size++] = value;
}

template<typename T>
inline void Vector<T>::PushBack(const T&& value)
{
	if (m_size >= m_capacity)
	{
		if (m_capacity == 0)m_capacity = 1;
		Realloc(m_capacity * 2);
	}
	m_data[m_size++] = std::move(value);
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
	for (size_t i = 0; i < m_size; i++)
	{
		m_data[i].~T();
	}
	m_size = 0;
}

template<typename T>
inline void Vector<T>::PopBack()
{
	if (m_size > 0)
	{
		m_size--;
		m_data[m_size].~T();
	}
}

template<typename T>
inline Vector<T>::~Vector()
{
	Clear();
	::operator delete(m_data, m_capacity * sizeof(T));
}

template<typename T>
inline void Vector<T>::Realloc(size_t newCapacity)
{
	//T* newData = new T[newCapacity];
	T* newData = (T*)::operator new(newCapacity * sizeof(T));
	m_capacity = newCapacity;
	for (size_t i = 0; i < m_size; i++)
	{
		newData[i] = std::move(m_data[i]);
	}

	for (size_t i = 0; i < m_size; i++)
	{
		m_data[i].~T();
	}

	//delete[] m_data;
	::operator delete(m_data, m_capacity * sizeof(T));
	m_data = newData;
}
