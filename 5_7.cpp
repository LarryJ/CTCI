/*******************************
An array A contains all the
integers 0 to n, except for one
number which is missing. In this
problem, we cannot access an
entire integer in A with a single
operation. The elements of A are
represented in binary, and the
only operation we can use to 
access them is "fetch the jth bit
of A[i]", which takes constant time.
Write code to find the missing
integer. Can you do it in O(n) time?
*******************************/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int NUM = 10;
const int MISS_NUM = 5;

//O(1)
int fetch_bit(int n, int j)
{
  if (j >= sizeof(int) * 8)
    return -1;
  else
    return (n >> j & 1); 
}

int length(int n)
{
  int count = 0;
  while (n > 0)
  {
    ++count;
    n /= 2;
  }
  return count;
} 

int search_by_bit(vector<int> v, int l, int pos)
{
  if (pos > l)
    return 0;
  vector<int> v0;
  vector<int> v1;
  for (size_t j = 0; j < v.size(); ++j)
  {
    if (v[j] >> pos & 1)
      v1.push_back(v[j]);
    else
      v0.push_back(v[j]);
  }
  //NUM is odd -> count0 should be equal to count1
  //NUM is even -> count0 should be equal to count1
  if (v0.size() > v1.size())
  {
    int result = search_by_bit(v1, l, pos + 1);
    return result << 1 | 1;
  }
  else
  {
    int result = search_by_bit(v0, l, pos + 1);
    return result << 1 | 0;
  }
}
int find_missing_integer(vector<int> v)
{
  int l = length(v.size() - 1);
  int result = search_by_bit(v, l, 0);
  return result;
}

int main()
{
  int arr[NUM - 1] = {1, 4, 3, 9, 2, 6, 5, 7, 0};
  vector<int> v(arr, arr + NUM - 1);
  cout << find_missing_integer(v) << endl;
  return 0;
}
