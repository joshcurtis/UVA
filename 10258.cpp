#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct contestant{
  int num;
  int solved;
  int time;
  bool participating;
  contestant(){
    num=solved=time=0;
    participating=false;
  }
};

bool comp(const contestant& A, const contestant& B)
{
  if(A.solved != B.solved)
    return A.solved > B.solved;
  else if(A.time != B.time)
    return A.time < B.time;
  return A.num < B.num;
}

typedef vector<int> vi;
int attempts[101][20];
int solved[101][20];
int main()
{
  int T;
  cin >> T;
  cin.ignore();
  while(T--)
  {
    vector<contestant> conts(101);
    for(int i = 0; i < conts.size(); i++)
      conts[i].num = i;
    for(int i = 1; i <= 100; i++)
    {
      fill(attempts[i], attempts[i]+20, 0);
      fill(solved[i], solved[i]+20, 0);
    }
    int c, t, p;
    char L;
    cin.ignore();
    while(cin.peek() != '\n' && cin.good())
    {
      cin >> c >> p >> t >> L;
      cin.ignore();
      conts[c].participating=true;
      if(L == 'I')
	attempts[c][p]++;
      else if(L == 'C' && !solved[c][p])
      {
	conts[c].solved++;
	conts[c].time += t + 20 * attempts[c][p];
	solved[c][p] = 1;
      }
    }
    sort(conts.begin(), conts.end(), comp);
    for(vector<contestant>::iterator it =  conts.begin(); it != conts.end(); it++)
    {
      if(it->participating)
	cout << it->num << ' ' << it->solved << ' ' << it->time << endl;
    }
    if(T) cout << endl;
  }
}
