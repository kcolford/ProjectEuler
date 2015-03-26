// problem 8

#include "util.hh"
#include "config.h"
#include "product.hh"

int main()
{
#define int long long
  fstream f(INFILE_DIRECTORY "8.in");
  vector<int> n(istream_iterator<char>(f),
                (istream_iterator<char>()));
  for (int i = 0; i < n.size(); i++)
    n[i] -= '0';
  cout << n << endl;
  int val = 0;
  for (int i = 0; i < n.size() - 13; i++)
    val = max(val, product(n.begin() + i, n.begin() + i + 13));
  cout << val << endl;
}
                
