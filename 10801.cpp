#include<iostream>
#include<functional>
#include<vector>
#include<queue>
#include<sstream>
#include<array>
using namespace std;
typedef array<int, 3> a3;

const int MAX = 1e9;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int dijkstra(const int dest, const vector<vii> adjList, const vi times)
{
  vector<int> dist(100, MAX);
  dist[0] = 0;
  priority_queue<a3, vector<a3>, greater<a3> > pq;
  a3 state;
  state[0]=0;
  state[1]=0;
  state[2]=-1;
  pq.push(state);
  while(!pq.empty())
  {
    int d = pq.top()[0];
    int floor = pq.top()[1];
    int elevator = pq.top()[2];
    pq.pop();
    if(floor == dest) break;
    if(d == dist[floor])
    {
      for(vii::const_iterator it = adjList[floor].begin(); it != adjList[floor].end(); it++)
      {
	int next = it->first;
	int new_elevator = it->second;
	int wait = times[new_elevator] * (abs(floor-next))+d;
	if(new_elevator != elevator)
	  wait += 60;
	if(wait<dist[next])
	{
	  state[0] = dist[next] = wait;
	  state[1] = next;
	  state[2] = new_elevator;
	  pq.push(state);
	}
      }
    }
  }
  return dist[dest];
}

int main()
{
  int n,k, floor;
  string floorz;
  while(cin >> n >> k)
  {
    vi elevators(n);
    vector<vii> adjList(100);
    for(int i = 0;i<n; i++)
      cin >> elevators[i];

    cin.ignore();
    for(int i = 0; i < n; i++)
    {
      getline(cin, floorz, '\n');
      stringstream ss(floorz);
      vector<int> floors;
      while(ss >> floor)
	floors.push_back(floor);
      for(int j = 0; j < floors.size()-1; j++)
      {
	for(int k = j+1; k < floors.size(); k++)
	{
	  int wait = elevators[i] * (floors[k]-floors[j]);
	  adjList[floors[j]].push_back(ii(floors[k], i));
	  adjList[floors[k]].push_back(ii(floors[j], i));
	}
      }
    }
    int d = dijkstra(k, adjList, elevators);
    if(d == MAX)
      cout << "IMPOSSIBLE" << endl;
    else if(k == 0)
      cout << 0 << endl;
    else
      cout << d-60 << endl;
  }
  return 0;
}
