// Exercise 15-2 TooManyExceptions.cpp
// Implementation of TooManyExceptions exception class

#include "TooManyExceptions.h"

const char* TooManyExceptions::what() const noexcept
{
  return "TooManyExceptions exception";
}