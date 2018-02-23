// Array.h
// Same as Ex16_01A, but with push_back() and default constructor
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
  Array();                                  // Default constructor
  explicit Array(size_t arraySize);         // Constructor
  Array(const Array& array);                // Copy constructor
  ~Array();                                 // Destructor
  Array& operator=(const Array& rhs);       // Assignment operator
  T& operator[](size_t index);              // Subscript operator
  const T& operator[](size_t index) const;  // Subscript operator-const arrays
  void push_back(const T& element);         // Function to add new element to the end
  size_t getSize() const { return size; }   // Accessor for size
  void swap(Array& other) noexcept;         // noexcept swap member function
};

// Constructor
template <typename T>                      // This is a template with parameter T 
Array<T>::Array(size_t arraySize) :  size {arraySize}, elements {new T[arraySize]}
{}

// Default constructor
template <typename T>
Array<T>::Array() : Array{0}
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
Array<T>& Array<T>::operator=(const Array& rhs)
{
  auto rhsCopy(rhs);    // Copy...   (might throw an exception)
  swap(rhsCopy);        // ... and swap!  (noexcept)
  return *this;         // Return lhs
}

// Function to add new element to the end of the array
// Uses the 'copy-and-swap' idiom.
// If either the Array<> constructor throws (std::bad_alloc or some exception 
// from T's default constructor) or any of the copy assignments of a T element,
// then the original Array<> remains untouched.
template <typename T>
void Array<T>::push_back(const T& newElement)
{
  Array<T> copy(size + 1);            // Copy...
  for (size_t i = 0; i < size; ++i)
    copy[i] = elements[i];

  copy[size] = newElement;            // ... modify ...
  
  swap(copy);                         // ... and swap!  (noexcept)
}

/*
Alternative solution using std::unique_ptr<> 
(do not forget to increment the size!)

#include <memory>

template <typename T>
void Array<T>::push_back(const T& newElement)
{
  auto newElements = std::make_unique<T[]>(size + 1);
  for (size_t i = 0; i < size; ++i)
    newElements[i] = elements[i];

  newElements[size] = newElement;
  
  elements = newElements.release();
  ++size;
}
*/

/*
Alternative solution using raw pointers and try/catch
(least recommended: memory allocation should always use RAII;
in a way you are writing the more low-level code the compiler generates
for you when using an RAII approach)

template <typename T>
void Array<T>::push_back(const T& newElement)
{
  auto newElements{ new T[size + 1] };
  try
  {
    for (size_t i = 0; i < size; ++i)
      newElements[i] = elements[i];
  
    newElements[size] = newElement;
  }
  catch (...)
  {
    delete[] newElements;
	throw;
  }
  
  elements = newElements.release();
  ++size;
}
*/

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