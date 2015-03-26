// problem 50

#include "util.hh"
#include "primes.hh"

#define UPPERBOUND 1000000

int main() {
  vector<long long> sums(1, 0);
  sums.reserve(10 + prime_index_of(UPPERBOUND));

  for (int i = 0; primes[i] < UPPERBOUND; i++)
    sums.push_back(sums.back() + primes[i]);

  long long max = 41, terms = 6;
  for (int i = 7; i < sums.size(); i++) {
    for (int j = 0; j < i; j++) {
      long long p = sums[i] - sums[j];
      if (p < UPPERBOUND && is_prime(p)) {
        //cout << p << " " << i - j << endl;
        if (i - j > terms) {
          terms = i - j;
          max = p;
          //cout << max << " " << terms << " " << i << " " << j << endl;
        }
      }
    }
  }
  cout << max << endl;
}

