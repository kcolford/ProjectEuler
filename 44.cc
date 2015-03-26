// Project Euler Problem 44

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  vector<int> pent(5000);
  set<int> pent_cache;
  
  for (int i = 1; i < pent.size(); i++) {
    pent[i] = i * (3 * i - 1) / 2;
    pent_cache.insert(pent[i]);
  }

  for (int i = 1; ; i++) {
    int n = pent[i];
    for (int j = i-1; j > 0; j--) {
      int m = pent[j];
      if (pent_cache.count(n + m) && pent_cache.count(n - m)) {
        cout << n - m << endl;
        return 0;
      }
    }
  }

  return 1;
}

