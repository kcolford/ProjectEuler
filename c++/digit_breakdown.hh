#ifndef DIGIT_BREAKDOWN_HH
#define DIGIT_BREAKDOWN_HH

#include <boost/operators.hpp>
#include <ostream>
#include "vector.hh"

class digit_breakdown
  : public boost::addable1<digit_breakdown>
  , public boost::multipliable2<digit_breakdown, unsigned>
  , public boost::equivalent1<digit_breakdown>
  , public boost::totally_ordered1<digit_breakdown>
{
  typedef std::vector<int> container;
  typedef container::size_type size_type;

  container c;

  int base;

  void push_front(int i)
  { c.push_back(i); }

  void pop_front()
  { c.pop_back(); }

  int& front()
  { return c.back(); }

  void clear()
  { c.clear(); }

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

  int get_base() const
  { return base; }

  digit_breakdown& normalize();
  
  digit_breakdown(unsigned int i = 0, int base_ = 10)
    : base(base_)
  { push_front(i); normalize(); }

  digit_breakdown& operator+=(const digit_breakdown& o);

  bool operator<(const digit_breakdown& o) const;

  digit_breakdown make_reversed() const;

  bool is_palindrome() const;

  digit_breakdown& operator*=(unsigned i);

  int sum() const;
};

std::ostream& operator<<(std::ostream& out, const digit_breakdown& d);

#endif
