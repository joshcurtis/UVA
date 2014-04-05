#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

typedef long long ll;

ll dist[81][81];
ll feast[81][81];

int main()
{
    int C, R, Q;
    ll caseNum = 0;
    while(cin >> C >> R >> Q && (C != 0 || R != 0 || Q != 0) )
    {
	for(int i = 1; i <= C; i++)
	    for(int j = 1; j <= C; j++)
	    {
		dist[i][j] = LLONG_MAX;
		feast[i][j] = 0;
	    }

	//Read in feast dists
	for(int i = 1; i <= C; i++)
	{
	    cin >> feast[i][i];
	    dist[i][i] = 0;
	}
	
	//Calculate dists between cities
	for(int i = 1; i <= R; i++)
	{
	    ll c1, c2, cost;
	    cin >> c1 >> c2 >> cost;
	    dist[c1][c2] = dist[c2][c1] = cost;
	    feast[c1][c2] = feast[c2][c1] = max(feast[c1][c1], feast[c2][c2]);
	}

	//Floyd-Warshall
	for(int k = 1; k <= C; k++)
	    for(int i = 1; i <= C; i++)
		for(int j = 1; j <= C; j++)
		{
		    if( dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX
		        && dist[i][j]+feast[i][j] > dist[i][k]+dist[k][j] + max(feast[i][k], feast[k][j]) )
		    {
			//Since both dists will include the dist of a feast, subtract the dist of the lesser feast
			dist[j][i] = dist[i][j] = dist[i][k]+dist[k][j];
			
			//Update the largest feast on the path between i and j
			feast[j][i] = feast[i][j] = max(feast[i][k], feast[k][j]);
		    }
		}
	//Re run floyd-warshall
	for(int k = 1; k <= C; k++)
	    for(int i = 1; i <= C; i++)
		for(int j = 1; j <= C; j++)
		{
		    if( dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX
		        && dist[i][j]+feast[i][j] > dist[i][k]+dist[k][j] + max(feast[i][k], feast[k][j]) )
		    {
			//Since both dists will include the dist of a feast, subtract the dist of the lesser feast
			dist[j][i] = dist[i][j] = dist[i][k]+dist[k][j];
			
			//Update the largest feast on the path between i and j
			feast[j][i] = feast[i][j] = max(feast[i][k], feast[k][j]);
		    }
		}

	//Output
	if(caseNum>0)
	    cout << endl;
	cout << "Case #" << ++caseNum << endl;
	for(int i = 1; i <= Q; i++)
	{
	    int c1, c2;
	    cin >> c1 >> c2;
	    if(dist[c1][c2] != LLONG_MAX)
		cout << dist[c1][c2] + feast[c1][c2] << endl;
	    else
		cout << -1 << endl;
	}
    }
    return 0;
}
