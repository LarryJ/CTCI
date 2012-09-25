/*******************************
Design an algorithm and write
code to find the first common
ancestor of two nodes in a
binary tree. Additional data
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

bool find_path(Node *root, Node *des, vector<Node *> &v)
{
  if (root == NULL)
    return false;
  if (root == des)
  {
    v.push_back(des);
    return true;
  }
  v.push_back(root);
  if (find_path(root -> left, des, v))
    return true;
  if (find_path(root -> right, des, v))
    return true;
  v.pop_back();
  return false;
}

Node *find_first_common_node(Node *root, Node *n1, Node *n2)
{
  if (root == NULL || n1 == NULL || n2 == NULL)
    return NULL;
  if (n1 == n2)
    return n1;
  vector<Node *> v1;
  // find the path from root to n1
  if (!find_path(root, n1, v1))    //v1 not under root
    return NULL;
  // find the path from root to n2
  vector<Node *> v2;
  if (!find_path(root, n2, v2))    //v2 not under root
    return NULL;
  //compare v1 v2
  size_t i = 1, j = 1;
  while (i < v1.size() && j < v2.size())
  {
    if (v1[i] != v2[j])
      return v1[i - 1];
    ++i;
    ++j;
  }
  return v1[i - 1];
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
  Node *result = find_first_common_node(root, l2, l4);
  if (result != NULL)
    cout << result -> value << endl;
  return 0;
}
