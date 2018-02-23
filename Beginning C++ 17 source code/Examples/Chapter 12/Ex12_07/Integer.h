#ifndef INTEGER_H
#define INTEGER_H

class Integer
{
private:
  int n; 
public:
  Integer(int m = 0) : n{m} {}
  int getValue() const { return n; }
  void setValue(int m) { n = m; }   
};

Integer operator+(const Integer& one, const Integer& other)
{
  return one.getValue() + other.getValue();
}
Integer operator-(const Integer& one, const Integer& other)
{
  return one.getValue() - other.getValue();
}
Integer operator*(const Integer& one, const Integer& other)
{
  return one.getValue() * other.getValue();
}
Integer operator/(const Integer& one, const Integer& other)
{
  return one.getValue() / other.getValue();
}
Integer operator%(const Integer& one, const Integer& other)
{
  return one.getValue() % other.getValue();
}

#endif
