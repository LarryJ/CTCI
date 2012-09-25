/*******************************
You have two numbers represented
by a linked list, where each
node contains single digit. The
digits are stored in reverse
order, such that the 1's digit
is at the head of the list. Write
a function that adds the two
numbers and returns the sum as
a linked list.
EXAMPLE
Input: (7 -> 1 -> 6) +
       (5 -> 9 -> 2).
That is, 617 + 295
Output: 2 -> 1 -> 9. 
That is, 912
*******************************/

#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node *next;
  Node (int v = 0, Node *n = NULL){value = v; next = n;}
};

Node *add_linked_list(Node *f, Node *s, int carry)
{
  if (f == NULL && s == NULL && carry == 0)
    return NULL;
  int num = carry;
  Node *head = new Node;
  if (f != NULL)
  {
    num += f -> value;
    f = f -> next;
  }
  if (s != NULL)
  {
    num += s -> value;
    s = s -> next;
  }
  head -> value = num % 10;
  carry = num / 10;
  head -> next = add_linked_list(f, s, carry);
  return head;
}

int main()
{
  Node *f1 = new Node(7);
  Node *f2 = new Node(1);
  Node *f3 = new Node(9);
  //Node *f4 = new Node(10);
  f1 -> next = f2;
  f2 -> next = f3;
  //f3 -> next = f4;
  Node *s1 = new Node(5);
  Node *s2 = new Node(9);
  Node *s3 = new Node(2);
  s1 -> next = s2;
  s2 -> next = s3;
  Node *result = add_linked_list(f1, s1, 0);
  while (result != NULL)
  {
    cout << result -> value << " -> ";
    result = result -> next;
  }
  cout << endl;
  return 0;
}
