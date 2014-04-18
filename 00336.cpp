#include<queue>
#include<vector>
#include<map>
#include<set>
#include<iostream>
using namespace std;

int main()
{
  int num_edges;
  cin >> num_edges;
  int case_num =1;

  while(num_edges != 0)
  {
    int a,b;
    map<int, set<int> > edges;
    for(int i = 0; i < num_edges; i++)
    {
      cin >> a >> b;
      edges[a].insert(b);
      edges[b].insert(a);
    }
    cin >> a >> b;
    while(a != 0 || b != 0)
    {
      queue<int> q;
      q.push(a);
      map<int, int> seen;
      seen[a] = 0;
      int visited = 0;
      while(q.size())
      {
	visited++;
	int node = q.front(); q.pop();
	//cout << "Visit " << node << ", TTL: " << seen[node] << endl;
	if(seen[node] < b)
	  for(set<int>::iterator it = edges[node].begin(); it != edges[node].end(); it++)
	    if(seen.count(*it) == 0)
	    {
	      seen[*it] = seen[node]+1;
	      q.push(*it);
	    }
      }
      cout << "Case " << case_num++ << ": " << edges.size() - visited << " nodes not reachable from node " << a << " with TTL = " << b << ".\n";
      cin >> a >> b;
    }
    cin >> num_edges;
  }
  return 0;
}
