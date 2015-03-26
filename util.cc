// utility module

#include "digit_breakdown.hh"
#include "digit_iterator.hh"
#include "palindrome.hh"

int reverse_digits(int n, int base)
{
  digit_breakdown b = digit_breakdown(n, base);
  return from_digits(b.rbegin(), b.rend(), base);
}

bool is_palindrome(int n, int base)
{
  return digit_breakdown(n, base).is_palindrome();
}
