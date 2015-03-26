#ifndef SUM_HH
#define SUM_HH

#include <boost/utility.hpp>

template<ForwardIt>
ForwardIt::value_type sum(ForwardIt first, ForwardIt last)
{
  if (first == last)
    return static_cast<ForwardIt::value_type>(0);
  else
    return *first + sum(boost::next(first), last);
}

#endif
