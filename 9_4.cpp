/*******************************
Write a method to return all
subsets of a set
*******************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 5;

void find_subsets_recursion(char *arr, string s, int index, 
			    int end, vector<string> &result)
{
  if (index == end)
  {
    result.push_back(s);
    return;
  }
  find_subsets_recursion(arr, s, index + 1, end, result);   //add nothing
  s += arr[index];
  find_subsets_recursion(arr, s, index + 1, end, result);
}

vector<string> find_subsets(char *arr, int n)
{
  string s;
  vector<string> result;
  find_subsets_recursion(arr, s, 0, n, result);
  return result;
}

int main()
{
  char arr[N] = {'a', 'b', 'c', 'd', 'e'};
  vector<string> result = find_subsets(arr, N);
  for (size_t i = 0; i < result.size(); ++i)
    cout << result[i] << endl;
  cout << "TOTAL: " << result.size() << endl; 
  return 0;
}
