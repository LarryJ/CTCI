/*******************************
Write an algorithm to find the
"next" node(i.e., in-order 
successor) of a given node in a
binary search tree. You may
assume each node has a link to
its parent.
*******************************/

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  int value;
  Node *left;
  Node *right;
  Node *parent;
  Node (int v = 0, Node *l = NULL, Node *r = NULL, Node *p = NULL)
  {
    value = v; left = l; right = r; parent = p;
  }
};

void in_order_traverse(vector<Node *> &v, Node *root)
{
  if (root == NULL)
    return;
  in_order_traverse(v, root -> left);
  v.push_back(root);
  in_order_traverse(v, root -> right);
}

Node *find_next_node(Node *root, Node *src)
{
  if (root == NULL)
    return NULL;
  vector<Node *> v;
  in_order_traverse(v, root);
  for (size_t i = 0; i < v.size(); ++i)
  {
    if (v[i] == src)
    {
      if (i < v.size() - 1)
	return v[i + 1];
      else
	return NULL;
    }
  }
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
  Node *result = find_next_node(root, l2);
  if (result != NULL)
    cout << result -> value << endl;
  return 0;
}
