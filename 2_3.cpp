/*******************************
Implement an algorithm to delete
a node in the middle of a singly
linked list, given only access
to that node
EXAMPLE
Input: the node c from the linked
list a -> b -> c -> d -> e
Result: nothing is returned, but
the new linked list looks like
a -> b -> d -> e
*******************************/

#include <iostream>

struct Node
{
  int value;
  Node *next;
  Node(int v = 0, Node *n = NULL){value = v; next = n;}
};

using namespace std;

void delete_middle_node(Node *&middle)
{
  if (middle == NULL)
    return;
  while (middle -> next != NULL)
  {
    middle -> value = middle -> next -> value;
    if (middle -> next -> next == NULL)
    {
      Node *temp =  middle -> next;
      middle -> next = NULL;
      middle = temp;
      break;
    }
    middle = middle -> next;
  }
  delete middle;
  middle = NULL;
}

int main()
{
  Node *n6 = new Node(11);
  Node *n5 = new Node(3, n6);
  Node *n4 = new Node(3, n5);
  Node *n3 = new Node(0, n4);
  Node *n2 = new Node(2, n3);
  Node *n1 = new Node(1, n2);
  Node *root = new Node(0, n1);
  delete_middle_node(n3);
  Node *n = root;
  while (n != NULL)
  {
    cout << n -> value << " -> ";
    n = n -> next;
  }
  cout << endl;
  return 0;
}
