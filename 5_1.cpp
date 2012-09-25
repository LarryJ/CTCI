/*******************************
You are given two 32-bit numbers,
N and M, and two bit positions,
i and j. Write a method to insert
M into N such that M starts at
bit j and ends at bit i. You can
assume that the bits j through i
have enough space to fit all of M.
That is, if M = 10011, you can
assume that there are at least 5
bits between j and i. You would
not, for example, have j = 3 and
i = 2, because M could not fully
fit between bit 3 and bit 2.
EXAMPLE
Input: N = 10000000000, M = 10011,
       i = 2, j = 6
Output: N = 10001001100
*******************************/

#include <iostream>

using namespace std;

const int N = 1024;
const int M = 19;
const int i = 2;
const int j = 6;

int bit_insertion(int n, int m, int beg, int end)
{ 
  //set n's bits to 0s from beg to end
  for (int x = beg; x <= end; ++x)
    n &= ~(1 << x);
  for (int x = beg; x <= end; ++x)
  {
    n |= ((m & 1) << x);   //get the last bit of m
    m >>= 1;
  }
  return n;
}

int main()
{
  cout << bit_insertion(N, M, i, j) << endl;
  return 0;
}
