// Definition of a basic function call operator
#include "Less.h"

bool Less::operator()(int a, int b) const
{
	return a < b;
}
