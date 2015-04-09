// problem 63

#include "util.hh"
#include "digit_breakdown.hh"
#include <gmpxx.h>

int main()
{
  int val = 1;
  for (int i = 2; i < 10; i++) {
    digit_breakdown t = i;
    for (int j = 1; j < 100; j++, t *= i) {
      if (t.size() == j) {
        val++;
        //clog << t << endl;
      }
    }
  }
  cout << val << endl;
}
