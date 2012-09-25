/*******************************
Given a circular linked list,
implement an algorithm which
returns the node at the beginning
of the loop
DEFINITION
Circular linked list: A (corrupt)
linked list in which a node's
next pointer points to an earlier
node, so as to make a loop in the
linked list.
EXAMPLE
Input: A -> B -> C -> D -> E -> C
Output: C
*******************************/

#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node *next;
  Node (int v = 0, Node *n = NULL){value = v; next = n;}
};

Node *loop_beginning(Node *a)
{
  if (a == NULL)
    return NULL;
  Node *fast = a;
  Node *slow = a;
  while (fast -> next != NULL)
  {
    fast = fast -> next;
    if (fast -> next != NULL)
    {
      fast = fast -> next;
      slow = slow -> next;
      if (fast == slow)    //fast and slow meet
	break;
    }
    else
      return NULL;  //no loop
  }
  if (fast -> next == NULL)
    return NULL;   //no loop
  Node *cur = a;
  while (1)
  {
    if (cur == slow)
      return cur;
    cur = cur -> next;
    slow = slow -> next;
  }
}

int main()
{
  Node *a = new Node(1);
  Node *b = new Node(2);
  Node *c = new Node(3);
  Node *d = new Node(4);
  Node *e = new Node(5);
  a -> next = b;
  b -> next = c;
  c -> next = d;
  d -> next = e;
  e -> next = b;
  Node *result = loop_beginning(a);
  cout << (result == NULL?NULL:result -> value) << endl; 
  return 0;
}
