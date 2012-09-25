/*******************************
Write a function to determine the
number of bits required to 
convert integer A to integer B
EXAMPLE
Input: 31, 14
Output: 2
*******************************/

#include <iostream>

using namespace std;

const int M = 14;
const int N = 31;

int convert_bits(int m, int n)
{
  m ^= n;
  int count = 0;
  for (; m != 0; m >>= 1)
    if ((m & 1) == 1)
      ++count;
  return count;
}

int main()
{
  cout << convert_bits(M, N) << endl;
  return 0;
}
