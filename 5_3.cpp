/*******************************
Given a positive integer, print
the next smallest and the next
largest number that has the same
number of 1 bits in their binary
representation.
*******************************/

#include <iostream>

using namespace std;

//const int N = 2147483646;
const int N = 39;

int find_bit_position(int start, int bit, int n)
{
  int pos = start;
  while (pos < sizeof(int) * 8 - 1 && (n >> pos & 1) != bit)
    ++pos;
  if (pos == sizeof(int) * 8 - 1)
    return -1;
  return pos;
}

int find_next_largest(int n)
{
  //find first bit 1
  int fo = find_bit_position(0, 1, n);
  if (fo == -1)
    return -1;
  //find first bit 0 after fo
  int nz = find_bit_position(fo, 0, n);
  if (nz == -1)
    return -1;
  //convert nz to 1
  n |= 1 << nz;
  //clear 1s
  for (int i = fo; i < nz; ++i)
    n &= ~(1 << i);
  //add 1s to tail
  for (int i = 0; i < nz - fo - 1; ++i)
    n |= 1 << i;
  return n;
}

int find_next_smallest(int n)
{
  //find first bit 0
  int fz = find_bit_position(0, 0, n);
  if (fz == -1)
    return -1;
  //find first bit 1 after fz
  int no = find_bit_position(fz, 1, n);
  if (no == -1)
    return -1;
  //convert no to 0
  n &= ~(1 << no);
  //clear tail
  for (int i = 0; i < fz; ++i)
    n &= ~(1 << i);
  //add 1s
  for (int i = no - 1; i >= no - fz - 1; --i)
    n |= 1 << i;
  return n;
}

void find_numbers(int n)
{
  if (n <= 0)
  {
    cout << "Must be positive number!" << endl;
    return;
  }
  cout << find_next_smallest(n) << endl;
  cout << find_next_largest(n) << endl;
}

int main()
{
  find_numbers(N);
  return 0;
}
