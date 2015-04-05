// problem 23

#include "util.hh"
#include "factoring.hh"

#define MAX_NON_ABUNDANT_SUM 28123

int main()
{
  vector<int> abundant;
  vector<bool> abundant_sums(MAX_NON_ABUNDANT_SUM + 2, false);
  for (int i = 9; i <= MAX_NON_ABUNDANT_SUM; i++)
    if (i < factor_sum(i))
      abundant.push_back(i);
  for (int i = 0; i < abundant.size(); i++)
    for (int j = 0; j <= i; j++)
      if (abundant[i] + abundant[j] < abundant_sums.size())
        abundant_sums[abundant[i] + abundant[j]] = true;
  long long out = 0;
  for (int i = 0; i < abundant_sums.size(); i++)
    if (!abundant_sums[i])
      out += i;
  cout << out << endl;
}

