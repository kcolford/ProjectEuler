// problem 21

#include "util.hh"
#include "factoring.hh"
#include "sum.hh"

bool is_amicable(int a)
{
  int b = sum(factors(a));
  return a != b && a == sum(factors(b));
}

int main()
{
  int out = 0;
  for (int i = 1; i < 10000; i++) {
    if (is_amicable(i)) {
      //clog << i << endl;
      out += i;
    }
  }
  cout << out << endl;
}
