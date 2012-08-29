/*******************************
Given two strings, write a
method to decide if one is a
permutation of the other
*******************************/

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool is_permutation(string s1, string s2)
{
  if (s1.length() != s2.length())
    return false;
  map<char, int> m;
  map<char, int>::iterator it;
  //put all characters of s1 into map
  for (size_t i = 0; i < s1.length(); ++i)
  {
    if ((it = m.find(s1[i])) == m.end())
      m.insert(pair<char, int>(s1[i], 1));
    else
      ++it -> second;
  }
  //check whether s2 is a permutation of s1
  for (size_t i = 0; i < s2.length(); ++i)
  {
    if ((it = m.find(s2[i])) == m.end())
      return false;
    --it -> second;
    if (it -> second == 0)
      m.erase(it);
  }
  return true;
}

int main()
{
  string str1, str2;
  getline(cin, str1);
  getline(cin, str2);
  cout << is_permutation(str1, str2) << endl;
  return 0;
}
