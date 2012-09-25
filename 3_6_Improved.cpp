/*******************************
Write a program to sort a stack
in ascending order (with biggest
items on top). You may use
additional stacks to hold items,
but you may not copy the elements
into any other data structure 
(such as an array). The stack
supports the following operations:
push, pop, peek, and isEmpty
*******************************/

#include <iostream>
#include <stack>

using namespace std;

void sort_stack(stack<int> &s)
{
  if (s.empty())
    return;
  //use only 1 additional stack
  stack<int> s1;
  s1.push(s.top());
  s.pop();
  while (!s.empty())
  {
    if (s1.top() < s.top())
    {
      int temp = s.top();
      s.pop();
      while (!s1.empty() && s1.top() < temp)
      {
	s.push(s1.top());
	s1.pop();
      }
      s1.push(temp);
    }
    while (!s.empty() && s1.top() >= s.top())
    {
      s1.push(s.top());
      s.pop();
    }

  }
  //push all elements back into s in ascending order
  while (!s1.empty())
  {
    s.push(s1.top());
    s1.pop();
  }
}

int main()
{
  stack<int> s;
  s.push(1);
  s.push(3);
  s.push(5);
  s.push(2);
  s.push(2);
  s.push(4);
  sort_stack(s);
  while (!s.empty())
  {
    cout << s.top() << endl;
    s.pop();
  }
  return 0;
}
