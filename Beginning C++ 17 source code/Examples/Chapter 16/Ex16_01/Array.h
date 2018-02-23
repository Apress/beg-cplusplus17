// This solution uses the const-and-back-again idiom to avoid code duplication
// between the non-const and const overloads of the array subscript operators.
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
  Array& operator=(const Array& rhs);       // Assignment operator
  T& operator[](size_t index);              // Subscript operator
  const T& operator[](size_t index) const;  // Subscript operator-const arrays
  size_t getSize() const { return size; }   // Accessor for size
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

// Copy assignment operator in terms of the copy constructor
template <typename T> 
Array<T>& Array<T>::operator=(const Array& rhs)
{
  if (&rhs != this)                         // If lhs != rhs...
  {                                         // ...do the assignment...
    delete[] elements;                      // Release any free store memory

    size = rhs.size;                        // Copy the members of rhs into lhs
    elements = new T[size];
    for (size_t i {}; i < size; ++i)
      elements[i] = rhs.elements[i];
  }
  return *this;                             // ... return lhs
}

#endif