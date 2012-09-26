/*******************************
Implement an algorithm to print
all valid (i.e., properly opened
and closed) combinations of 
n-pairs of parentheses.
EXAMPLE
Input: 3
Output: ((())), (()()), (())(),
        ()(()), ()()()
*******************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 5;

//left, number of remaining left parentheses
//right, number of remaining right parentheses
void parentheses_combination_recursion(int left, int right, string s,
				       vector<string> &result)
{
  if (left == 0 && right == 0)
  {
    result.push_back(s);
    return;
  }
  if (left > 0)
    parentheses_combination_recursion(left - 1, right, s + '(', result);
  if (right > left)
    parentheses_combination_recursion(left, right - 1, s + ')', result);
}

vector<string> parentheses_combination(int n)
{
  vector<string> result;
  string s;
  parentheses_combination_recursion(n, n, s, result);
  return result;
}

int main()
{
  vector<string> result = parentheses_combination(N);
  for (size_t i = 0; i < result.size(); ++i)
    cout << result[i] << endl;
  cout << "TOTAL: " << result.size() << endl;
  return 0;
}
