// Exercise 15-5 Customer.cpp
// A simple C++ customer class

#include "Customer.h"

Customer::Customer(
      std::string_view aSurname,
      std::string_view aName,
      std::string_view aStreet,
      int aStreetNumber,
      std::string_view aCity)
  : surname(aSurname)
  , name(aName)
  , street(aStreet)
  , streetNumber(aStreetNumber)
  , city(aCity)
{}

std::string Customer::ToString() const
{
  std::string result;
  result += surname;
  result += ' ';
  result += name;
  result += ", ";
  result += street;
  result += ' ';
  result += std::to_string(streetNumber);
  result += ", ";
  result += city;
  return result;
}