#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 1e8;
int T, F, I;

int dijkstra(vector<vii>& AL, const vector<bool> stations, const int new_station, const int src)
{
  vector<int> dist(I, INF);
  dist[src] = 0;
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  pq.push(ii(0, src));
  while(pq.size())
  {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if(stations[u] || u == new_station)
      return dist[u];
    if(d == dist[u])
      for(vii::iterator it = AL[u].begin(); it != AL[u].end(); it++)
      {
	int w = it->first;
	int v = it->second;
	if(dist[v] > d+w)
	  pq.push(ii(dist[v]=d+w, v));
      }
  }
  return INF;
}

int main()
{
  bool first = true;
  for(cin>>T; T--;)
  {
    cin >> F >> I;
    vector<bool> stations(I, false);
    vector<vii> AL(I);
    for(int i = 0,s; i < F; i++)
    {
      cin >> s;
      s--;
      stations[s] = true;
    }
    cin.ignore(100, '\n');
    while(cin.peek() != '\n' && cin.good())
    {
      int a,b,w;
      cin >> a >> b >> w;
      cin.ignore(100, '\n');
      a--;
      b--;
      AL[a].push_back(ii(w,b));
      AL[b].push_back(ii(w,a));
    }
    int new_station=1, dist,  min_max = INF;
    for(int i = 0; i < I; i++)
    {
      if(!stations[i])
      {
	dist = -1;
	for(int j = 0; j < I; j++)
	  if(!stations[j] && i != j)
	  {
	    int d = dijkstra(AL, stations, i, j);
	    dist = max(dist, d);
	  }
	if(dist < min_max)
	{
	  min_max = dist;
	  new_station = i+1;
	}
      }
    }
    if(first) first = false;
    else cout << endl;
    cout << new_station << endl;
  }
  return 0;
}



