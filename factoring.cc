// Compute factors of a number

#include <algorithm>
#include <cassert>
#include <climits>
#include "factoring.hh"
#include "primes.hh"

using namespace std;

bool is_prime(int n)
{
  if (n < primes_upperbound)
    return binary_search(primes, primes_end, n);
  
  for (int i = 0; n / primes[i] < primes[i]; i++)
    if (n % primes[i] == 0)
      return false;
  return true;
}

int prime_index_of(int n)
{
  return distance(primes, lower_bound(primes, primes_end, n));
}

vector<int> prime_factors(long long n)
{
  vector<int> out;
  for (int i = 0; i < primes_length; i++) {
    if (n < INT_MAX && n / primes[i] < primes[i]) {
      assert(is_prime(n));
      out.push_back(n);
      break;
    }
    if (n % primes[i] == 0) {
      n /= primes[i];
      out.push_back(primes[i]);
    }
  }
  return out;
}

