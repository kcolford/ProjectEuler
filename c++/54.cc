// problem 54

#include "util.hh"
#include "attributes.h"
#include <boost/operators.hpp>
#include <config.h>
#include <cstring>

struct card
{
  char value;
  char suit;
};

static const char card_values[] = "23456789TJQKA";

struct mapping
  : public vector<int> 
{
  mapping()
    : vector<int>(256)
  {
    for (int i = 0, j = 1; card_values[i]; i++, j++)
      at(static_cast<size_type>(card_values[i])) = j;
  }

  value_type& operator[](size_type s)
  { return at(s); }

  value_type max() const
  { return at('A') + 1; }

} card_map;

istream& operator>>(istream& in, card& c)
{
  in >> ws;
  c.value = in.get();
  c.suit = in.get();
  if (in)
    c.value = card_map[(int) c.value];
  return in;
}

struct group
  : public card
  , public boost::equivalent1<group>
  , public boost::totally_ordered1<group>
{

  int count;
  
  group(vector<card>& v)
  {
    assert(!v.empty());
    vector<card>::iterator i = v.end();
    i--;
    value = i->value;
    suit = i->suit;
    count = 1;
    v.pop_back();
    while (i-- != v.begin()) {
      if (i->value == value) {
        swap(*i, v.back());
        v.pop_back();
        count++;
      }
    }
    assert(v.size() < s);
  }

  bool operator<(const group& o) const
  {
    return (count < o.count ||
            (count == o.count && value < o.value));
  }

};

struct groups
  : public vector<group>
  , public boost::less_than_comparable1<groups>
{
  groups(vector<card>& v)
  {
    while (!v.empty()) {
      group t(v);
      push_back(t);
      assert(size() <= 5);
    }
    sort(begin(), end());
  }

  groups()
  {}

  bool is_strait() const
  {
    if (size() != 5)
      return false;
    
    for (int i = 0; i < 4; i++)
      if (at(i).value + 1 != at(i + 1).value)
        return false;
    
    return true;
  }

  bool is_flush() const
  {
    if (size() != 5)
      return false;
    
    for (int i = 0; i < 4; i++)
      if (at(i).suit != back().suit)
        return false;
    
    return true;
  }

  unsigned long long to_int() const
  {
    unsigned long long out = 0;

    out *= 2;
    if (is_strait() && is_flush())
      out += 1;

    out *= card_map.max();
    if (back().count == 4)
      out += back().value;

    out *= 2;
    if (back().count == 3 && size() == 2)
      out += 1;

    out *= 2;
    if (is_flush())
      out += 1;

    out *= 2;
    if (is_strait())
      out += 1;

    out *= 2;
    if (back().count == 3)
      out += 1;

    out *= 3;
    if (back().count == 2) {
      out += 1;
      if (at(size() - 2).count == 2)
        out += 1;
    }
    
    for (int i = size() - 1; i >= 0; i--) {
      for (int j = 0; j < at(i).count; j++) {
        out *= card_map.max();
        out += at(i).value;
      }
    }

    return out;
  }
};

bool operator<(const groups& l, const groups& r)
{
  return l.to_int() < r.to_int();
}

istream& operator>>(istream& in, groups& g)
{
  vector<card> v(5);
  in >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];
  g = v;
  return in;
}

int main()
{
  fstream f(INFILE_DIRECTORY "54.in");
  
  int wins = 0;
  groups g1, g2;
  while (f >> g1 >> g2)
    if (g1 > g2)
      wins++;

  cout << wins << endl;  
}
