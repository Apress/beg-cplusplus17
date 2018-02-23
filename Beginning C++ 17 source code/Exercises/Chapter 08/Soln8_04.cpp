// Exercise 8_4 An overloaded plus() function. 
#include <iostream>
#include <string>
#include <string_view>

int plus(int a, int b);
double plus(double x, double y);
std::string plus(std::string_view s1, std::string_view s2);

int main()
{
  const int n {plus(3, 4)};
  std::cout << "plus(3, 4) returns " << n << std::endl;
  
  const double d {plus(3.2, 4.2)};
  std::cout << "plus(3.2, 4.2) returns " << d << std::endl;
  
  const std::string s {plus("he", "llo")};
  std::cout << "plus(\"he\", \"llo\") returns " << s << std::endl;
  
  const std::string s1 {"aaa"};
  const std::string s2 {"bbb"};
  const std::string s3 {plus(s1, s2)};
  std::cout << "With s1 as " << s1 << " and s2 as " << s2 << std::endl;
  std::cout << "plus(s1, s2) returns " << s3 << std::endl;

  /*
  const auto d {plus(3, 4.2)};
  This won't compile because there is more than one overloaded plus() function for the arguments.
  The compiler will not choose so there must be a unique match with a function signature.
  */
}

// Adding integer values
inline int plus(int a, int b)
{
  return a + b;
}

// Adding floating-point values
inline double plus(double x, double y)
{
  return x + y;
}

// Adding strings
inline std::string plus(std::string_view s1, std::string_view s2)
{
  // return s1 + s2; does not compile in this case, 
  // because there is no addition operator (+) for string_view.
  // Therefore, you first have to turn the operands into std::strings...
  return std::string{s1} + std::string{s2};
}