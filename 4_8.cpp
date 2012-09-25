/*******************************
You have two very large binary
trees: T1, with millions of nodes,
and T2, with hundreds of nodes.
Create an algorithm to decide if
T2 is a subtree of T1.
A tree T2 is a subtree of T1 if 
there exists a node n in T1 such
that the subtree of n is identical
to T2. That is, if you cut off
the tree at node n, the two trees
would be identical.
*******************************/

#include <iostream>

using namespace std;

struct Node
{
  int value;
  Node *left;
  Node *right;
  Node (int v = 0, Node *l = NULL, Node *r = NULL)
  {
    value = v;
    left = l;
    right = r;
  }
};

bool compare_tree(Node *n1, Node *n2)
{
  if (n1 == NULL && n2 == NULL)
    return true;
  else if (n1 == NULL || n2 == NULL)
    return false;
  if (n1 -> value == n2 -> value)
    return (compare_tree(n1 -> left, n2 -> left) && compare_tree(n1 -> right, n2 -> right));
  else 
    return false;
}

bool is_subtree(Node *n1, Node *n2)  //check if n2 is a subtree of n1
{
  if (n1 == NULL)
    return false;
  if (n2 == NULL)
    return true;
  if (compare_tree(n1, n2))
    return true;
  return (is_subtree(n1 -> left, n2) || is_subtree(n1 -> right, n2));
}

int main()
{
  Node *root = new Node(4);
  Node *l1 = new Node(1);
  Node *r1 = new Node(6);
  Node *l2 = new Node(0);
  Node *r2 = new Node(3);
  Node *l3 = new Node(5);
  Node *r3 = new Node(7);
  Node *l4 = new Node(2);
  root -> left = l1;
  root -> right = r1;
  l1 -> left = l2;
  l1 -> right = r2;
  r1 -> left = l3;
  r1 -> right = r3;
  // l2 -> right = r2;
  r2 -> left = l4;


  //  Node *nl1 = new Node(1);
  //  Node *nl2 = new Node(0);
  //  Node *nr2 = new Node(3);
  Node *nl4 = new Node(2);
  // nl1 -> left = nl2;
  // nl1 -> right = nr2;
  // l2 -> right = r2;
  // nr2 -> left = nl4;

  cout << is_subtree(root, nl4) << endl;
  return 0;
}
