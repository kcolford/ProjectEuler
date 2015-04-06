// problem 24

#include "util.hh"
#include "digit_breakdown.hh"

int main() 
{
  string b = "0123456789";
  for (int i = 0; i < 1000000; i++)
    next_permutation(b.begin(), b.end());
  cout << b << endl;
}

