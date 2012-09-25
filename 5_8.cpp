/*******************************
A monochrome screen is stored
as a single array of bytes,
allowing eight consecutive pixels
to be stored in one byte. The
screen has width w, where w is
divisible by 8 (that is, no byte
will be split across rows). The
height of the screen, of course,
can be derived from the length
of the array and the width. 
Implement a function 
drawHorizontalLine(byte[] screen,
int width, int x1, int x2, int y)
which draws a horizontal line
from (x1, y) to (x2, y).
*******************************/

#include <iostream>

using namespace std;

const int N = 18;
const int WIDTH = 48;

void display_bit(char c, int start, int end)
{
  for (int i = start; i >= end; --i)
  {
    int b = c >> i & 1;
    cout << b << " - ";
  }
}

void draw_horizontal_line(char screen[], int width, 
			  int x1, int x2, int y)
{
  if (x1 < 0 || x2 > width - 1 || x1 > x2)
    return;
  int height = N / (width / 8);
  if (y < 0 || y > height - 1)
    return;
  int start_byte = y * (width / 8) + x1 / 8;
  int start_bit = 7 - x1 % 8;
  int end_byte = y * (width / 8) + x2 / 8;
  int end_bit = 7 - x2 % 8;
  if (start_byte == end_byte)   //within 1 byte
  {
    display_bit(screen[start_byte], start_bit, end_bit);
    cout << endl;
    return;
  }
  else   //start, end in different byte
  {
    //display start byte
    display_bit(screen[start_byte], start_bit, 0);
    //display bytes between start and end
    for (int i = start_byte + 1; i < end_byte; ++i)
      display_bit(screen[i], 7, 0);
    //display end byte
    display_bit(screen[end_byte], 7, end_bit);
    cout << endl;
    return;
  }
}

int main()
{
  char screen[N] = {0, 0, 1, 1, 0, 1,
		    0, 1, 1, 1, 0, 0,
		    1, 0, 1, 0, 1, 1};
  draw_horizontal_line(screen, WIDTH, 13, 47, 2);
  return 0;
}
