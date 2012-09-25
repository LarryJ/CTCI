/*******************************
Write an algorithm to find the
"next" node(i.e., in-order 
successor) of a given node in a
binary search tree. You may
assume each node has a link to
its parent.
*******************************/

#include <iostream>

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

Node *find_leftmost_subnode(Node *root)
{
  if (root -> left == NULL)
    return root;
  return find_leftmost_subnode(root -> left);
}

Node *search_right_subtree(Node *src)
{
  if (src -> right == NULL)
    return NULL;
  return find_leftmost_subnode(src -> right);
}

Node *find_first_right_parent(Node *root)
{
  if (root -> parent == NULL)
    return NULL;
  if (root == root -> parent -> left)
    return root -> parent;
  return find_first_right_parent(root -> parent);
}

Node *find_next_node(Node *root, Node *src)
{
  if (root == NULL)
    return NULL;
  //find leftmost node of the right subtree
  Node *result = search_right_subtree(src);
  if (result != NULL)
    return result;
  //find first right parent
  result = find_first_right_parent(src);
  return result;
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
  l1 -> parent = root;
  r1 -> parent = root;
  l1 -> left = l2;
  l1 -> right = r2;
  l2 -> parent = l1;
  r2 -> parent = l1;
  r1 -> left = l3;
  r1 -> right = r3;
  l3 -> parent = r1;
  r3 -> parent = r1;
  // l2 -> right = r2;
  r2 -> left = l4;
  l4 -> parent = r2;
  Node *result = find_next_node(root, root);
  if (result != NULL)
    cout << result -> value << endl;
  return 0;
}
