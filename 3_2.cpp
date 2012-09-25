/*******************************
How would you design a stack
which, in addition to push and 
pop, also has a function min
which returns the minimum
element? Push, pop and min should
all operate in O(1) time.
*******************************/

#include <iostream>

using namespace std;

const int MAX = 100;
int arr[MAX];
int m[MAX];
int size = 0;

void push(int value)
{
  if (size == MAX)
  {
    cout << "The stack is full!" << endl;
    return;
  }
  arr[size] = value;
  if (size == 0)
    m[size] = value;
  else
  {
    if (m[size - 1] > value)
      m[size] = value;
    else 
      m[size] = m[size - 1];
  }
  ++size;
}

int pop()
{
  if (size == 0)
  {
    cout << "The stack is empty!" << endl;
    return -1;
  }
  --size;
  return arr[size];
}

int stack_min()
{
  if (size == 0)
  {
    cout << "The stack is empty!" << endl;
    return -1;
  }
  return m[size - 1];
}

int main()
{
  push(10);
  for (int i = 0; i < 2; ++i)
    cout << pop() << endl;
  push(2);
  cout << stack_min() << endl;
  push(3);
  cout << stack_min() << endl;
  push(1);
  cout << stack_min() << endl;
  push(8);
  cout << stack_min() << endl;
  push(0);
  cout << stack_min() << endl;
  return 0;
}
