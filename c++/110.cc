// Problem 110

// Find the first value for n, such that the equation 1/x + 1/y = 1/n
// has more than 4 million (4,000,000) possible solutions.

// The solution runs instantly with full optimizations turned on.  It
// uses the fact that 1/x + 1/y = 1/n is the same as y = n*n/(x - n) +
// n and then it just becomes a problem of finding the smallest n with
// a number of factors greater than or equal to 8,000,000.

#include "util.hh"              // convenience module 
#include "factoring.hh"         // the factoring module
#include "foreach.hh"           // wrapper around Boost.Foreach to
                                // provide C++11 like for-syntax

int main()
{
  // regular int's are too small, use a quick macro hack to fix it
#define int long long

  int m = numeric_limits<int>::max();
  for (int c = 4000001; c < 4100000; c++) {
    long p = 0;
    int n = 1;
    foreach_r (int i, prime_factors(c * 2 - 1)) {
      int e = primes[p++];      // there are more than 500,000 primes
                                // in this array so we should be fine
                                // for overflow

      // use the square and multiply method with bit twiddling to
      // speed up this innermost loop
      i--;
      while ((i >>= 1)) {
        if (i & 1) n *= e;
        e *= e;
      }
    }
    if (0 < n && n < m) m = n;
  }

  assert(m < numeric_limits<int>::max()); // sanity check

  cout << m << endl;

  return 0;
}
