// Generate prime numbers.

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <string>
#include "vector.hh"

using namespace std;

int main(int argc, char *argv[]) {
  int upperbound = 10000000;
  int reserve = 1000000;
  string filename = "primes.c";

  switch (argc - 1) {
  default:
    throw invalid_argument("Incorrect number of arguments.");
  case 3:
    reserve = atoi(argv[3]);
  case 2:
    upperbound = atoi(argv[2]);
  case 1:
    filename = argv[1];
  case 0:
    ;
  }

  int s[2] = {2, 3};
  vector<int> p(s, s + 2);
  p.reserve(reserve);

  for (int i = 5; i < upperbound; i += 2) {
    for (int j = 1; j < p.size(); j++) {
      if (i / p[j] < p[j]) {
        p.push_back(i);
        break;
      }
      if (i % p[j] == 0)
        break;
    }
  }

  fstream source(filename.c_str(), ios_base::out);
  source
    << "/* Generated array of prime numbers. */" << endl
    << endl
    << "#include \"primes.h\"" << endl
    << endl
    << "const int primes_length = " << p.size() << ";" << endl
    << endl
    << "const int primes_upperbound = " << upperbound << ";" << endl
    << endl
    << "const int primes[] = " << p << ";" << endl
    ;
  
  return 0;
}
