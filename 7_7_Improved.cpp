/*******************************
Design an algorithm to find the
kth number such that the only
prime factors are 3, 5 and 7
*******************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned long find_kth_number(int k)
{
  if (k < 0)
    return -1;
  vector<unsigned long> v3(1, 3);
  vector<unsigned long> v5(1, 5);
  vector<unsigned long> v7(1, 7);
  //find the min value in v3, v5, v7
  int count = 0;
  unsigned long n = 1;
  while (count != k)
  {
    n = min(min(v3[0], v5[0]), v7[0]);
    if (n == v3[0])
    {
      v3.erase(v3.begin());
      v3.push_back(n * 3);
      v5.push_back(n * 5);
      v7.push_back(n * 7);
    }
    else if (n == v5[0])
    {
      v5.erase(v5.begin());
      v5.push_back(n * 5);
      v7.push_back(n * 7);
    }
    else
    {
      v7.erase(v7.begin());
      v7.push_back(n * 7);
    }
    ++count;
  }
  return n;
}

int main()
{
  cout << find_kth_number(105) << endl;
  return 0;
}
