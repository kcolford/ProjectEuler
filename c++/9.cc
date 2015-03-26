// problem 9

#include "util.hh"

int main()
{
  for (int i = 1; ; i++)
    for (int j = 1; j < i; j++) {
      int a = i * i - j * j, b = 2 * i * j, c = i * i + j * j;
      if (a + b + c == 1000) {
        cout << a * b * c << endl;
        return 0;
      }
    }
}
