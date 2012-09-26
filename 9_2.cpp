/*******************************
Imagine a robot sitting on the 
upper left corner of an X by Y
grid. The robot can only move in
two directions: right and down.
How many possible paths are there
for the robot to go from (0, 0)
to (X, Y)
*******************************/

#include <iostream>

using namespace std;

const int X = 5;
const int Y = 6;

int count_grid_paths(int x, int y, int **grid)
{
  if (grid[x][y] != 0)
    return grid[x][y];
  int ways = 0;
  if (x > 0)
    ways += count_grid_paths(x - 1, y, grid);
  if (y > 0)
    ways += count_grid_paths(x, y - 1, grid);
  grid[x][y] = ways;
  return ways;
}

int count_paths(int x, int y)
{
  int **grid = new int *[x];
  for (int i = 0; i < x; ++i)
    grid[i] = new int[y];
  
  grid[0][0] = 1;
  int result = count_grid_paths(x - 1, y - 1, grid);
  for (int i = 0; i < x; ++i)
    delete []grid[i];
  delete grid;
  grid = NULL;
  return result;
}

int main()
{
  cout << count_paths(X, Y) << endl;
  return 0;
}
