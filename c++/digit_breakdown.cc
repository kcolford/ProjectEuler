// Implementation of the digit breakdown

#include "digit_breakdown.hh"
#include <algorithm>

digit_breakdown& digit_breakdown::normalize()
// Note that this can only handle positive digits in the
// representation.
{
  int acc = 0;
  for (reverse_iterator i = rbegin(); i != rend(); i++) {
    *i += acc;
    acc = *i / base;
    *i %= base;
  }
  while (acc > 0) {
    push_front(acc % base);
    acc /= base;
  }
  while (front() == 0)
    pop_front();
  return *this;
}

digit_breakdown& digit_breakdown::operator+=(const digit_breakdown& o)
{
  reverse_iterator i = rbegin();
  for (const_reverse_iterator j = o.rbegin(); j != o.rend(); i++, j++) {
    if (i == rend()) {
      while (j != o.rend()) {
        push_front(*j);
        j++;
      }
      break;
    } else {
      *i += *j;
    }
  }
  
  return normalize();
}

bool digit_breakdown::operator<(const digit_breakdown& o) const
{
  if (size() != o.size())
    return size() < o.size();
  for (const_iterator i = begin(), j = o.begin(); i != end(); i++, j++)
    if (*i != *j)
      return *i < *j;
  return false;
}

digit_breakdown digit_breakdown::make_reversed() const
{
  digit_breakdown r = *this;
  std::reverse(r.begin(), r.end());
  return r;
}

bool digit_breakdown::is_palindrome() const
{
  return *this == make_reversed();
}

digit_breakdown& digit_breakdown::operator*=(unsigned i)
{
  digit_breakdown t = *this;
  clear();
  while (i) {
    if (i & 1)
      *this += t;
    t = t + t;
    i >>= 1;
  }
  return normalize();
}

int digit_breakdown::sum() const
{
  int out = 0;
  for (const_iterator i = begin(); i != end(); i++)
    out += *i;
  return out;
}

std::ostream& operator<<(std::ostream& out, const digit_breakdown& d)
{
  for (digit_breakdown::const_iterator i = d.begin(); i != d.end(); i++)
    out << *i;
  return out;
}
