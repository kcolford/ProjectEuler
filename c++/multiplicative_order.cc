// implementation of the multipicative order function.

#include "multiplicative_order.hh"

int multiplicative_order(int n, int m)
{
  int out = 1, i = n;
  while (i != 1) {
    i = (i * n) % m;
    out++;
  }
  return out;
}
