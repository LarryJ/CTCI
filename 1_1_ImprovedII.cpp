/*******************************
Implement an algorithm to
determine if a string has all
unique characters. What if you
cannot use additional data
structures
*******************************/

#include <iostream>
#include <string>
#include <map>

using namespace std;

bool check_unique_char(string str)
{
  //use additional data structures
  map<char, int> m;
  map<char, int>::iterator it;
  for (size_t i = 0; i < str.length(); ++i)
  {
    if ((it = m.find(str[i])) != m.end())
      return false;
    else
      m[str[i]] = 1;
  }
  return true;
}

int main()
{
  string str;
  getline(cin, str );
  cout << check_unique_char(str) << endl;
  return 0;
}
