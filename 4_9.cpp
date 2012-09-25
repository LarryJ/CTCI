/*******************************
You are given a binary tree in
which each node contains a value.
Design an algorithm to print all
paths which sum to a given value.
Note that a path can start or end
anywhere in the tree.
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

const int N = 5;

void find_sum_path(Node *root, int value, vector<int> v)
{
  if (root == NULL)
    return;
  v.push_back(root -> value);
  int sum = 0;
  for (int i = v.size() - 1; i >= 0; --i)
  {
    sum += v[i];
    if (sum == value)
    {
      for (size_t j = i; j < v.size(); ++j)
	cout << v[j] << " -> ";
      cout << endl;
    }
  }
  find_sum_path(root -> left, value, v);
  find_sum_path(root -> right, value, v);
}

void find_sum_path(Node *root, int value)
{
  vector<int> v;
  find_sum_path(root, value, v);
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
  find_sum_path(root, N);
  return 0;
}
