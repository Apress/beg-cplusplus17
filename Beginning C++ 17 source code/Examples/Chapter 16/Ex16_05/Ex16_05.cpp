// Disambiguating dependant names: this code will not compile. 
// You can uncomment the /*typename*/ to make it compile.

template <typename T>
class Outer
{
public:
  class Nested { /* ... */ };

  Nested getNested() const;
};

template <typename T>
/*typename*/ Outer<T>::Nested Outer<T>::getNested() const
{
  return Nested{ /* ... */ };
}

template <typename T>
void foo(/* ... */)
{
  Outer<T> outer;
  Outer<T>::Nested nested = outer.getNested();
}

int main()
{
}
