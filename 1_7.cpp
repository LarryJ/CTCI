/*******************************
Write an algorithm such that if
an element in an MxN matrix is
0, its entire row and column are
set to 0
*******************************/

#include <iostream>
#include <vector>

using namespace std;

const int M = 3;
const int N = 4;

void modify_matrix(int m[][N])
{
  vector<int> row, column;
  for (int i = 0; i < M; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      if (m[i][j] == 0)
      {
	row.push_back(i);
	column.push_back(j);
      }
    }
  }
  //modify the matrix
  //row
  for (int i = 0; i < row.size(); ++i)
    for (int j = 0; j < N; ++j)
      m[row[i]][j] = 0;
  //column
  for (int i = 0; i < column.size(); ++i)
    for (int j = 0; j < M; ++j)
      m[j][column[i]] = 0;
}

int main()
{
  int m[M][N] = {{0, 1, 1, 1}, {0, 1, 0, 1}, {1, 1, 1, 1}};
  modify_matrix(m);
  for (int i = 0; i < M; ++i)
  {
    for (int j = 0; j < N; ++j)
      cout << m[i][j];
    cout << endl;
  }
  return 0;
}
