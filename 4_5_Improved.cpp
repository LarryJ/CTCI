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

bool check_binary_tree(Node *root, int &l_value, int &r_value)
{
  int l = 0, r = 0;
  //check left subtree
  if (root -> left != NULL)
  {
    if (!check_binary_tree(root -> left, l, r))
      return false;
    if (root -> value < r)
      return false;
    l_value = l;
  }
  else
    l_value = root -> value;
  //check right subtree
  if (root -> right != NULL)
  {
    if (!check_binary_tree(root -> right, l, r))
      return false;
    if (root -> value >= l)
      return false;
    r_value = r;
  }
  else
    r_value = root -> value;
  return true;
}

bool is_binary_search_tree(Node *root)
{
  if (root == NULL)
    return false;
  int l_value = 0, r_value = 0;
  return check_binary_tree(root, l_value, r_value);
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
