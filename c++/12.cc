// problem 12

#include "util.hh"

int main()
{
  for (int i = 1, n = 1; ; i += 1, n += i) {
    int o = 0, j;
    for (j = 2; n / j > j; j++)
      if (n % j == 0)
        o += 2;
    if (n / j == j)
      o += 1;
    if (o > 500) {
      cout << n << endl;
      break;
    }
  }
}
