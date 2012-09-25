/*******************************
Implement a function to check
if a binary tree is balanced.
For the purposes of this question,
a balanced tree is defined to be
a tree such that the heights of
the two subtrees of any node
never differ by more than one.
*******************************/

#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Node
{
  int value;
  Node *left;
  Node *right;
  Node(int v = 0, Node *l = NULL, Node *r = NULL)
  {value = v; left = l; right = r;}
};

int tree_height(Node *root)
{
  if (root == NULL)
    return 0;
  int hl = tree_height(root -> left);
  int hr = tree_height(root -> right);
  return max(hl, hr) + 1;
}

bool is_balanced(Node *root)
{
  if (root == NULL)
    return true;
  //check if the tree is balanced
  int hl = tree_height(root -> left);
  int hr = tree_height(root -> right);
  if (abs(hl - hr) > 1)
    return false;
  //check left subtree and right subtree
  return (is_balanced(root -> left) && is_balanced(root -> right));
}

int main()
{
  Node *root = new Node(0);
  Node *l1 = new Node(1);
  Node *r1 = new Node(2);
  Node *l2 = new Node(3);
  Node *r2 = new Node(4);
  Node *l3 = new Node(5);
  Node *r3 = new Node(6);
  Node *l4 = new Node(7);
  root -> left = l1;
  root -> right = r1;
  l1 -> left = l2;
  //l1 -> right = r2;
  r1 -> left = l3;
  r1 -> right = r3;
  l2 -> right = r2;
  r2 -> left = l4;
  cout << is_balanced(root) << endl;
  return 0;
}
