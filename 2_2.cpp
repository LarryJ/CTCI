/*******************************
Implement an algorithm to find
kth to last element of a singly
linked list
*******************************/

#include <iostream>

using namespace std;

const int k = 1;

struct Node
{
  int value;
  Node *next;
  Node(int v = 0, Node *n = NULL){value = v; next = n;}
};

void k_to_last_element(Node *root)
{
  Node *first = root;
  Node *second = root;
  int i = 0;
  while (i < k && first != NULL)
  {
    ++i;
    first = first -> next;
  }
  if (first == NULL)
  {
    cout << "total No. of nodes < k" << endl;
    return;
  }
  while (first -> next != NULL)
  {
    first = first -> next;
    second = second -> next;
  }
  cout << second -> value << endl;
}

int main()
{
  Node *n6 = new Node(0);
  Node *n5 = new Node(3, n6);
  Node *n4 = new Node(3, n5);
  Node *n3 = new Node(0, n4);
  Node *n2 = new Node(2, n3);
  Node *n1 = new Node(1, n2);
  Node *root = new Node(0, n1);
  k_to_last_element(root);
  return 0;
}
