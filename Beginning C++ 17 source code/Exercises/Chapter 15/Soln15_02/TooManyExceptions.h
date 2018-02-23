// Exercise 15-2 TooManyExceptions.h
// Definition of TooManyExceptions exception class

#ifndef TOOMANYEXCEPTIONS_H
#define TOOMANYEXCEPTIONS_H
#include <exception>

class TooManyExceptions : public std::exception
{
public:
  const char* what() const noexcept override;
};

#endif //TOOMANYEXCEPTIONS_H