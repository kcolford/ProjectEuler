// Problem 66

#include "util.hh"
#include "perfect_square.hh"
  

int main()
{
  uint64_t max_x = 0;
  int max_d = 0;
  for (int d = 2; d <= 100; d++) {
    if (int_sqrt(d))
      continue;
    uint64_t x = d + 1;
    int y = 1;
    while (!int_sqrt(x)) {
      x += d * (2 * y + 1);
      y += 1;
    }
    
    x = int_sqrt(x);

    if (max_x <= x) {
      max_x = x;
      max_d = d;
    }
  }
  cout << max_d << endl;
  return 0;
}
