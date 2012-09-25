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
(4) Disks can only be moved onto
an adjacent tower 
Write a program to move the disks
from the first tower to the last
using stacks
*******************************/

#include <iostream>

using namespace std;

const int N = 3;

void move_side_to_center(char A, char C, char B, int n);
void move_center_to_side(char B, char A, char C, int n);

void move_side_to_center(char A, char C, char B, int n)  //A to B
{
  if (n == 0)
    return;
  //move n - 1 disk from A to B
  move_side_to_center(A, C, B, n - 1);
  //move n - 1 disk from B to C
  move_center_to_side(B, A, C, n - 1);
  //move last disk from A to B
  cout << A << " -> " << B << endl;
  //move n - 1 disk from C to B
  move_side_to_center(C, A, B, n - 1);
}

void move_center_to_side(char B, char A, char C, int n)  //B to C
{
  if (n == 0)
    return;
  //move n - 1 disk from B to A
  move_center_to_side(B, C, A, n - 1);
  //move last disk from B to C
  cout << B << " -> " << C << endl;
  //move n - 1 disk from A to B
  move_side_to_center(A, C, B, n - 1);
  //move n - 1 disk from B to C
  move_center_to_side(B, A, C, n - 1);
} 

void move_disk(char A, char B, char C, int n)   //A to C
{
  if (n == 0)
    return;
  //move n - 1 disk from A to B
  move_side_to_center(A, C, B, n - 1);
  //move n - 1 disk from B to C
  move_center_to_side(B, A, C, n - 1);
  //move last disk from A to B
  cout << A << " -> " << B << endl;
  //move n - 1 disk from C to B
  move_side_to_center(C, A, B, n - 1);
  //move n - 1 disk from B to A
  move_center_to_side(B, C, A, n - 1);
  //move last disk from B to C
  cout << B << " -> " << C << endl;
  //move n - 1 disk from A to B
  move_side_to_center(A, C, B, n - 1);
  //move n - 1 disk from B to C
  move_center_to_side(B, A, C, n - 1);
}

int main()
{
  char a = 'A', b = 'B', c = 'C';
  move_disk(a, b, c, N);
  return 0;
}
