// problem 4

#include "util.hh"
#include "palindrome.hh"

int main()
{
  int m = 0;
  for (int i = 999; i >= 100; i--)
    for (int j = 999; j >= 100; j--)
      if (is_palindrome(i * j))
        m = max(m, i * j);
  cout << m << endl;
}
