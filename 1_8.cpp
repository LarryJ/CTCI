/*******************************
Assume you have a method
isSubstring which checks if one
word is a substring of another.
Given two string, s1 and s2,
write code to check if s2 is a 
rotation of s1 using only one
call to isSubstring (e.g., 
"waterbottle" is a rotation of
"erbottlewat").
*******************************/

#include <iostream>
#include <string>

using namespace std;

//check whether s2 is a substring of s1
bool isSubstring(string s1, string s2)
{
  size_t l1 = s1.length();
  size_t l2 = s2.length();
  if (l2 > l1)
    return false;
  for (int i = 0; i < l1; ++i)
  {
    int k = i;
    for (int j = 0; j < l2; ++j)
    {
      if (k == l1)
	return false;
      if (s1[k] == s2[j])
      {
	if (j == l2 - 1)
	  return true;
	++k;
      }
      else
	break;
    }
  }
  return false;
}

//check whether s1 is a rotation of s2
bool is_rotation(string s1, string s2)
{
  if (s1.empty() || s2.empty())
    return false;
  if (s1.length() != s2.length())
    return false;
  return isSubstring(s2 + s2, s1);
}

int main()
{
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  cout << is_rotation(s1, s2) << endl;
  return 0;
}
