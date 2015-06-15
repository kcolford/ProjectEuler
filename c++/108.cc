// Problem 108

#include "util.hh"
#include "factoring.hh"
#include "foreach.hh"
#include "primes.hh"
#include <gmpxx.h>

int main()
{
#if 1

  mpz_class m("328932743289472389479328479");
  for (int c = 1001; ; c++) {
    int p = 0;
    mpz_class n = 1;
    foreach (int i, prime_factors(c)) {
      mpz_class e;
      mpz_ui_pow_ui(e.get_mpz_t(), primes[p++], i - 1);
      n *= e;
    }
    m = min(m, n);
    if (m == n)
      cout << n << endl;
  }
  cout << m << endl;

#else

#define int long long
  int m = 0;
  for (int n = 1; ; n++) {
    int val = 2;
    for (int z = 2; z < n; z++)
      if ((n * n) % z == 0)
        val++;
    m = max(m, val);

    if (0) {
      cout << "n = " << n << "   \t"
           << "val = " << val << "    \t"
           << "m = " << m << "\t"
           << endl;
    }
    if (0 && m == val) {
      cout << "n = " << n << "    \t"
           << "m = " << m << "    \t"
           << endl;
    }

    if (val > 1000) {
      cout << val << endl;
      break;
    }
  }

#endif

  return 0;
}
