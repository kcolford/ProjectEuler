// Problem 108

#include "util.hh"
#include "factoring.hh"
#include "foreach.hh"

int main()
{
  int m = numeric_limits<int>::max();
  for (int c = 1000; c < 2000; c++) {
    long p = 0;
    int n = 1;
    foreach_r (int i, prime_factors(c * 2 - 1)) {
      int e = primes[p++];
      i--;
      while ((i >>= 1)) {
        if (i & 1) n *= e;
        e *= e;
      }
    }
    if (0 < n && n < m) m = n;
  }
  cout << m << endl;

  return 0;
}
