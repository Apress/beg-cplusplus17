#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>                        // For standard exception types
#include <string>                           // For to_string()
#include <utility>                          // For std::as_const()

template <typename T, int startIndex>
class Array
{
private:
  T* elements;                              // Array of type T
  size_t size;                              // Number of array elements

public:
  explicit Array(size_t arraySize);         // Constructor
  Array(const Array& array);                // Copy Constructor
  ~Array();                                 // Destructor
  T& operator[](int index);                 // Subscript operator
  const T& operator[](int index) const;     // Subscript operator-const arrays
  Array& operator=(const Array& rhs);       // Assignment operator
  size_t getSize() const { return size; }   // Accessor for size
  void swap(Array& other) noexcept;
};

// Constructor
template <typename T, int startIndex>
Array<T, startIndex>::Array(size_t arraySize)
 : elements {new T[arraySize]}, size {arraySize}
{}

// Copy constructor
template <typename T, int startIndex>
Array<T, startIndex>::Array(const Array& array) 
	: Array{array.size}
{
  for (size_t i {} ; i < size ; ++i)
    elements[i] = array.elements[i];
}

// Destructor
template <typename T, int startIndex>
Array<T, startIndex>::~Array()
{
  delete[] elements;
}

// const subscript operator
template <typename T, int startIndex>
const T& Array<T, startIndex>::operator[](int index) const
{
  if (index < startIndex)
    throw std::out_of_range{"Index too small: " + std::to_string(index)};

  if (index > startIndex + static_cast<int>(size) - 1)
    throw std::out_of_range{"Index too large: " + std::to_string(index)};

  return elements[index - startIndex];
}

// Non-const subscript operator
template <typename T, int startIndex>
T& Array<T, startIndex>::operator[](int index)
{
  // Use the 'const-and-back-again' idiom to avoid code duplication:
  return const_cast<T&>(std::as_const(*this)[index]);
}

// Assignment operator
template <typename T, int startIndex>
Array<T, startIndex>& Array<T, startIndex>::operator=(const Array& rhs)
{
  auto copy{rhs};        // Copy...        (could go wrong and throw an exception)
  swap(copy);            // ... and swap!  (noexcept)
  return *this;
}

// noexcept swap member function
template <typename T, int startIndex>
void Array<T, startIndex>::swap(Array& other) noexcept
{
	std::swap(elements, other.elements);
	std::swap(size, other.size);
}

// Conventional noexcept swap non-member function
template <typename T, int startIndex>
void swap(Array<T, startIndex>& one, Array<T, startIndex>& other) noexcept
{
	one.swap(other);     // Forward to public member function
}

#endif