#ifndef PRODUCT_HH
#define PRODUCT_HH

#include <boost/utility.hpp>

template<class ForwardIt>
typename ForwardIt::value_type product(ForwardIt first, ForwardIt last)
{
  if (first == last)
    return 1;
  else
    return *first * product(boost::next(first), last);
}

#endif
