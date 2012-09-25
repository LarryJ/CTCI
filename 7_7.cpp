/*******************************
Design an algorithm to find the
kth number such that the only
prime factors are 3, 5 and 7
*******************************/

#include <iostream>
#include <vector>

using namespace std;

void insert_element(vector<unsigned long> &v, unsigned long n)
{
  vector<unsigned long>::iterator it;
  for (it = v.begin(); it != v.end(); ++it)
  {
    if (*it == n)  //remove duplicates
      return;
    if (*it > n)
    {
      v.insert(it, n);
      return;
    }
  }
  //n is larger than all elements in v
  v.push_back(n);
}

unsigned long find_kth_number(int k)
{
  if (k < 0)
    return -1;
  vector<unsigned long> v;
  v.push_back(1);
  v.push_back(3);
  v.push_back(5);
  v.push_back(7);
  int pos = 0;
  while (pos != k)
  {
    unsigned long n = v[pos] * 3;
    insert_element(v, n);
    n = v[pos] * 5;
    insert_element(v, n);
    n = v[pos] * 7;
    insert_element(v, n);
    ++pos;
  }
  for (unsigned i = 0; i < v.size(); ++i)
    cout << v[i] << endl;
  return v[pos];
}

int main()
{
  cout << find_kth_number(105) << endl;
  return 0;
}
