// problem 16

#include "util.hh"
#include "digit_breakdown.hh"
#include <gmpxx.h>

int main()
{
  mpz_class n = 2;
  n <<= 1000;
  digit_breakdown b = n;
  cout << b.sum() << endl;
}
