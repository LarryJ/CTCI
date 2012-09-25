/*******************************
Write code to partition a linked
list around a value x, such that
all nodes less than x come before
all nodes greater than or equal
to x
*******************************/

#include <iostream>
#include <vector>

using namespace std;

const int pivot = 2;

struct Node
{
  int value;
  Node *next;
  Node (int v = 0, Node *n = NULL){value = v; next = n;}
};

Node *partition(Node *root, int pivot)
{
  if (root == NULL)
    return NULL;
  vector<Node *> v1, v2;
  Node *n1;
  Node *n2;
  while (root != NULL)
  {
    if (root -> value < pivot)
    {
      if (v1.empty())   //the first element < pivot
      {
	v1.push_back(root);
	n1 = root;
      }
      else
      {
	n1 -> next = root;
	n1 = root;
      }
    }
    else
    {
      if (v2.empty())  //the first element >= pivot
      {
	v2.push_back(root);
	n2 = root;
      }
      else
      {
	n2 -> next = root;
	n2 = root;
      }
    }
    root = root -> next;
  }
  //connect n1 and n2
  if (!v2.empty())
    n2 -> next = NULL;
  if (v1.empty())
    return v2[0];
  if (!v2.empty())
    n1 -> next = v2[0];
  return v1[0];
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
  Node *result = partition(root, pivot);
  Node *n = result;
  while (n != NULL)
  {
    cout << n -> value << " -> ";
    n = n -> next;
  }
  cout << endl;
  return 0; 
}

