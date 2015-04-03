# Define the util library.
add_library(util SHARED
  attributes.h
  cast.hh
  datetime.cc
  datetime.hh
  digit_breakdown.cc
  digit_breakdown.hh
  digit_iterator.hh
  error_check.hh
  factoring.cc
  has_member.hh
  iterator_compare.hh
  len.h
  limiter.cc
  limiter.hh
  palindrome.hh
  primes.c
  primes.h
  primes.hh
  product.hh
  radixsort.cc
  radixsort.hh
  sum.hh
  util.cc
  util.hh
  vector.hh
  )
