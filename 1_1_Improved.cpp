/*******************************
Implement an algorithm to
determine if a string has all
unique characters. What if you
cannot use additional data
structures
*******************************/

#include <iostream>
#include <string>

using namespace std;

bool check_unique_char(string str)
{
  //use additional data structures
  //assume str only contains ascii, thus, 256 different characters (including extension)
  int check_arr[256] = {0};
  //cout << "****" << check_arr[255] << endl;
  for (size_t i = 0; i < str.length(); ++i)
  {
    if (check_arr[str[i]] == 1)
      return false;
    else
      check_arr[str[i]] = 1;
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
