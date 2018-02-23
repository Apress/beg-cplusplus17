// Rational.h

#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational
{
private:
  int n, d;

public:
  // Constructor
  Rational(int numerator = 0, int denominator = 1) 
	: n {numerator}, d {denominator} {}

  // Accessors
  int getNumerator() const { return n; }
  int getDenominator() const { return d; }
  
  // Mutators
  void setNumerator(int n) { this->n = n; }
  void setDenominator(int d) { this->d = d; }
  
  // Casting operators (could be non-explicit as well: is a matter of taste)
  explicit operator double() const { return static_cast<double>(n) / d; }
  explicit operator float() const { return static_cast<float>(n) / d; }
  
  // Binary comparison operators with double
  bool operator<(double d) const { return static_cast<double>(*this) < d; }
  bool operator>(double d) const { return static_cast<double>(*this) < d; }
  bool operator==(double d) const { return static_cast<double>(*this) == d; }
  bool operator!=(double d) const { return static_cast<double>(*this) != d; }
  bool operator<=(double d) const { return static_cast<double>(*this) <= d; }
  bool operator>=(double d) const { return static_cast<double>(*this) >= d; }
  
  // Unary arithmetic operator
  Rational operator-() const { return Rational{-n, d}; }   
  
  // Conversion-to-bool and negation operators.
  // A Rational is false if and only if its numerator equals zero.
  //
  // Note: for operator bool(), we used explicit here to sidestep ambiguities with other operators.
  // If you want implicit conversions to bool, 
  // you cannot rely anymore implicit conversions for any of the arithmetic or comparison operators:
  // you'll have to specify all combinations you want to support there explicitly.
  explicit operator bool() const  { return n != 0; }         
  bool operator!() const { return n == 0; }
  
  // Compound assignment operators
  Rational& operator+=(const Rational& other)
  {
	n = n * other.d + other.n * d;
	d = d * other.d;
	return *this;
  };
  Rational& operator-=(const Rational& other)
  { 
	n = n * other.d - other.n * d;
	d = d * other.d;
	return *this;
  };
  Rational& operator*=(const Rational& other)
  { 
	n *= other.n;
	d *= other.d;
	return *this;
  };
  Rational& operator/=(const Rational& other)
  { 
	n *= other.d;
	d *= other.n;
	return *this;
  };
  
  // Prefix and postfix increment and decrement operators
  Rational& operator++() 
  { 
	n += d;
	return *this;
  }
  const Rational operator++(int)
  {
	auto copy(*this);              // Create a copy of the current object
	++(*this);                     // Increment the current object using the prefix operator...
	return copy;                   // Return the unincremented copy
  }
  Rational& operator--() 
  { 
	n -= d;
	return *this;
  }

  const Rational operator--(int)
  {
	auto copy(*this);              // Create a copy of the current object
	--(*this);                     // Increment the current object using the prefix operator...
	return copy;                   // Return the unincremented copy
  }
};

// Stream output operator
inline std::ostream& operator<<(std::ostream& stream, const Rational& r)
{
	return stream << r.getNumerator() << '/' << r.getDenominator();
}

// Binary comparison operators for two Rational: non-member functions to allow for implicit conversions.
// This allows expressions such as 1 == myRational and myRational < 10
inline bool operator<(const Rational& one, const Rational& other)
{
	return one.getNumerator() * other.getDenominator() < other.getNumerator() * one.getDenominator();
}
inline bool operator==(const Rational& one, const Rational& other)
{
	return one.getNumerator() * other.getDenominator() == other.getNumerator() * one.getDenominator();
}
inline bool operator>(const Rational& one, const Rational& other)
{
	return one.getNumerator() * other.getDenominator() > other.getNumerator() * one.getDenominator();
}
inline bool operator!=(const Rational& one, const Rational& other)
{
	return one.getNumerator() * other.getDenominator() != other.getNumerator() * one.getDenominator();
}
inline bool operator>=(const Rational& one, const Rational& other)
{
	return one.getNumerator() * other.getDenominator() >= other.getNumerator() * one.getDenominator();
}
inline bool operator<=(const Rational& one, const Rational& other)
{
	return one.getNumerator() * other.getDenominator() <= other.getNumerator() * one.getDenominator();
}

// Binary comparison operators for a double and a Rational: must be non-member function.
inline bool operator<(double d, const Rational& r)
{
	return d < static_cast<double>(r);
}
inline bool operator>(double d, const Rational& r)
{
	return d > static_cast<double>(r);
}
inline bool operator==(double d, const Rational& r)
{
	return d == static_cast<double>(r);
}
inline bool operator!=(double d, const Rational& r)
{
	return d != static_cast<double>(r);
}
inline bool operator<=(double d, const Rational& r)
{
	return d <= static_cast<double>(r);
}
inline bool operator>=(double d, const Rational& r)
{
	return d >= static_cast<double>(r);
}

// Binary arithmetic operators: non-member functions to allow for implicit conversions
// This allows expressions such as 2 * (myRationale + 1)
inline Rational operator+(const Rational& one, const Rational& other) { Rational copy{ one }; return copy += other; }
inline Rational operator-(const Rational& one, const Rational& other) { Rational copy{ one }; return copy -= other; }
inline Rational operator*(const Rational& one, const Rational& other) { Rational copy{ one }; return copy *= other; }
inline Rational operator/(const Rational& one, const Rational& other) { Rational copy{ one }; return copy /= other; }

#endif