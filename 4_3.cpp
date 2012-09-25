/*******************************
Given a sorted (increasing order)
array, write an algorithm to
create a binary search tree with
minimal height.
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
    value = v; left = l; right = r;
  }
};

Node *my_binary_search(int *arr, int beg, int end)
{
  if (beg > end)
    return NULL;
  int mid = (beg + end) / 2;
  Node *n = new Node(arr[mid]);
  Node *left = my_binary_search(arr,  beg, mid - 1);
  Node *right = my_binary_search(arr, mid + 1, end);
  n -> left = left;
  n -> right = right;
  return n;
}

Node *array_to_tree(int *arr, int length)
{
  int beg = 0;
  int end = length - 1;
  return my_binary_search(arr, beg, end);
}

void in_order_traverse(Node *root)
{
  if (root == NULL)
    return;
  in_order_traverse(root -> left);
  cout << root -> value << endl;
  in_order_traverse(root -> right);
}

int main()
{
  int arr[10];
  for (int i = 0; i < 10; ++i)
    arr[i] = i;
  Node *root = array_to_tree(arr, 10);
  in_order_traverse(root);
  return 0;
}
