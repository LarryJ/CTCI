/*******************************
A magic index in an array 
A[0...n-1] is defined to be an
index such that A[i] = i. Given
a sorted array, write a method
to find a magic index, if one
exists, in array A
*******************************/

#include <iostream>

using namespace std;

const int N = 10;

bool find_magic_number(int *arr, int n)
{
  int beg = 0;
  int end = n - 1;
  while (beg <= end)
  {
    int mid = (beg + end) / 2;
    if (arr[mid] == mid)
      return true;
    else if (arr[mid] > mid)
      end = mid - 1;
    else 
      beg = mid + 1;
  }
  return false;
}

int main()
{
  int arr[N] = {-10, -8, -5, 0, 2, 4, 5, 6, 7, 9};
  cout << find_magic_number(arr, N) << endl;
  return 0;
}
