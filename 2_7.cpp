/*******************************
Implement a function to check if
a linked list is a palindrome
*******************************/

#include <iostream>
#include <stack>

using namespace std;

struct Node
{
  int value;
  Node *next;
  Node (int v = 0, Node *n = NULL){value = v; next = n;}
};

bool is_palindrome(Node *root)
{
  if (root == NULL)
    return false;
  stack<int> stk;
  Node *n = root;
  while (n != NULL)
  {
    stk.push(n -> value);
    n = n -> next;
  }
  while (root != NULL)
  {
    if (root -> value != stk.top())
      return false;
    root = root -> next;
    stk.pop();
  }
  return true;
}

int main()
{
  Node *a = new Node(1);
  Node *b = new Node(2);
  Node *c = new Node(3);
  Node *d = new Node(3);
  Node *e = new Node(2);
  Node *f = new Node(1);
  //Node *g = new Node(1);
  a -> next = b;
  b -> next = c;
  c -> next = d;
  d -> next = e;
  e -> next = f;
  //f -> next = g;
  cout << is_palindrome(a) << endl;
  return 0;
}
