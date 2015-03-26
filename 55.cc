// problem 55

#include "util.hh"
#include "digit_breakdown.hh"

bool is_lychrel(int n)
{
  digit_breakdown accum = n, rev = accum.make_reversed();
  for (int i = 0; i < 50; i++) {
    accum = accum + rev;
    rev = accum.make_reversed();
    if (accum == rev)
      return false;
  }
  return true;
}

int main()
{
  int count = 0;
  for (int i = 1; i < 10000; i++)
    if (is_lychrel(i))
      count += 1;
  cout << count << endl;
}
