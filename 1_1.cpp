/*******************************
Implement an algorithm to
determine if a string has all
unique characters. What if you
cannot use additional data
structures
*******************************/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check_unique_char(string str)
{
  //not using additional data structures
  sort(str.begin(), str.end());
  for (size_t i = 1; i < str.length(); ++i)
  {
    if (str[i] == str[i - 1])
      return false;
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
