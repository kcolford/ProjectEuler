#ifndef SUM_HH
#define SUM_HH

#include <boost/utility.hpp>

template<class ForwardIt>
typename ForwardIt::value_type sum(ForwardIt first, ForwardIt last)
{
  if (first == last)
    return static_cast<typename ForwardIt::value_type>(0);
  else
    return *first + sum(boost::next(first), last);
}

template<class Container>
typename Container::value_type sum(const Container& c)
{
  return sum(c.begin(), c.end());
}

#endif
