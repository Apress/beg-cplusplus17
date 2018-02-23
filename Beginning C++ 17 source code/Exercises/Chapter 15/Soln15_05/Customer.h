// Exercise 15-5  Customer.h
// A simple C++ customer class

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <string_view>

class Customer
{
public:
  Customer(
      std::string_view surname,
      std::string_view name,
      std::string_view street,
      int streetNumber,
      std::string_view city
  );

  std::string ToString() const;
  
private:
  std::string surname;
  std::string name;
  std::string street;
  int streetNumber;
  std::string city;
};

#endif