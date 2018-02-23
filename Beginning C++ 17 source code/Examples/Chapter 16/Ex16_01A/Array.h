// This variant of the template uses copy-and-swap for a memory-safe copy assignment operator
#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>                        // For standard exception types
#include <string>                           // For std::to_string()
#include <utility>                          // For std::as_const()

template <typename T>
class Array
{
private:
  T* elements;                              // Array of type T
  size_t size;                              // Number of array elements

public:
  explicit Array(size_t arraySize);         // Constructor
  Array(const Array& array);                // Copy constructor
  ~Array();                                 // Destructor
  Array& operator=(Array rhsCopy);          // Assignment operator
  T& operator[](size_t index);              // Subscript operator
  const T& operator[](size_t index) const;  // Subscript operator-const arrays
  size_t getSize() const { return size; }   // Accessor for size
  void swap(Array& other) noexcept;         // noexcept swap member function
};

// Constructor
template <typename T>                      // This is a template with parameter T 
Array<T>::Array(size_t arraySize) : elements{ new T[arraySize] }, size{ arraySize }
{}

// Copy constructor
template <typename T>
Array<T>::Array(const Array& array) : Array{array.size}
{
  for (size_t i {}; i < size; ++i)
    elements[i] = array.elements[i];
}

// Destructor
template <typename T> 
Array<T>::~Array()
{
  delete[] elements;
}

// const subscript operator
template <typename T>
const T& Array<T>::operator[](size_t index) const
{
  if (index >= size) 
	  throw std::out_of_range {"Index too large: " + std::to_string(index)};

  return elements[index];
}

// Non-const subscript operator in terms of const one
// Uses the 'const-and-back-again' idiom
template <typename T>
T& Array<T>::operator[](size_t index)
{
  return const_cast<T&>(std::as_const(*this)[index]);
}

// Assignment operator in terms of the copy constructor
// Uses the 'copy-and-swap' idiom.
template <typename T>
Array<T>& Array<T>::operator=(Array rhsCopy)  // Copy...
{
  swap(rhsCopy);        // ... and swap!  (noexcept)
  return *this;         // Return lhs
}

// noexcept swap member function
template <typename T>
void Array<T>::swap(Array& other) noexcept
{
  std::swap(elements, other.elements);
  std::swap(size, other.size);
}

// Conventional noexcept swap non-member function
template <typename T>
void swap(Array<T>& one, Array<T>& other) noexcept
{
  one.swap(other);     // Forward to public member function
}

#endif