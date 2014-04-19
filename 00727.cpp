#include<iostream>
#include<stack>
#include<cctype>
#include<string>
#include<cstdio>
using namespace std;


int main()
{
  int tn;
  cin >> tn;
  cin.ignore(100,'\n');
  int i = 0;
  while(tn--)
  {
    if(i++)
      cout << endl;
    cin.ignore(100,'\n');
    string postfix, infix;
    stack< char > s;
    while(cin.peek() != '\n'  && cin.peek() != EOF && cin.good())
    {
      char c = cin.get(); cin.ignore(100, '\n');
      if(c == '(')
	s.push(c);
      else if(c == ')')
      {
	while(s.top() != '(')
	{
	  cout << s.top();
	  s.pop();
	}
	s.pop();
      }
      else if(c == '+' || c == '-')
      {
	while(s.size() && s.top() != '(')
	{
	  cout << s.top();
	  s.pop();
	}
	s.push(c);
      }
      else if(c == '*' || c == '/')
      {
	if(s.size() && (s.top() == '*' || s.top() == '/'))
	{
	  cout << s.top();
	  s.pop();
	}
	s.push(c);
      }
      else
	cout << c;
    }
    while(s.size())
    {
      cout << s.top();
      s.pop();
    }
    cout << endl;
  }
}    


