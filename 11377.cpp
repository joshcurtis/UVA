#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<set>
#include<map>
using namespace std;
typedef vector<int> vi;
typedef vector<ii> vii;
const int MAX = 1e7;
int main()
{
  int N, M, K, T, Q, a,b,c;
  cin >> T;
  for(int case_num = 1; case_num <= T; case_num++)
  {
    cin >> N >> M >> K;
    N++;
    vector<bool> airports(N, false);
    vector<vi> flights(N);
    for(int i = 0; i < K; i++)
    {
      cin >> c;
      airports[c] = true;
    }
    for(int i = 0; i < M; i++)
    {
      cin >> a >> b;
      flights[a].push_back(b);
      flights[b].push_back(a);
    }
    cout << "Case " << case_num << ":" << endl;
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
      cin >> a >> b;
      int built = airports[a] ? 0 : 1;
      priority_queue<ii, vector<ii>, greater<ii> > pq;
      pq.push(ii(built, a));
      vi dist(N, MAX);
      dist[a] = built;
      while(pq.size() && a != b) // Dijkstra's
      {
	int built = pq.top().first;
	int city = pq.top().second;
	pq.pop();
	if(city == b) break;
	if(built == dist[city])
	{
	  for(vi::iterator it = flights[city].begin(); it != flights[city].end(); it++)
	  {
	    int next = *it;
	    int airport = airports[next] ? 0 : 1;
	    if(built+airport < dist[next])
	    {
	      dist[next] = built+airport;
	      pq.push(ii(dist[next], next));
	    }
	  }
	}
      }
      if(a == b) cout << 0 << endl;
      else if(dist[b] == MAX) cout << -1 << endl;
      else cout << dist[b] << endl;
    }
    cout << endl;
  }
  
}
