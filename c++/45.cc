// problem 45

#include <algorithm>
#include <boost/array.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>

using std::cout;
using std::endl;
using std::binary_search;

template<typename T, int S>
struct array: std::vector<T> {
  array(): std::vector<T>(S) {}
};

void array_solve() {
  array<unsigned long long, 1000000000> t, p, h;

  cout << sizeof(long long) << endl;
  cout << std::numeric_limits<unsigned long long>::max() << endl;

  //#pragma omp parallel for
  for (int i = 0; i < t.size(); i++) {
    t[i] = i * (i + 1) / 2;
    p[i] = i * (3 * i - 1) / 2;
    h[i] = i * (2 * i - 1);
  }

  //#pragma omp parllel for
  for (int i = 144; i < h.size(); i++) {
    if (binary_search(t.begin(), t.end(), h[i]) &&
        binary_search(p.begin(), p.end(), h[i])) {
      cout << h[i] << endl;
      return;
    }
  }
  
  throw 1;
}

void direct_solve() {
  unsigned long long t, p, h, tn, pn, hn;

  t = p = h = 40755;
  tn = 285;
  pn = 165;
  hn = 143;
  
  for (;;) {
    h += 4 * hn + 1;
    hn += 1;

    while (p < h) {
      p += 3 * pn + 1;
      pn += 1;
    }

    while (t < h) {
      t += tn + 1;
      tn += 1;
    }
    
    if (t == h && p == h) {
      cout << h << endl;
      return;
    }
  }
}

int main() {
  direct_solve();
}

