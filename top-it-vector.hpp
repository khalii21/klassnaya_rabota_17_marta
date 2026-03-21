#ifndef TOP_IT_VECTOR_HPP
#define TOP_IT_VECTOR_HPP
#include <cstddef>
#include <utility>
#include <cassert>

namespace khalikov
{
  template< class T >
  struct Vector
  {
    Vector();
    explicit Vector(size_t k);
    ~Vector();
    Vector(const Vector< T > &);
    Vector< T > & operator=(const Vector< T > & rhs);
    T & operator[](size_t id) noexcept;
    const T & operator[](size_t id) const noexcept;

    bool isEmpty() const noexcept;
    void pushBack(const T &);
    void popBack();
    size_t getSize() const noexcept;
    size_t getCapacity() const noexcept;
    void resize(size_t newCapacity);
		void swap(Vector< T > & rhs) noexcept;
		void pushFront(const T &);

  private:
    T * data_;
    size_t cap_, size_;
  };
}

template< class T >
size_t khalikov::Vector< T >::getSize() const noexcept
{
	return size_;
}

template< class T >
void khalikov::Vector< T >::pushFront(const T & val)
{
	Vector< T > cpy(getSize() + 1);
	cpy[0] = val;
	cpy.size_++;
	for(size_t i = 1; i < cpy.getSize(); i++)
	{
		cpy.data_[i] = data_[i-1];
		cpy.size_++;
	}
	swap(cpy);
}

template< class T >
size_t khalikov::Vector< T >::getCapacity() const noexcept
{
	return cap_;
}

template< class T >
bool khalikov::Vector< T >::isEmpty() const noexcept
{
	return !size_;
}

template< class T >
void khalikov::Vector< T >::popBack()
{
	Vector< T > cpy(size_ - 1);
	for(size_t i = 0; i < size_ - 1; i++)
	{
		cpy.data_[i] = data_[i];
		cpy.size_++;
	}
	swap(cpy);
}

template< class T >
khalikov::Vector< T >::Vector():
	data_(nullptr),
	cap_(0),
	size_(0)
{}

template< class T >
khalikov::Vector< T >::Vector(size_t k):
	data_(new T[k]),
	cap_(k),
	size_(0)
{}

template< class T >
khalikov::Vector< T >::~Vector()
{
	delete[] data_;
}

template< class T >
khalikov::Vector< T >::Vector(const Vector< T > & rhs):
	data_(nullptr),
	cap_(0),
	size_(0)
{
	Vector< T > temp(rhs.cap_);
	for(size_t i = 0; i < rhs.size_; i++)
	{
		temp[i] = rhs[i];
	}
	temp.size_ = rhs.size_;
	swap(temp);
}


template< class T >
void khalikov::Vector< T >::swap(Vector< T > & rhs) noexcept
{
	std::swap(rhs.data_, data_);
	std::swap(rhs.size_, size_);
	std::swap(rhs.cap_, cap_);
}

template< class T >
khalikov::Vector< T > & khalikov::Vector< T >::operator=(const Vector< T > & rhs)
{
	Vector< T > cpy(rhs);
	swap(rhs);
	return *this;
}

template< class T >
void khalikov::Vector< T >::resize(size_t newCapacity)
{
	Vector< T > res(newCapacity);
	size_t index = 0;
	for (size_t i = 0; i < size_; i++)
	{
		res[index++] = (*this)[i];
	}
	res.size_ = index;
	swap(res);
}

template< class T >
T & khalikov::Vector< T >::operator[](size_t id) noexcept
{
	assert(id < getSize());
	return data_[id];
}

template< class T >
const T & khalikov::Vector< T >::operator[](size_t id) const noexcept
{
	assert(id < getSize());
	return data_[id];
}

template< class T >
void khalikov::Vector< T >::pushBack(const T & val)
{
	if (cap_ > size_)
	{
		data_[size_] = val;
		size_++;
	}
	else
	{
		size_t newCapacity = cap_ + 5;
		resize(newCapacity);
		data_[size_] = val;
		size_++;
	}
}

#endif
