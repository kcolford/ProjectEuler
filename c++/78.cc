// problem 78

// p(1) := 1
// p(2) := 2
// p(3) := 3
// p(4) := 5
// p(5) := 7
// p(6) := 11

// oooo
// ooo o
// oo oo
// oo o o
// o o o o

// ooooo
// oooo o
// ooo oo
// ooo o o
// oo oo o
// oo o o o
// o o o o o

// oooooo
// ooooo o
// oooo oo
// oooo o o
// ooo ooo
// ooo oo o
// ooo o o o
// oo oo oo
// oo oo o o
// oo o o o o
// o o o o o o

#include "util.hh"

struct Pentagonals
  : public vector<int>
{
  reference operator[](size_type s)
  {
    while (s >= size())
      push_back(size() * (3 * size() - 1) / 2);
    return vector<int>::operator[](s);
  }
} penta;

struct Partitions
  : public vector<int>
{
private:
  int zero;

public:
  Partitions()
    : zero(0)
  { 
    reserve(1000000); 
    push_back(1);
  }

  typedef int size_type;

  reference operator[](size_type s)
  { return s < 0 ? zero : vector<int>::operator[](s); }
} p;

int main()
{
  for (int i = p.size(); p[i - 1]; i++) {
    p.push_back(0);
    for (int k = 1; penta[k] <= i; k++) {
      int c = p[i - penta[k]] + p[i - penta[k] - k];
      if (k % 2 == 0)
        p[i] -= c;
      else
        p[i] += c;
      p[i] %= 1000000;
    }
  }
  cout << p.size() - 1 << endl;
}
