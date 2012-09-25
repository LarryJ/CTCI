/*******************************
Given a binary search tree, 
design an algorithm which creates
a linked list of all the nodes
at each depth (e.g., if you have
a tree with depth D, you'll have
D linked lists).
*******************************/

#include <iostream>
#include <queue>
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

struct LinkedNode
{
  int value;
  LinkedNode *next;
  LinkedNode (int v = 0, LinkedNode *n = NULL)
  {
    value = v; next = n;
  }
};

vector<vector<LinkedNode *> > tree_to_linked_list(Node *root)
{
  vector<vector<LinkedNode *> > v;
  if (root == NULL)
    return v;
  //use BFS
  queue<pair<Node *, int> > q;   //store Node and its level
  q.push(pair<Node *, int> (root, 0));
  vector<LinkedNode *> v1;
  LinkedNode *n = new LinkedNode(root -> value);
  v1.push_back(n);
  v.push_back(v1);
  while (!q.empty())
  {
    Node *temp_node = q.front().first;
    int temp_level = q.front().second;
    q.pop();
    if (temp_node -> left != NULL)
    {
      LinkedNode *ln = new LinkedNode(temp_node -> left -> value);
      q.push(pair<Node *, int> (temp_node -> left, temp_level + 1));
      if (v.size() <= temp_level + 1)    //create a new head
      {
	vector<LinkedNode *> v2;
	v2.push_back(ln);
	v.push_back(v2);
      }
      else
	v[v.size() - 1].push_back(ln);
    }
    if (temp_node -> right != NULL)
    {
      LinkedNode *ln = new LinkedNode(temp_node -> right -> value);
      q.push(pair<Node *, int> (temp_node -> right, temp_level + 1));
      if (v.size() <= temp_level + 1)    //create a new head
      {
	vector<LinkedNode *> v2;
	v2.push_back(ln);
	v.push_back(v2);
      }
      else
	v[v.size() - 1].push_back(ln);
    }
  }
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
  // l2 -> right = r2;
  r2 -> left = l4;
  vector<vector<LinkedNode *> > v= tree_to_linked_list(root);
  for (size_t i = 0; i < v.size(); ++i)
  {
    for (size_t j = 0; j < v[i].size(); ++j)
      cout << v[i][j] -> value << " -> ";
    cout << endl;
  }
  return 0;
}
