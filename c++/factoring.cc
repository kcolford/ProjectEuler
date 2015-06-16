// Compute factors of a number

#include <algorithm>
#include <cassert>
#include <climits>
#include <map>
#include "factoring.hh"
#include "primes.hh"
#include "sum.hh"

#ifndef ENABLE_PRIME_FACTOR_CACHE
# define ENABLE_PRIME_FACTOR_CACHE 0
#endif

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

// Return a vector of the prime factors of n.  The vector is sorted in
// ascending order.
vector<int> prime_factors(long long n)
{
#if ENABLE_PRIME_FACTOR_CACHE
  static map<long long, vector<int> > cache;
  if (cache.count(n))
    return cache[n];
  long long n_ = n;
#endif

  vector<int> out;
  for (int i = 0; n != 1 && i < primes_length; i++) {
    if (n < INT_MAX && n / primes[i] < primes[i]) {
      assert(is_prime(n));
      out.push_back(n);
      break;
    }
    while (n % primes[i] == 0) {
      n /= primes[i];
      out.push_back(primes[i]);
    }
  }

#if ENABLE_PRIME_FACTOR_CACHE
  cache[n_] = out;
#endif
  return out;
}

vector<int> low_factors(long long n)
{
  assert(n > 0);
  vector<int> out;
  out.push_back(1);
  for (int i = 2; n / i >= i; i++)
    if (n % i == 0)
      out.push_back(i);
  return out;
}

// Return a set of all the factors of n, including 1 and n.
set<long long> factors(long long n)
{
  assert(n > 0);
  set<long long> out = {1, n};
  for (int i = 2; n / i >= i; i++)
    if (n % i == 0) {
      out.insert(i);
      out.insert(n / i);
    }
  return out;
}

int factor_sum(long long n)
{
  return sum(factors(n));
}

int count_factors(long long n)
{
  assert(n > 0);
  vector<int> p = prime_factors(n);
  int count = 1;
  for (int i = 0, j = 0; i < p.size(); i = j) {
    int c = 2;
    for (j = i + 1; j < p.size() && p[i] == p[j]; j++, c++)
      ;
    count *= c;
  }
  return count;
}
