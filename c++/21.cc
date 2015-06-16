// problem 21

#include "util.hh"
#include "factoring.hh"

bool is_amicable(int a)
{
  int b = factor_sum(a);
  return a != b && a == factor_sum(b);
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
