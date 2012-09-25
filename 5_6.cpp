/*******************************
Write a program to swap odd and
even bits in an integer with as
few instructions as possible
(e.g., bit 0 and bit 1 are swapped,
bit 2 and bit 3 are swapped, and 
so on)
*******************************/

#include <iostream>

using namespace std;

const int N = 145;

int convert_integer(int n)
{
  for (int i = 0; i < sizeof(int) * 8; i += 2)
  {
    int p1 = 1 & (n >> i);
    int p2 = 1 & (n >> (i + 1));
    if (p1 != p2)
    {
      if (p1 == 0)
      {
	n &= ~(1 << (i + 1));
	n |= 1 << i;
      }
      else
      {
	n |= 1 << (i + 1);
	n &= ~(1 << i);
      }
    }
  }
  return n;
}

int main()
{
  cout << convert_integer(N) << endl;
  return 0;
}
