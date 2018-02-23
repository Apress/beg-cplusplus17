// Exercise 11-4 Integer.h

#ifndef INTEGER_H
#define INTEGER_H

class Integer
{
private:
  int n;

public:
  Integer(int m = 0);
  Integer(const Integer& obj);
  friend int compare(const Integer& obj1, const Integer& obj2);  // friend compare function
  int getValue() const { return n; }
  void setValue(int m) { n = m; }
  void show() const;
};

// A non-friend function that implements the same function
int nonFriendCompare(const Integer& obj1, const Integer& obj2);

#endif