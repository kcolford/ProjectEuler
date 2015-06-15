// Implementation of the perfect-square routines

#include "perfect_square.hh"

unsigned int_sqrt(unsigned s)
{
  if (s == 0)
    return 0;

  unsigned long c = s, a = s;
  while ((c >>= 2))
    a >>= 1;
  
  while (a*a > s)
    a = (a + s/a) >> 1;
  
  return a*a == s ? a : 0;
}

bool is_perfect_square(unsigned s)
{
  return s == 0 ? true : int_sqrt(s) ? int_sqrt(s) : false;
}

bool set_int_sqrt(unsigned& s)
{
  if (!is_perfect_square(s))
    return false;
  s = int_sqrt(s);
  return true;
}

int sp_val(int s, int p)
{
  if (s * s < 4 * p) return 0;
  unsigned t = s * s - 4 * p;
  if (!set_int_sqrt(t)) return 0;
  if ((s + t) % 2 != 0) return 0;
  return (s + t) / 2;
}

bool sum_product(int& s, int& p)
{
  if (p == 0) return true;
  if (!sp_val(s, p)) return false;
  p = sp_val(s, p);
  s -= p;
  return true;
}

  
