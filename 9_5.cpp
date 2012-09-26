/*******************************
Write a method to compute all
permutations of a string
*******************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void string_permutation_recursion(string s, int index, 
				  string str, vector<string> &result)
{
  if (index == s.size())
  {
    result.push_back(str);
    return;
  }
  for (size_t i = 0; i < str.size(); ++i)
  {
    string temp(str);
    temp.insert(i, s, index, 1);
    string_permutation_recursion(s, index + 1, temp, result);
  }
  //append to tail
  str += s[index];
  string_permutation_recursion(s, index + 1, str, result);
}

vector<string> string_permutation(string s)
{
  vector<string> result;
  string str;
  string_permutation_recursion(s, 0, str, result);
  return result;
}

int main()
{
  string s = "derick";
  vector<string> result = string_permutation(s);
  for (size_t i = 0; i < result.size(); ++i)
    cout << result[i] << endl;
  cout << "TOTAL: " << result.size() << endl;
  return 0;
}
