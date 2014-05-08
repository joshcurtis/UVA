#include<iostream>
#include<vector>
#include<stack>
using namespace std;

typedef vector<int> vi;

int main()
{
  int T;
  cin >> T;
  cin.ignore();
  bool first = true;
  while(T--)
  {
    if(first) first = false;
    else cout << endl;
    cin.ignore();
    int size = cin.get()-'A'+1;
    char x;

    vector<vi> edges(size);
    vector<bool> visited(size, false);
    cin.ignore();
    while(cin.peek() != '\n' && cin.good())
    {
      int a = cin.get() - 'A';
      int b = cin.get() - 'A';
      /*
	char x=a+'A', y=b+'A';
	cout << x << y << endl;*/
      cin.ignore();
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
    int sets=0;
    for(int i = 0; i < size; i++)
    {
      if(!visited[i])
      {
	sets++;
	stack<int> S;
	S.push(i);
	while(S.size())
	{
	  int src = S.top();
	  S.pop();
	  for(int j = 0; j < edges[src].size(); j++)
	  {
	    int dest = edges[src][j];
	    if(!visited[dest])
	    {
	      visited[dest] = true;
	      S.push(dest);
	    }
	  }
	}
      }
    }
    cout << sets << endl;
  }
}
