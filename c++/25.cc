// problem 25

#include "util.hh"
#include <gmpxx.h>

int main()
{
  mpz_class a = 0, b = 1;
  int i = 0;
  while (a.get_str(10).size() < 1000) {
    mpz_class t = a + b;
    a = b;
    b = t;
    i++;
  }
  cout << i << endl;
}
