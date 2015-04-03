// problem 67

#include "util.hh"

int main()
{
  fstream f(INFILE_DIRECTORY "67.in");
  vector<vector<int> > t;
  string line;
  while (getline(f, line)) {
    stringstream ss(line);
    t.push_back(vector<int>(istream_iterator<int>(ss),
                            (istream_iterator<int>())));
    assert(t.size() == t.back().size());
  }

  vector<int> acc = t.back();
  for (int i = t.size() - 2; i >= 0; i--) {
    assert(acc.size() == i + 1);
    vector<int> tmp;
    tmp.reserve(i);
    for (int j = 0; j < acc.size() - 1; j++)
      tmp.push_back(max(acc[j], acc[j + 1]));
    acc = tmp;
    assert(acc.size() == i);
    for (int j = 0; j < acc.size(); j++)
      acc[j] += t[i][j];
  }

  assert(acc.size() == 1);
  cout << acc[0] <<  endl;
}
