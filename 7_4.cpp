/*******************************
Write methods to implement the
multiply, subtract, and divide
operations for integers. Use
only the add operator
*******************************/

#include <iostream>

using namespace std;


//a - b
int my_subtract(int a, int b)
{
  if (b == 0)
    return a;
  int n = 1;
  if (b > 0)
    n = -1;
  while (b != 0)
  {
    a += n;
    b += n;
  }
  return a;
}

//get -a
int my_negation(int a)
{
  int n = (a > 0)? -1 : 1;
  int num = 0;
  while (a != 0)
  {
    num += n;
    a += n;
  }
  return num;
}

int my_multiply(int a, int b)
{
  if (a == 0 || b == 0)
    return 0;
  if (a > 0 && b < 0)
    return my_negation(my_multiply(a, my_negation(b)));
  else if (a < 0 && b > 0)
    return my_negation(my_multiply(my_negation(a), b));
  else
  {
    if (a < 0 && b < 0)
    {
      a = my_negation(a);
      b = my_negation(b);
    }
    int num = 0;
    for (int i = 0; i < b; ++i)
      num += a;
    return num;
  }
}

//a / b
int my_divide(int a, int b)
{
  if (b == 0)
  {
    cout << "divisor cannot be 0!" << endl;
    return -1;
  }
  if (a == 0)
    return 0;
  if (a > 0 && b < 0)
    return my_negation(my_divide(a, my_negation(b)));
  else if (a < 0 && b > 0)
    return my_negation(my_divide(my_negation(a), b));
  else
  {
    if (a < 0 && b < 0)
    {
      a = my_negation(a);
      b = my_negation(b);
    }
    int num = 0;
    while (a >= b)
    {
      a -= b;
      ++num;
    }
    return num;
  } 
}

int main()
{
  cout << my_subtract(5, 15) << endl;
  cout << my_subtract(-4, -8) << endl;
  cout << my_multiply(0, 11) << endl;
  cout << my_multiply(4, -30) << endl;
  cout << my_divide(0, 0) << endl;
  cout << my_divide(0, 11) << endl;
  cout << my_divide(20, -4) << endl;
  return 0;
}
