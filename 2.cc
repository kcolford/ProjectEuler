// problem 2

#include "util.hh"

int main()
{
  int o = 0;
  for (int a = 1, b = 2; a < 4000000; a += b, swap(a, b))
    if (a % 2 == 0)
      o += a;
  cout << o << endl;
}

  
