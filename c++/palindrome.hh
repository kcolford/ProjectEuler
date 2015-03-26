#ifndef PALINDROME_HH
#define PALINDROME_HH

#include <iterator>
#include "iterator_compare.hh"

template<class BidirIt>
bool is_palindrome(BidirIt first, BidirIt last)
{
  return iterator_equal(first, last, std::reverse_iterator<BidirIt>(first),
                        std::reverse_iterator<BidirIt>(last));
}

template<class Container>
bool is_palindrome(const Container& c)
{
  return is_palindrome(c.begin(), c.end());
}

bool is_palindrome(int n, int base = 10)
  ;

#endif
