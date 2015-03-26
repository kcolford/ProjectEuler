// problem 1

#include "util.hh"

int main()
{
  int o = 0;
  for (int i = 0; i < 1000; ++i)
    if (!(i % 3 && i % 5))
      o += i;
  cout << o << endl;
}
