#ifndef PRIMES_H
#define PRIMES_H

#include "attributes.h"
#include <stdbool.h>

extern const int primes_length;

extern const int primes_upperbound;

extern const int primes[];

#define primes_end (primes + primes_length)

bool is_prime(int n)
  ATTRIBUTE_PURE
  ;

int prime_index_of(int n)
  ATTRIBUTE_PURE
  ;

#endif
