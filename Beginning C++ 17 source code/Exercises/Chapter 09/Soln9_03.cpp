// Exercise 9-3.cpp
// Defining a function template for adding numbers, 
// and an overload that works for pointer types.
// Extra: also make plus() work with string literals...
#include <iostream>
#include <string>
#include <string_view>

template <typename T>
T plus(const T a, const T b)
{
	return a + b;
}

// Overload with another template for pointer types
template <typename T>
T plus(const T* a, const T* b)
{
	return *a + *b;
}

/*
As for the extra part of the exercice: here are some attempts that won't work (and why):

(1) Because the return type does not match that of the second template, 
    the following is a specialization of the first template.
	
    template <>
    const char* plus(const char* a, const char* b)
    {
      return (std::string{ a } + b).c_str();
    }

	When calling plus("he", "llo"), however, the compiler unfortunately 
	still prefers the overload with the pointers!
	It also has another serious problem, which it shares with our next attempt:

(2) The following overload will compile and get called: 

    const char* plus(const char* a, const char* b)
    {
	  return (std::string{ a } +b).c_str();             // never return pointer to (the internals of) a local object!!!
    }

	It may even appear to be working with certain compilers. 
	However, to concatenate the string, the compiler has to create a temporary
	std::string object, which it stores on the stack.
	After the function is done executing, this temporary object ceases to exist;
	as does the character array it contains.
	What this function returns is thus a so-called dangling pointer to 
	already released memory. This may work if your very lucky,
	but in other cases it will either produce garbage output or even crash!

(3) Using an overload with std::string_view won't work either in this case,
    as the compiler would still prefer the template that accepts pointers.
	The reason is that std::string_view needs a conversion, 
	whereas a function that takes const char* pointers does not.

A correct solution is therefore to create an overload that returns a new object:
*/
std::string plus(const char* a, const char* b)
{
	return std::string{ a } + b;
}

int main()
{
	int n{ plus(3, 4) };
	std::cout << "plus(3, 4) returns " << n << std::endl;
	
	double d{ plus(3.2, 4.2) };
	std::cout << "plus(3.2, 4.2) returns " << d << std::endl;
	
	std::string s1{ "aaa" };
	std::string s2{ "bbb" };
	auto s3 = plus(s1, s2);
	std::cout << "With s1 as " << s1 << " and s2 as " << s2 << std::endl;
	std::cout << "plus(s1, s2) returns " << s3 << std::endl;

	// The extra part:
	std::string s{ plus("he", "llo") };
	std::cout << "plus(\"he\", \"llo\") returns " << s << std::endl;
}