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

bool is_balanced(Node *root, int &h)
{
  if (root == NULL)
  {
    h = 0;
    return true;
  }
  int hl = 0, hr = 0;
  if (is_balanced(root -> left, hl) && is_balanced(root -> right, hr))
  {
    if (abs(hl - hr) <= 1)
    {
      h = max(hl, hr) + 1;
      return true;
    }
    else
      return false;
  }
  else
    return false;
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
  l1 -> right = r2;
  r1 -> left = l3;
  r1 -> right = r3;
  //l2 -> right = r2;
  r2 -> left = l4;
  int h = 0;
  cout << is_balanced(root, h) << endl;
  return 0;
}
