/*******************************
Write an algorithm to print all
ways of arranging eight queens
on an 8x8 chess board so that
none of them share the same row,
column or diagonal. In this case,
"diagonal" means all diagonals,
not just the two that bisect the
board.
*******************************/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

bool check_validation(int row, int column, vector<int> current_board)
{
  for (size_t i = 0; i < current_board.size(); ++i)
  {
    if (current_board[i] == column)    //check the column
      return false;
    if (row - i == abs(current_board[i] - column))  //check the diagonal
      return false;
  }
  return true;
}

void _8queens_recursion(int row, vector<int> current_board, vector<vector<int> > &result)
{
  if (row == 8)
  {
    result.push_back(current_board);
    return;
  }
  for (int i = 0; i < 8; ++i)
  {
    if (check_validation(row, i, current_board))
    {
      vector<int> temp = current_board;
      temp.push_back(i);
      _8queens_recursion(row + 1, temp, result);
    }
  }
}

void _8queens(vector<vector<int> > &result)
{
  vector<int> current_board;
  _8queens_recursion(0, current_board, result);
}

int main()
{
  vector<vector<int> > result;
  _8queens(result);
  for (size_t i = 0; i < result.size(); ++i)
  {
    for (size_t j = 0; j < result[i].size(); ++j)
      cout << result[i][j] << " ";
    cout << endl;
  }
  cout << "TOTAL: " << result.size() << endl;
  return 0;
}
