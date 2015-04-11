#ifndef FACTORING_HH
#define FACTORING_HH

#include "attributes.h"
#include <set>
#include <vector>

std::vector<int> prime_factors(long long n)
  ATTRIBUTE_PURE
  ;

std::set<int> factors(long long n)
  ATTRIBUTE_PURE
  ;

std::vector<int> low_factors(long long n)
  ATTRIBUTE_PURE
  ;

int factor_sum(long long n)
  ATTRIBUTE_FLATTEN
  ;

#endif
