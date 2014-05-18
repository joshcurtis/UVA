#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<functional>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;


long long dijkstra(vector<vii>& servers, ll src, ll dest)
{
  vector<ll> dist(servers.size(), LLONG_MAX);
  dist[src] = 0;
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  pq.push(ii(0, src));
  while(pq.size())
  {
    ll u = pq.top().second;
    ll d = pq.top().first;
    pq.pop();
    if(dist[u] == d)
    {
      if(u == dest)
	return dist[u];
      for(vii::iterator it = servers[u].begin(); it != servers[u].end(); it++)
      {
	ll v = it->first;
	d = it->second;
	if(dist[v] > dist[u]+d)
	{
	  dist[v] = dist[u]+d;
	  pq.push(ii(dist[v], v));
	}
      }
    }
  }
  return -1;
}

int main()
{
  ll N;
  cin >> N;
  for(ll t = 1; t <= N; t++)
  {
    ll n, m, S, T, a, b, d;
    cin >> n >> m >> S >> T;
    vector<vii> servers(n);
    for(ll i = 0; i < m; i++)
    {
      cin >> a >> b >> d;
      servers[a].push_back(ii(b,d));
      servers[b].push_back(ii(a,d));
    }
    ll dist = dijkstra(servers, S, T);
    cout << "Case #" << t << ": ";
    if(dist == -1) cout << "unreachable" << endl;
    else cout << dist << endl;
  }
  return 0;
}
