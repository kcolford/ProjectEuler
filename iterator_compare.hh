#ifndef ITERATOR_COMPARE_HH
#define ITERATOR_COMPARE_HH

#include <boost/utility.hpp>

template<class ForwardIt1, class ForwardIt2>
bool iterator_equal(ForwardIt1 first1, ForwardIt1 last1,
                    ForwardIt2 first2, ForwardIt2 last2)
{
  if (first1 == last1 || first2 == last2)
    return first1 == last1 && first2 == last2;
  if (*first1 == *first2)
    return iterator_equal(boost::next(first1), last1,
                          boost::next(first2), last2);
  return false;
}

#endif
