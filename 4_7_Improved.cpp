/*******************************
Design an algorithm and write
code to find the first common
ancestor of two nodes in a
binary tree. No additional data
structures can be used
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

bool find_path(Node *root, Node *n)
{
  if (root == NULL)
    return false;
  if (root == n)
    return true;
  return (find_path(root -> left, n) || find_path(root -> right, n));
}

Node *find_first_common_node(Node *root, Node *n1, Node *n2)
{
  if (root == NULL || n1 == NULL || n2 == NULL)
    return NULL;
  if (root == n1 || root == n2)
    return root;
  bool l_flag_1 = find_path(root -> left, n1);
  bool r_flag_1 = find_path(root -> right, n1);
  bool l_flag_2 = find_path(root -> left, n2);
  bool r_flag_2 = find_path(root -> right, n2);
  if ((l_flag_1 == true && r_flag_2 == true) ||
      (r_flag_1 == true && l_flag_2 == true))
    return root;
  else if (l_flag_1 == true && l_flag_2 == true)
    return find_first_common_node(root -> left, n1, n2);
  else if (r_flag_1 == true && r_flag_2 == true)
    return find_first_common_node(root -> right, n1, n2);
  else
    return NULL;
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
  Node *result = find_first_common_node(root, l4, l3);
  if (result != NULL)
    cout << result -> value << endl;
  return 0;
}
