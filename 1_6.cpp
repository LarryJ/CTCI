/*******************************
Given an image represented by
an NxN matrix, where each pixel
in the image is 4 bytes, write 
a method to rotate the image by
90 degrees. Can you do this
in place?
*******************************/

#include <iostream>

using namespace std;

typedef int PIX;

const int N = 5;

void rotate_circle(int pos, PIX m[][N])
{
  for (int i = 0; i < N - 1 - 2 * pos; ++i)
  {
    PIX temp = m[pos][pos + i];
    m[pos][pos + i] = m[N - 1 - pos - i][pos];
    m[N - 1 - pos - i][pos] = m[N - 1 - pos][N - 1 - i - pos];
    m[N - 1 - pos][N - 1 - i - pos] = m[pos + i][N - 1 - pos];
    m[pos + i][N - 1 - pos] = temp;
  }
}

void rotate_matrix(PIX m[][N])
{
  for (int i = 0; i < N / 2; ++i)
    rotate_circle(i, m);
}

int main()
{
  PIX m[N][N];
  int n = 0;
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      m[i][j] = n;
      ++n;
    }
  }
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      cout << m[i][j];
    }
    cout << endl;
  }
  rotate_matrix(m);
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
