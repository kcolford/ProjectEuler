// problem 10

#include "util.hh"
#include "primes.hh"

int main()
{
  long long o = 0;
  for (int i = 0; primes[i] < 2000000; i++)
    o += primes[i];
  cout << o << endl;
}
