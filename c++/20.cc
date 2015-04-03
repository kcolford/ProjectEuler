// problem 20

#include "util.hh"
#include <gmpxx.h>
#include "digit_breakdown.hh"

int main()
{
  mpz_class val = 1;
  for (int i = 1; i <= 100; i++)
    val *= i;
  digit_breakdown b(val);
  cout << b.sum() << endl;
}
