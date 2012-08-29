/*******************************
Write a method to replace all
spaces in a string with '%20'.
You may assume that the string
sufficient space in the end of
the string to hold the
additional characters, and that
you are given the "true" length
of the string
EXAMPLE
Input: "Mr John Smith    "
Output:"Mr%20John%20Smith"
*******************************/

#include <iostream>

using namespace std;

char *replace_space(char *str)
{
  int count = 0;
  int i = 0;
  for (; str[i] != '\0'; ++i)
  {
    if (str[i] == ' ')
      count += 3;
    else
      count += 1;
  }
  for (int j = i; j >= 0 && count >= 0; --j)
  {
    if (str[j] == ' ')
    {
      str[count--] = '0';
      str[count--] = '2';
      str[count--] = '%';
    }
    else
      str[count--] = str[j];
  }
  return str;
}

int main()
{
  char ch[200];
  cin.getline(ch, 200);
  cout << replace_space(ch) << endl;
  return 0;
}
