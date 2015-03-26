// problem 13

#include "util.hh"
#include "config.h"
#include <gmpxx.h>

int main()
{
  fstream f(INFILE_DIRECTORY "13.in");
  mpz_class o = 0, t;
  while (f >> t) {
    o += t;
  }
  stringstream ss;
  ss << o;
  string s = ss.str();
  s.resize(10);
  cout << s << endl;
}

