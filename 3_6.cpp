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
  stack<int> s1;  //use to sort the stack
  stack<int> s2;  //for temporary use
  while (!s.empty())    //push all elements into s1 in descending order
  {
    if (s1.empty())
    {
      s1.push(s.top());
      s.pop();
    }
    else
    {
      while (!s1.empty() && s.top() > s1.top())
      {
	s2.push(s1.top());
	s1.pop();
      }
      s1.push(s.top());
      s.pop();
      while (!s2.empty())
      {
	s1.push(s2.top());
	s2.pop();
      }
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
  s.push(4);
  sort_stack(s);
  while (!s.empty())
  {
    cout << s.top() << endl;
    s.pop();
  }
  return 0;
}
