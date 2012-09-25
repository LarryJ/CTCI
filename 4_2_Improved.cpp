/*******************************
Given a directed graph, design
an algorithm to find out whether
there is a route between two
nodes
*******************************/

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node
{
  int value;
  vector<Node *> neib;
  Node (int v = 0){value = v;}
};

bool my_DFS(Node *src, Node *des, map<Node *, int> &m)
{
  if (src == des)
    return true;
  for (size_t i = 0; i < src -> neib.size(); ++i)
  {
    map<Node *, int>::iterator it = m.find(src -> neib[i]);
    if (it != m.end())
      continue;
    else
    {
      m.insert(pair<Node *, int> (src -> neib[i], 0));
      if (my_DFS(src -> neib[i], des, m))
	return true;
    }
  }
  return false;
}

//use DFS
bool has_route(Node *src, Node *des)
{
  if (src == NULL || des == NULL)
    return false;
  map<Node *, int> m;
  return my_DFS(src, des, m);
}

int main()
{
  Node *a = new Node(1);
  Node *b = new Node(2);
  Node *c = new Node(3);
  Node *d = new Node(4);
  Node *e = new Node(5);
  a -> neib.push_back(b);
  a -> neib.push_back(c);
  a -> neib.push_back(d);
  b -> neib.push_back(a);
  b -> neib.push_back(c);
  c -> neib.push_back(a);
  c -> neib.push_back(b);
  c -> neib.push_back(e);
  d -> neib.push_back(a);
  e -> neib.push_back(c);
  cout <<  has_route(d, e) << endl;
  return 0;
}
