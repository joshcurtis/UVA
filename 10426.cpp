#include<cstdio>
#include<queue>
#include<set>
#include<array>
#include<tuple>
using namespace std;

typedef pair<char, char> cc;          
typedef array<cc, 4> acc;
const char X[] = {1, 1, -1, -1, 2, 2, -2, -2};
const char Y[] = {2, -2, 2, -2, 1, -1, 1, -1};

int bfs(const acc& initial, const cc& monter, const char r, const char c);
bool met(const acc& pos);

int main()
{
  int set_num, r, c,x,y, minutes=0;
  acc board;
  while(scanf("Set#%d\n", &set_num) != EOF)
  {
    scanf("%d %d\n", &r, &c);
    for(int i = 0; i < 4; i++)
    {
      scanf("%d %d", &x, &y);
      board[i] = make_pair((char)x, (char)y);
    }
    scanf("\n%d %d\n", &x, &y);
    cc monster =  make_pair((char)x, (char)y);
    minutes = bfs(board, monster, r, c);
    printf("Set#%d\n", set_num);
    if(minutes >= 0)
      printf("Minimum time required is %d minutes.\n", minutes);
    else
      printf("Meeting is impossible.\n");
  }
}

int bfs(const acc& board, const cc& monster, const char r, const char c)
{
  //Keep track of the knight positions, whether or not the monster is awake, and the number of moves made
  queue<tuple<acc, bool, int> > q;
  set<acc> seen;
  seen.insert(board);
  q.push(make_tuple(board, false, 0));
  while(q.size())
  {
    acc pos = get<0>(q.front());
    bool awake = get<1>(q.front());
    int moves = get<2>(q.front());
    q.pop();
    if( met(pos) )
      return moves;
    moves++;
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 8; j++)
      {
	acc new_pos = pos;
	new_pos[i].first += X[j];
	new_pos[i].second += Y[j];
	//Bounds check
	if(new_pos[i].first < 1 || new_pos[i].first >= r||new_pos[i].second < 1||new_pos[i].second >= c)
	  continue;
	if(seen.count(new_pos) == 0)
	{
	  if(new_pos[i].first == monster.first && new_pos[i].second == monster.second)
	  {
	    if(awake)
	      continue;
	    else
	      awake = true;
	  }
	  seen.insert(new_pos);
	  q.push(make_tuple(new_pos, awake, moves));
	}
      }
  }
  return -1;
}

bool met(const acc& board)
{
  for(int i = 0; i < 3; i++)
    if(board[i].first != board[i+1].first || board[i].second != board[i+1].second)
      return false;
  return true;
}
