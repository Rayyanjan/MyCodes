#include <iostream>
#include <stack>
using namespace std;
bool Balanced(string str)
{
  stack<char> s;
  char openingBrackets[] = {'(', '[', '{'};
  char closingBrackets[] = {')', ']', '}'};

  for (int i = 0; i < str.size(); i++)
  {
    for (int i = 0; i < 3; ++i)
    {
      if (str[i] == openingBrackets[i])
      {
        s.push(str[i]);
        break;
      }
    }
    for (int i = 0; i < 3; ++i)
    {
      if (str[i] == closingBrackets[i])
      {
        if (s.empty() || s.top() != openingBrackets[i])
        {
          return false;
        }
        s.pop();
        break;
      }
    }
  }
  return s.empty();
}

int main()
{
  string input;
  cout << "Enter a string with parentheses, square brackets, and curly braces: ";
  getline(cin, input);
  if (Balanced(input))
  {
    cout << "The string is balanced." << endl;
  }
  else
  {
    cout << "The string is not balanced." << endl;
  }

  return 0;
}