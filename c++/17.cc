// problem 17

#include "util.hh"
#include <config.h>
#include <json/json.h>
#include "len.h"

int operator+(int a, const Json::Value& j)
{
  //if (!j.asString().size()) clog << j << endl;
  return a + j.asString().size();
}

int operator+(const Json::Value& j, int a)
{
  return a + j;
}

int main()
{
  fstream f(INFILE_DIRECTORY "number-words.json");
  Json::Value root;
  f >> root;
  //clog << root << endl;
  int val = 0;
  string th = "thousand";
  string h = "hundred";
  string a = "and";
  for (int i = 0; i < 10; i++) {
    int hun = 0 + root["units"]["ones"][i];
    //clog << hun << endl;
    hun += hun ? h.size() : 0;
    val += hun;
    hun += hun ? a.size() : 0;

    for (int j = 1; j < 10; j++)
      val += hun + root["units"]["ones"][j];
    for (int j = 0; j < 10; j++)
      val += hun + root["units"]["teens"][j];

    for (int j = 2; j < 10; j++) {
      int t = 0 + root["tens"][j];
      for (int k = 0; k < 10; k++)
        val += hun + t + root["units"]["ones"][k];
    }
  }
  val += root["units"]["ones"][1] + th.size();
  
  cout << val << endl;
}
