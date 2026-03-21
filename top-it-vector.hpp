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
    void pushBack(const T &);
    void popBack();
    size_t getSize() const noexcept;
    size_t getCapacity() const noexcept;


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
khalikov::Vector< T >::~Vector()
{
	delete[] data_;
}

template< class T >
void khalikov::Vector< T >::pushBack(const T &)
{}

#endif
