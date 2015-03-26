#ifndef DIGIT_ITERATOR_HH
#define DIGIT_ITERATOR_HH

#include <boost/iterator/iterator_adaptor.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <boost/utility.hpp>
#include <stack>

template<int base = 10>
class digit_iterator
  : public boost::iterator_facade<digit_iterator<base>,
                                  const int,
                                  boost::forward_traversal_tag>
{
  friend class boost::iterator_core_access;

  std::stack<int> c;

  void increment()
  { c.pop(); }

  const int& dereference() const
  { return c.top(); }

  bool equal(const digit_iterator<base>& o) const
  { return c == o.c; }

public:

  digit_iterator(unsigned val = 0)
  {
    while (val) {
      c.push(val % base);
      val /= base;
    }
  }
};

typedef digit_iterator<10> decimal_iterator;

template<class ForwardIt>
int from_digits(ForwardIt first, ForwardIt last, int base = 10)
{
  if (first == last)
    return 0;
  else
    return *first * base + from_digits(boost::next(first), last, base);
}

template<class Container>
int from_digits(const Container& c, int base = 10)
{
  return from_digits(c.begin(), c.end(), base);
}

int reverse_digits(int n, int base = 10)
  ;

#endif
