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
  private:
    T * data;
    size_t cap, size;
  };
}
