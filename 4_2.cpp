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

//use BFS
bool has_route(Node *src, Node *des)
{
  if (src == NULL || des == NULL)
    return false;
  map<Node *, int> m;
  queue<Node *> q;
  q.push(src);
  while (!q.empty())
  {
    Node *n = q.front();
    q.pop();
    for (size_t i = 0; i < n -> neib.size(); ++i)
    {
      if (n -> neib[i] == des)
	return true;
      map<Node *, int>::iterator it = m.find(n -> neib[i]);
      if (it != m.end())   //node already visited
	continue;
      else
      {
	m.insert(pair<Node *, int> (n -> neib[i], 0));
	q.push(n -> neib[i]);
      }
    }
  }
  return false;
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
