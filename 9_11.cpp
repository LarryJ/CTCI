/*******************************
Given a boolean expression
consisting of the symbols 0, 1,
&, |, and ^, and a desired
boolean result value result,
implement a function to count
the number of ways of parenthesizing
the expression such that it
evaluates to result.
EXAMPLE: 1 ^ 0 | 0 | 1
Desired result: false(0)
Output: 2 ways.
1 ^ ((0 | 0) | 1) and
1 ^ (0 | (0 | 1)).
*******************************/

#include <iostream>
#include <string>
#include <map>

using namespace std;

int parenthesizing_expression_recursion(string s, bool result, map<string, int> &m)
{
  if (s.size() == 1)
  {
    if (s[0] == '1' && result)
      return 1;
    else if (s[0] == '0' && !result)
      return 1;
    else
      return 0;
  }
  string key = s + (result? '1' : '0');    //append the result to form a key
  map<string, int>::iterator it = m.find(key);
  if (it != m.end())
    return it -> second;
  int n = 0;         //number of ways
  if (result)
  {
    for (size_t i = 1; i < s.size(); i += 2)  //i, location of operators
    {
      switch (s[i])
      {
      case '&':
	n += parenthesizing_expression_recursion(s.substr(0, i), true, m) * 
	  parenthesizing_expression_recursion(s.substr(i + 1), true, m);
	break;
      case '|':
	n += parenthesizing_expression_recursion(s.substr(0, i), true, m) *
	  parenthesizing_expression_recursion(s.substr(i + 1), true, m) +
	  parenthesizing_expression_recursion(s.substr(0, i), false, m) *
	  parenthesizing_expression_recursion(s.substr(i + 1), true, m) +
	  parenthesizing_expression_recursion(s.substr(0, i), true, m) *
	  parenthesizing_expression_recursion(s.substr(i + 1), false, m);
	break;
      case '^':
	n += parenthesizing_expression_recursion(s.substr(0, i), true, m) *
	  parenthesizing_expression_recursion(s.substr(i + 1), false, m) + 
	  parenthesizing_expression_recursion(s.substr(0, i), false, m) *
	  parenthesizing_expression_recursion(s.substr(i + 1), true, m);
	break;
      default:
	break;
      }
    }
  }
  else
  {
    for (size_t i = 1; i < s.size(); i += 2)  //i, location of operators
    {
      switch (s[i])
      {
      case '&':
	n += parenthesizing_expression_recursion(s.substr(0, i), false, m) * 
	  parenthesizing_expression_recursion(s.substr(i + 1), false, m) +
	  parenthesizing_expression_recursion(s.substr(0, i), false, m) * 
	  parenthesizing_expression_recursion(s.substr(i + 1), true, m)+
	  parenthesizing_expression_recursion(s.substr(0, i), true, m) * 
	  parenthesizing_expression_recursion(s.substr(i + 1), false, m);
	break;
      case '|':
	n += parenthesizing_expression_recursion(s.substr(0, i), false, m) *
	  parenthesizing_expression_recursion(s.substr(i + 1), false, m);
	break;
      case '^':
	n += parenthesizing_expression_recursion(s.substr(0, i), true, m) *
	  parenthesizing_expression_recursion(s.substr(i + 1), true, m) + 
	  parenthesizing_expression_recursion(s.substr(0, i), false, m) *
	  parenthesizing_expression_recursion(s.substr(i + 1), false, m);
	break;
      default:
	break;
      }
    }
  }
  m.insert(pair<string, int> (key, n));
  return n;
}

int parenthesizing_expression(string s, bool result)
{
  map<string, int> m;
  return parenthesizing_expression_recursion(s, result, m);
}

int main()
{
  string s = "1^0|0&1^0|1";
  bool result = true;
  cout << parenthesizing_expression(s, result) << endl;
  return 0;
}
