// problem 47

#include "util.hh"
#include "primes.h"

int main() {
  vector<int> pcount(500000);
  for (int i = 0; i < primes_length; i++)
    for (int j = 0; j < pcount.size(); j += primes[i])
      pcount[j] += 1;

  int ff[] = {4, 4, 4, 4};
  cout << distance(pcount.begin(),
                   search(pcount.begin(), pcount.end(),
                          ff, ff + len(ff)))
       << endl;
}
