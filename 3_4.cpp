/*******************************
In the classic problem of the
Towers of Hanoi, you have 3
towers and N disks of different
sizes which can slide onto any
tower. The puzzle starts with
disks sorted in ascending order
of size from top to bottom (i.e.,
each disk sits on top of an even
larger one). You have the
following constraints:
(1) Only one disk can be moved
at a time.
(2) A disk is slid off the top
of one tower onto the next tower
(3) A disk can only be placed on
top of a larger disk
Write a program to move the disks
from the first tower to the last
using stacks
*******************************/

#include <iostream>

using namespace std;

const int N = 3;

void move_disk(char A, char B, char C, int N)   //A to C
{
  if (N == 0)
    return;
  //move N - 1 disk to B
  move_disk(A, C, B, N - 1);
  //move last disk to C
  cout << A << " -> " << C << endl;
  //move N - 1 disk to C
  move_disk(B, A, C, N - 1);
}

int main()
{
  char a = 'A', b = 'B', c = 'C';
  move_disk(a, b, c, N);
  return 0;
}
