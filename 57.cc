// problem 57

#include "util.hh"
#include <gmpxx.h>

int main()
{
  mpq_class frac = 1;
  int c = 0;
  for (int i = 0; i < 1000; i++) {
    mpz_class n = frac.get_num(), d = frac.get_den();
    while (n != 0 && d != 0) {
      n /= 10;
      d /= 10;
    }
    if (n != 0)
      c += 1;
    
    frac = 1 + 1/(1 + frac);
  }
  cout << c << endl;
}
