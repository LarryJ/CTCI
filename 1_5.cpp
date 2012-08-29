/*******************************
Implement a method to perform
basic string compressing using
using the counts of repeated
characters. For example, the
string aabcccccaa would become
a2b1c5a3. If the "compressed"
string would not become smaller
than the original string, your
method should return the 
original string
*******************************/

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string compress_string(string str)
{
  if (str.empty())
    return NULL;
  size_t length = str.length();
  string new_str;
  new_str += str[0];
  char last = str[0];
  int count = 1;
  for (int i = 1; i < length; ++i)
  {
    if (str[i] == last)
      ++count;
    else
    {
      char buf[10];
      sprintf(buf, "%d", count);
      new_str += buf;
      new_str += str[i];
      count = 1;
      last = str[i];
    }
  }
  char buf[10];
  sprintf(buf, "%d", count);
  new_str += buf;
  if (new_str.length() >= length)
    return str;
  else
    return new_str;
}

int main()
{
  string str;
  getline(cin, str);
  if (!str.empty())
    cout << compress_string(str) << endl;
  return 0;
}
