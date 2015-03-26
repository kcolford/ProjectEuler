// problem 6

#include "util.hh"

int main()
{
  int n = 1, d = 0, i = 1;
  while (++i <= 100) {
    d += 2 * n * i;
    n += i;
  }
  cout << d << endl;
}
