/*******************************
Write a program to swap odd and
even bits in an integer with as
few instructions as possible
(e.g., bit 0 and bit 1 are swapped,
bit 2 and bit 3 are swapped, and 
so on)
*******************************/

#include <iostream>
#include <vector>

using namespace std;

const int N = 145;

int convert_integer(int n)
{
  return ((n & 0x55555555) << 1 | (n & 0xaaaaaaaa) >> 1);
}

int main()
{
  cout << convert_integer(N) << endl;
  return 0;
}
