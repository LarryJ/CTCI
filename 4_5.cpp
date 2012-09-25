/*******************************
Implement a function to check
if a binary tree is a binary
search tree
*******************************/

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  int value;
  Node *left;
  Node *right;
  Node (int v = 0, Node *l = NULL, Node *r = NULL)
  {
    value = v; left = l; right = r;
  }
};

void in_order_traverse(Node *root, vector<Node *> &v)
{
  if (root == NULL)
    return;
  in_order_traverse(root -> left, v);
  v.push_back(root);
  in_order_traverse(root -> right, v);
}

bool is_binary_search_tree(Node *root)
{
  if (root == NULL)
    return false;
  vector<Node *> v;
  in_order_traverse(root, v);
  for (size_t i = 1; i < v.size(); ++i)
    if (v[i] -> value < v[i - 1] -> value)
      return false;
  return true;
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
  cout << is_binary_search_tree(root) << endl;
  return 0;
}
