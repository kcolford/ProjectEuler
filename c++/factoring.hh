#ifndef FACTORING_HH
#define FACTORING_HH

#include "primes.hh"
#include "attributes.h"
#include <set>
#include <vector>

std::vector<int> prime_factors(long long n)
  ATTRIBUTE_PURE
  ;

std::set<long long> factors(long long n)
  ATTRIBUTE_PURE
  ;

std::vector<int> low_factors(long long n)
  ATTRIBUTE_PURE
  ;

int factor_sum(long long n)
  ATTRIBUTE_FLATTEN
  ATTRIBUTE_PURE
  ;

int count_factors(long long n)
  ATTRIBUTE_PURE
  ;

#endif
