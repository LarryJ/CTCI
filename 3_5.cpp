/*******************************
Implement a MyQueue class which 
implements a queue using two
stacks
*******************************/

#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
private:
  stack<int> s1;    //push into elements
  stack<int> s2;    //pop out elements
public:
  int pop();
  void push(int value);
};

int MyQueue::pop()
{
  if (s1.empty())
  {
    cout << "Stack is empty!" << endl;
    return -1;
  }
  while (!s1.empty())
  {
    s2.push(s1.top());
    s1.pop();
  }
  int v = s2.top();
  s2.pop();
  while (!s2.empty())
  {
    s1.push(s2.top());
    s2.pop();
  }
  return v;
}

void MyQueue::push(int value)
{
  s1.push(value);
}

int main()
{
  MyQueue q;
  cout << q.pop() << endl;
  q.push(1);
  q.push(10);
  cout << q.pop() << endl;
  cout << q.pop() << endl;
  return 0;
}
