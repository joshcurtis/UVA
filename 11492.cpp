#include<queue>
#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<map>
#include<functional>
using namespace std;

typedef pair<int, pair<int, char> > iic;
typedef pair<int, int> ii;
typedef vector<iic> viic;
typedef vector<ii> vii;
#define TRviic(c, it) for (viic::iterator it = (c).begin(); it != (c).end(); it++)
const int INF = 0x0fffffff;

int main()
{
  int num_edges;
  string src, dest, start, end, word;
  while(cin >> num_edges && num_edges != 0)
  {
    cin >> src >> dest;
    map<string, int> mapping;
    mapping[src] = 0; mapping[dest]=1;
    int k = 2;
    vector<viic> AdjList;
    AdjList.reserve(num_edges*num_edges);
    for(int i = 0; i < num_edges; i++)
    {
      cin >> start >> end >> word;
      if(mapping.count(start) == 0)
	mapping[start] = k++;
      if(mapping.count(end) == 0)
	mapping[end] = k++;
      AdjList.resize(k);
      AdjList[mapping[start]].push_back(make_pair(mapping[end], make_pair(word.size(), word[0])));
      AdjList[mapping[end]].push_back(make_pair(mapping[start], make_pair(word.size(), word[0])));
    }
    //Dijkstra's
    vector<int> dist(k, INF); dist[0] = 0;
    priority_queue<iic , viic, greater<iic> > pq; pq.push( iic(0, make_pair(0, 0)) );
    while(!pq.empty())
    {
      iic top = pq.top(); pq.pop();
      int d = top.first;
      int u = top.second.first; 
      char prev = top.second.second;
      if(d == dist[u])
      {
	for(viic::iterator it = AdjList[u].begin(); it != AdjList[u].end(); it++)
	{
	  int v = it->first;
	  int weight = it->second.first;
	  char first = it->second.second;
	  /*
	    string uu, vv;
	    for(map<string, int>::iterator sit = mapping.begin(); sit != mapping.end(); sit++)
	    {
	    if(sit->second == u)
	    uu = sit->first;
	    if(sit->second == v)
	    vv = sit->first;
	    }
	    cout << uu << ' ' << vv << ' ' << weight << endl;*/
	  if(d + weight < dist[v] && (prev != first))
	  {
	    dist[v] = d+weight;
	    pq.push(iic(dist[v], make_pair(v, first)));
	  }
	}
      }
    }
    //Dijkstra's backwards
    vector<int> dist2(k, INF); dist2[1] = 0;
    priority_queue<iic , viic, greater<iic> > pq2; pq2.push( iic(0, make_pair(1, 0)) );
    while(!pq2.empty())
    {
      iic top = pq2.top(); pq2.pop();
      int d = top.first;
      int u = top.second.first; 
      char prev = top.second.second;
      if(d == dist2[u])
      {
	for(viic::iterator it = AdjList[u].begin(); it != AdjList[u].end(); it++)
	{
	  int v = it->first;
	  int weight = it->second.first;
	  char first = it->second.second;
	  if(d + weight < dist2[v] && (prev != first))
	  {
	    dist2[v] = d+weight;
	    pq2.push(iic(dist2[v], make_pair(v, first)));
	  }
	}
      }
    }

    if(src == dest)
      cout << 0 << endl;
    else if(dist[mapping[dest]] == INF && dist2[mapping[src]] == INF)
      cout << "impossivel" << endl;
    else
      cout << min(dist[mapping[dest]], dist2[mapping[src]]) << endl;
  }
}
