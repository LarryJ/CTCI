/*******************************
Given a real number between 0
and 1 (e.g., 0.72) that is passed
in as a double, print the binary
representation. If the number
cannot be represented accurately
in binary with at most 32 
characters, print "ERROR"
*******************************/

#include <iostream>
#include <string>

using namespace std;

const double N = 0.8125;

string double_in_binary(double n)
{
  if (n >= 1.00 || n <= 0.00)
    return NULL;
  string result = "0.";
  while (n > 0.00)
  {
    n *= 2;
    if (n >= 1)
    {
      result += '1';
      n -= 1;
    }
    else
      result += '0';
    if (result.size() > 32)
    {
      result = "ERROR";
      break;
    }
  }
  return result;
}

int main()
{
  string result = double_in_binary(N);
  if (!result.empty())
    cout << result  << endl;
  return 0;
}
