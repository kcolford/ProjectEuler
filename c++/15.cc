// problem 15

#include "util.hh"
#include "attributes.h"

long long search(int a, int b)
{
  static long long c[21][21] = {0};

  if (a < 0 || b < 0)
    return 0;
  if (a == 0 && b == 0)
    return 1;
  if (!c[a][b])
    c[a][b] = search(a - 1, b) + search(a, b - 1);
  return c[a][b];
}

int main()
{
  cout << search(20, 20) << endl;
}
