// problem 56

#include "util.hh"
#include "digit_breakdown.hh"

int main() 
{
  int n = 0;
  for (int a = 2; a < 100; a++) {
    digit_breakdown c = a;
    for (int b = 1; b < 100; b++, c *= a)
      n = max(n, c.sum());
  }
  cout << n << endl;
}

