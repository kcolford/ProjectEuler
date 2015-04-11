// problem 88

#include "util.hh"
#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH
#include <set>
#include "sum.hh"

int main()
{
  vector<vector<int> > ps(1, vector<int>(1, 1));
  vector<int> mps(2, 0);
  set<int> mps_set;
  for (int i = mps.size(); i <= 12000; i++) {
    while (mps.size() <= i || mps[i] == 0) {
      int v = ps.size();
      ps.push_back(vector<int>(1, 1));
      for (int j = 2; j <= v / j; j++) {
        if (v % j == 0 && j + v / j <= v) {
          foreach (int k, ps[j]) {
            foreach (int l, ps[v / j]) {
              int m = k + l + v - (j + v / j);
              ps[v].push_back(m);
              if (mps.size() <= m) {
                mps.resize(m + 1);
                mps[m] = v;
              } else if (mps[m] == 0) {
                mps[m] = v;
              }
            }
          }
        }
      }
    }
    mps_set.insert(mps[i]);
  }
#ifndef NDEBUG
  cout << mps << endl;
#endif
  cout << sum(mps_set) << endl;
}

    
    
