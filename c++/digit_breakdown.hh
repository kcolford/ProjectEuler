#ifndef DIGIT_BREAKDOWN_HH
#define DIGIT_BREAKDOWN_HH

#include "attributes.h"
#include <boost/operators.hpp>
#include "cast.hh"
#include <ostream>
#include <vector>

class digit_breakdown
  : public boost::addable1<digit_breakdown>
  , public boost::multipliable2<digit_breakdown, unsigned>
  , public boost::equivalent1<digit_breakdown>
  , public boost::totally_ordered1<digit_breakdown>
{
public:

  typedef unsigned short int digit_type;
  typedef signed int base_type;

private:

  typedef std::vector<digit_type> container;

public:

  typedef container::size_type size_type;

private:

  container c;

  digit_type base;

  void push_front(digit_type i)
  { c.push_back(i); }

  void pop_front()
  { c.pop_back(); }

  digit_type& front()
  { return c.back(); }

  void clear()
  { c.clear(); }

public:

  size_type size() const
  { return c.size(); }

public:

  typedef container::iterator reverse_iterator;
  typedef container::const_iterator const_reverse_iterator;
  typedef container::reverse_iterator iterator;
  typedef container::const_reverse_iterator const_iterator;

  iterator begin()
  { return c.rbegin(); }

  const_iterator begin() const
  { return c.rbegin(); }

  iterator end()
  { return c.rend(); }
  
  const_iterator end() const
  { return c.rend(); }

  reverse_iterator rbegin()
  { return c.begin(); }

  const_reverse_iterator rbegin() const
  { return c.begin(); }

  reverse_iterator rend()
  { return c.end(); }
  
  const_reverse_iterator rend() const
  { return c.end(); }

  digit_type get_base() const
  { return base; }

  digit_breakdown& normalize();

  template<typename T>
  digit_breakdown(T i = 0, digit_type base_ = 10)
    : base(base_)
  {
    while (i > 0) {
      push_front(cast<digit_type>(T(i % base)));
      i /= base;
    }
  }

  digit_breakdown& operator+=(const digit_breakdown& o);

  bool operator<(const digit_breakdown& o) const
    ATTRIBUTE_PURE
    ;

  digit_breakdown make_reversed() const;

  bool is_palindrome() const;

  digit_breakdown& operator*=(base_type i);

  base_type sum() const
    ATTRIBUTE_PURE
    ;

};

std::ostream& operator<<(std::ostream& out, const digit_breakdown& d);

#endif
