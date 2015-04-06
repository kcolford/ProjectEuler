// problem 26

#include "util.hh"
#include "primes.hh"
#include "multiplicative_order.hh"

// For the solution this time, seen
// http://mathworld.wolfram.com/FullReptendPrime.html

int main()
{
  int n = prime_index_of(1000);
  while (multiplicative_order(10, primes[n]) != primes[n] - 1)
    n--;
  cout << primes[n] << endl;
}
