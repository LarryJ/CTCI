/*******************************
Write code to partition a linked
list around a value x, such that
all nodes less than x come before
all nodes greater than or equal
to x
*******************************/

#include <iostream>

using namespace std;

const int pivot = 2;

struct Node
{
  int value;
  Node *next;
  Node (int v = 0, Node *n = NULL){value = v; next = n;}
};

void partition(Node *&root, int pivot)
{
  if (root == NULL)
    return;
  Node *first = root;
  Node *second = root;
  while (first != NULL)
  {
    if (first -> value < pivot)
    {
      int temp = first -> value;
      first -> value = second -> value;
      second -> value = temp;
      second = second -> next;
    }
    first = first -> next;
  }
}

int main()
{
  Node *n6 = new Node(1);
  Node *n5 = new Node(3, n6);
  Node *n4 = new Node(3, n5);
  Node *n3 = new Node(0, n4);
  Node *n2 = new Node(2, n3);
  Node *n1 = new Node(1, n2);
  Node *root = new Node(0, n1);
  partition(root, pivot);
  Node *n = root;
  while (n != NULL)
  {
    cout << n -> value << " -> ";
    n = n -> next;
  }
  cout << endl;
  return 0; 
}
