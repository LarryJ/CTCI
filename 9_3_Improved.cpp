/*******************************
A magic index in an array 
A[0...n-1] is defined to be an
index such that A[i] = i. Given
a sorted array, write a method
to find a magic index, if one
exists, in array A
(values in the arrays are not 
distinct)
*******************************/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;

bool find_magic_number(int *arr, int beg, int end)
{
  if (beg > end)
    return false;
  int mid = (beg + end) / 2;
  if (arr[mid] == mid)
    return true;
  if (find_magic_number(arr, beg, min(mid - 1, arr[mid])))
    return true;
  return find_magic_number(arr, max(mid + 1, arr[mid]), end);
}

int main()
{
  int arr[N] = {-1, 0, 0, 0, 5, 6, 6, 13, 18, 18};
  cout << find_magic_number(arr, 0, N - 1) << endl;
  return 0;
}
