// problem 49

#include "util.hh"
#include "primes.hh"
#include "digit_iterator.hh"

#include <set>

int main() {
  
#define last_prime (2 * primes[j] - primes[i])

  int upper = prime_index_of(10000);

  for (int i = prime_index_of(1493); i < upper; i++)
    for (int j = i + 1; last_prime <= primes[upper]; j++)
      if (binary_search(primes, primes + upper, last_prime)) {
        set<int> 
          s1(decimal_iterator(primes[i]), decimal_iterator()),
          s2(decimal_iterator(primes[j]), decimal_iterator()),
          s3(decimal_iterator(last_prime), decimal_iterator());

        if (!(s1 == s2 && s2 == s3))
          continue;

        cout << primes[i] << primes[j] << last_prime << endl;
      }
}

        
