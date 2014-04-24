#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

const int MAX = 0x0fffffff;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
  vvi adjMat(10, vi(10) ), pathMat(10, vi(10) );
  int nodes, src, dest, roads, road, delay, tmp,  case_num = 1;;
  while(cin >> nodes && nodes != 0)
  {
    fill(adjMat.begin(), adjMat.end(), vi(10, MAX) );

    for(int i = 0; i < nodes; i++)
      for(cin >> roads; roads--;)
      {
	cin >> road >> delay;
	adjMat[i][--road] = delay;
	pathMat[i][road] = i;
      }
    for(int k = 0; k < nodes; k++)
      for(int i = 0; i < nodes; i++)
	for(int j = 0; j < nodes; j++)
	  if( (adjMat[i][k] != MAX) && (adjMat[k][j] != MAX) && (adjMat[i][j] > adjMat[i][k] + adjMat[k][j]) )
	  {
	    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
	    pathMat[i][j] = pathMat[k][j];
	  }
    cin >> src >> dest;
    src--; dest--;
    tmp = dest;
    stack<int>  intermediate;
    intermediate.push(tmp+1);
    do
    {
      tmp = pathMat[src][tmp];
      intermediate.push(tmp+1);
    }while(tmp != src);


    cout << "Case " << case_num++ << ": Path =";
    while(intermediate.size())
    {
      cout << ' ' << intermediate.top(); intermediate.pop();
    }
    cout << "; " << adjMat[src][dest] << " second delay" << endl;
  }
  return 0;
}
