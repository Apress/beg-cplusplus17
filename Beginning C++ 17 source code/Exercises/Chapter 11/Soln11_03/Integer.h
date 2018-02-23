// Exercise 11-3 Integer.h
#ifndef INTEGER_H
#define INTEGER_H
class Integer
{
private:
  int n;

public:
  Integer(int m = 0);
  Integer(const Integer& obj);
  int compare(const Integer& obj) const;
  int getValue() const { return n; }
  void setValue(int m) { n = m; }
  void show() const;

  Integer& add(const Integer& obj);
  Integer& subtract(const Integer& obj);
  Integer& multiply(const Integer& obj);
};
#endif