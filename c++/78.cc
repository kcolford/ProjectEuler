// problem 78

#include "util.hh"

// p(1) := 1
// p(2) := 2
// p(3) := 3
// p(4) := 5
// p(5) := 7
// p(6) := 11

// oooo
// ooo o
// oo oo
// oo o o
// o o o o

// ooooo
// oooo o
// ooo oo
// ooo o o
// oo oo o
// oo o o o
// o o o o o

// oooooo
// ooooo o
// oooo oo
// oooo o o
// ooo ooo
// ooo oo o
// ooo o o o
// oo oo oo
// oo oo o o
// oo o o o o
// o o o o o o

#include <cmath>

static
int pentagonal(int n)
{
  return n * (3 * n - 1) / 2;
}

int p(int n)
{
  if (n < 0) return 0;
  if (n == 0) return 1;

  static int cache[1000000] = {0};
  if (n < len(cache) && cache[n])
    return cache[n];

  int val = 0;
  for (int k = 1; k <= (1 + sqrt(1 + 24 * n))/6; k++)
    val += ((k - 1) % 2 ? -1 : 1) *
      (p(n - pentagonal(k)) + p(n - pentagonal(-k)));
  
  if (n < len(cache)) cache[n] = val;
  return val;
}

#ifndef TESTING
int main()
{
  int i = 4;
  while (p(i) % 1000000) {
    cout << i << endl;
    i += 5;
  }
  cout << i << endl;
}
#endif
