/*
	The use of the static keyword to specify internal linkage is no longer recommended: 
	you should always use a nameless namespace instead!
*/

// Recursive function to calculate x to the power n for unsigned exponents
// This is a local helper function, 
// and hence has been specified to have internal linkage.
static double compute(double x, unsigned n)
{
  return n == 0? 1.0 : x * compute(x, n - 1);
}

double power(double x, int n)
{
  return n >= 0? compute(x, static_cast<unsigned>(n)) 
               : 1.0 / compute(x, static_cast<unsigned>(-n));
}
