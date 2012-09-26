/*******************************
You have a stack of n boxes,
with widths wi, heights hi, and
depths di. The boxes cannot be
rotated and can only be stacked
on top of one another if each
box in the stack is strictly
larger than the box above it in
width, height, and depth. 
Implement a method to build the
tallest stack possible, where the
height of a stack is the sum of
the heights of each box
*******************************/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 6;

bool my_compare(double b1[3], double b2[3])
{
  if (b1[1] == b2[1])
  {
    if (b1[0] == b2[0])
      return (b1[2] < b2[2]);
    else
      return (b1[0] < b1[0]);
  }
  else
    return (b1[1] < b2[1]);
}

double max_heights(double b[][3], int n)
{
  double **box = new double *[n];
  for (int i = 0; i < n; ++i)
  {
    box[i] = new double[3];
    box[i][0] = b[i][0];  //width
    box[i][1] = b[i][1];  //height
    box[i][2] = b[i][2];  //depth
  }
  sort(box, box + n, my_compare);   //sort the boxes
  double *arr = new double[n];
  arr[0] = box[0][1];
  for (int i = 0; i < n; ++i)
  {
    double max = 0;
    for (int j = 0; j < i; ++j)
    {
      if (box[j][0] < box[i][0] &&
	  box[j][1] < box[i][1] && box[j][2] < box[i][2])
	if (arr[j] > max)
	  max = arr[j];
    }
    arr[i] = max + box[i][1];
  }
  for (int i = 0; i < n; ++i)
    delete []box[i];
  delete box;
  box = NULL;
  double max = 0;
  for (int i = 0; i < n; ++i)
    if (arr[i] > max)
      max = arr[i];
  delete arr;
  arr = NULL;
  return max;
}

int main()
{
  double box[N][3] = {{1.00, 2.31, 3.44}, {2.3, 1.11, 3.44}, {2.12, 3.33, 4.44},
		      {0.01, 1.31, 1.44}, {12.3, 11.11, 14.44}, {7.12, 7.33, 5.44}};
  cout << max_heights(box, N) << endl;
  return 0;
}
