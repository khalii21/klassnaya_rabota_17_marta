#ifndef TOP_IT_VECTOR_HPP
#define TOP_IT_VECTOR_HPP
#include <cstddef>
#include <utility>

namespace khalikov
{
  template< class T >
  struct Vector
  {
    Vector();
    explicit Vector(size_t k);
    ~Vector();
    Vector(const Vector< T > &) = delete;
    Vector< T > & operator=(const Vector< T > & rhs);
    T & operator[](size_t id) noexcept;
    const T & operator[](size_t id) const noexcept;

    bool isEmpty() const noexcept;
    void pushBack(const T &);
    void popBack();
    size_t getSize() const noexcept;
    size_t getCapacity() const noexcept;
    Vector< T > & resize(size_t newCapacity);
		void swap(Vector< T > & rhs) noexcept;

  private:
    T * data_;
    size_t cap_, size_;
  };
}

template< class T >
bool khalikov::Vector< T >::isEmpty() const noexcept
{
	return !size_;
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
void khalikov::Vector< T >::swap(Vector< T > & rhs) noexcept
{
	std::swap(rhs.data_, data_);
	std::swap(rhs.size_, size_);
	std::swap(rhs.capacity_, cap_);
}

template< class T >
khalikov::Vector< T > & khalikov::Vector< T >::operator=(const Vector< T > & rhs)
{
	Vector< T > cpy(rhs);
	swap(rhs);
	return *this;
}

template< class T >
khalikov::Vector< T > & khalikov::Vector< T >::resize(size_t newCapacity)
{
	Vector< T > res(newCapacity);
	for (size_t i = 0; i < size_; i++)
	{
		res[res.size_++] = (*this)[i];
	}
	return res;
}

template< class T >
T & khalikov::Vector< T >::operator[](size_t id) noexcept
{}

template< class T >
const T & khalikov::Vector< T >::operator[](size_t id) const noexcept
{}

template< class T >
void khalikov::Vector< T >::pushBack(const T & val)
{
	if (cap_ > size_)
	{
		(*this)[size_] = val;
		size_++;
	}
	else
	{
		size_t newCapacity = cap_ + 5;
		resize(newCapacity);
		(*this)[size_] = val;
		size_++;
	}
}

#endif
