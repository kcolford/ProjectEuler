// Problem 110

// Find the first value for n, such that the equation 1/x + 1/y = 1/n
// has more than 4 million (4,000,000) possible solutions.
// 
// The answer is: 9350130049860600

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
  // Note that we use int64_t because 32-bit ints are too small.
  int64_t n_min = numeric_limits<int64_t>::max();

  for (int c = 4000001; c < 4100000; c++) {
    int     p = 0;
    int64_t n = 1;

    foreach_r (int i, prime_factors(c * 2 - 1)) {
      // Adjust i so that it is half of what it's supposed to be, that
      // way we end up computing n instead of n*n.
      i = (i - 1) / 2;

      // Choose the smallest prime as a base for the largest exponent.
      assert(p < primes_length);
      int e = primes[p++];

      // Use the square and multiply method with bit twiddling to
      // speed up this innermost loop.
      do {
        if (i & 1)
          n *= e;
        e *= e;
      } while ((i >>= 1));
    }
    if (0 < n && n < n_min)
      n_min = n;
  }

  assert(n_min < numeric_limits<int64_t>::max()); // sanity check

  cout << n_min << endl;

  return 0;
}
