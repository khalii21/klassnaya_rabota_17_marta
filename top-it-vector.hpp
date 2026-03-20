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

    bool isEmpty() const noexcept;


  private:
    T * data_;
    size_t cap_, size_;
  };
}

#endif
