/*******************************
A child is running up a staircase
with n steps, and can hop either
1 step, 2 steps, or 3 steps at
a time. Implement a method to
count how many possible ways the
child can run up the stairs
*******************************/

#include <iostream>

using namespace std;

const int N = 50;

int count_ways(int n)
{
  if (n == 0)
    return 0;
  int a = 1;   //n == 1
  int b = 2;   //n == 2
  int c = 4;   //n == 3
  int d;
  int i = 4;
  while (i <= n)
  {
    d = a + b + c;
    a = b;
    b = c;
    c = d;
    ++i;
  }
  return d;
}

int main()
{
  cout << count_ways(N) << endl;
  return 0;
}
