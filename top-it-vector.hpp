#ifndef TOP_IT_VECTOR_HPP
#define TOP_IT_VECTOR_HPP
#include <cstddef>

namespace khalikov
{
  template< class T >
  struct Vector
  {
    Vector();
    ~Vector();
    Vector(const Vector< T > &) = delete;
    Vector< T > & operator=(const Vector< T > &) = delete;

    bool isEmpty() const noexcept;


  private:
    T * data_;
    size_t cap_, size_;
  };
}

template< class T >
bool khalikov::Vector< T >::isEmpty() const noexcept
{
	return false;
}

template< class T >
khalikov::Vector< T >::Vector():
	data_(nullptr),
	size_(0),
	cap_(0)
{}

template< class T >
khalikov::Vector< T >::~Vector()
{
	delete[] data_;
}

#endif
