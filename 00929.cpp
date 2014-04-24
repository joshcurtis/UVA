#include<cstdio>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
const int dx[] ={0, 0, -1, 1}, dy[] ={1, -1, 0, 0};

int main()
{
  int tn, N, M, d,i, j, n, m;
  ii u, v;
  int maze[1000][1000], dist[1000][1000];
  for(scanf("%d\n", &tn); tn--;)
  {
    scanf("%d\n%d\n", &N, &M);
    for(i = 0; i < N; i++)
      for(j = 0; j < M; j++)
      {
	scanf("%d", &maze[i][j]);
	dist[i][j] = INF;
      }
    //Dijkstra's
    dist[0][0] = maze[0][0];
    priority_queue<iii, vector<iii>, greater<iii> > pq;
    pq.push(iii(dist[0][0], ii(0,0)));
    while(pq.size())
    {
      d = pq.top().first;
      ii u = pq.top().second;
      if(u.first == N-1 && u.second == M-1)
	break;
      pq.pop();
      if(d == dist[u.first][u.second])
      {
	for(j = 0; j < 4; j++)
	{
	  n = u.first+dx[j];
	  m = u.second+dy[j];
	  if(n >= 0 && n < N && m >= 0 && m < M)
	    if(dist[n][m] > dist[u.first][u.second] + maze[n][m])
	    {
	      dist[n][m] = dist[u.first][u.second] + maze[n][m];
	      pq.push(iii(dist[n][m], ii(n, m)));
	    }
	}
      }
    }
    printf("%d\n",dist[N-1][M-1]);
  }

}
