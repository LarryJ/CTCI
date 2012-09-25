/*******************************
Write code to remove duplicates
from an unsorted linked list,
no extra buffer allowed
*******************************/

#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node *next;
  Node(int v = 0, Node *n = NULL){value = v; next = n;}
};

void remove_duplicates(Node *root)
{
  while (root != NULL)
  {
    Node *n = root;
    while (n -> next != NULL)
    {
      if (n -> next -> value == root -> value)
      {
	Node *temp = n -> next;
	n -> next = temp -> next;
	delete temp;
	temp = NULL;
      }
      else
	n = n -> next;
    }
    root = root -> next;
  }

}

int main()
{
  Node *n7 = new Node(1);
  Node *n6 = new Node(0, n7);
  Node *n5 = new Node(3, n6);
  Node *n4 = new Node(4, n5);
  Node *n3 = new Node(0, n4);
  Node *n2 = new Node(2, n3);
  Node *n1 = new Node(1, n2);
  Node *root = new Node(0, n1);
  remove_duplicates(root);
  Node *n = root;
  while (n != NULL)
  {
    cout << n -> value << " -> ";
    n = n -> next;
  }
  cout << endl;
  return 0;
}
