/*******************************
Implement a function
void reverse(char *str) in C/C++
which reverses a null-terminated
string
*******************************/

#include <iostream>

using namespace std;

void reverse(char *str)
{
  int count = 0;
  for (int i = 0; str[i] != '\0'; ++i)
    ++count;
  for (int i = 0; i < count / 2; ++i)
  {
    char temp = str[i];
    str[i] = str[count - 1 - i];
    str[count - 1 - i] = temp;
  }
  cout << str << endl;
}

int main()
{
  char ch[200];
  cin.getline(ch, 200);
  reverse(ch);
  return 0;
}
