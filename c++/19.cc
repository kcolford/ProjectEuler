// problem 19

#include "util.hh"
#include "datetime.hh"

int main()
{
  int val = 0, day = (1 + 365) % 7;
  for (int i = 1901; i <= 2000; i++) {
    for (int j = 1; j <= 12; j++) {
      val += day == 0;
      day = (day + days_in_month(i, j)) % 7;
    }
  }
  cout << val << endl;
}
