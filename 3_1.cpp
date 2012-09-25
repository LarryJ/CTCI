/*******************************
Describe how you could use a 
single array to implement three
stacks
*******************************/

#include <iostream>

using namespace std;

const int MAX = 300;
int size[3] = {0, 0, 0};
int arr[MAX];

int pop(int sno)
{
  if (size[sno] == 0)
  {
    cout << "Stack NO." << sno << " is empty!" << endl;
    return 0;
  }
  size[sno] -= 1;
  return arr[MAX / 3 * sno + size[sno]];
}

void push(int sno, int value)
{
  if (size[sno] == MAX / 3)
  {
    cout << "Stack No." << sno << " is full!" << endl;
    return;
  }
  arr[MAX / 3 * sno + size[sno]] = value;
  size[sno] += 1;
}

bool is_empty(int sno)
{
  return (size[sno] == 0)? true : false;
}

int stack_size(int sno)
{
  return size[sno];
}

int main()
{
  for (int i = 0; i < MAX / 3; ++i)
    push(0, i);
  cout << "Size of No.0 is " << stack_size(0) << endl;
  push(0, 1);   //push into a full stack
  pop(1);   //pop from an empty stack
  push(1, 1);
  cout << pop(1) << endl;
  return 0;
}
