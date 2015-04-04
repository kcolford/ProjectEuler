// probelem 22

#include "util.hh"

vector<string> names = {
#include <22.in>
};

int main()
{
  sort(names.begin(), names.end());
  long long val = 0;
  for (int i = 0; i < names.size(); i++) {
    int sc = 0;
    for (int j = 0; j < names[i].size(); j++)
      sc += names[i][j] - ('A' - 1);
    val += sc * (i + 1);
  }
  cout << val << endl;
}
