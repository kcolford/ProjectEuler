// problem 14

#include "util.hh"
#include <map>

#define int long long

map<int, int> collatz;

int collatz_count(int n)
{
  if (!collatz.count(n))
    collatz[n] = 1 + (n & 1 ? collatz_count(3 * n + 1) 
                      : collatz_count(n / 2));
  return collatz[n];
}

#undef int

int main()
{
  int m = 1;
  collatz[1] = 0;
  for (int i = 2; i < 1000000; i++)
    if (collatz_count(m) < collatz_count(i))
      m = i;
  cout << m << endl;
}
