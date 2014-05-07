#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class country{
public:
  string name;
  int wins;
  int losses;
  int ties;
  int goalsAgainst;
  int goalsFor;
  country(){
    wins = losses = ties = 0;
    goalsFor = goalsAgainst = 0;
  }
};

bool myComp(const country& A, const country& B)
{
  int a, b, agd, bgd, agp, bgp;
  string aname, bname;
  a = 3*A.wins+A.ties;
  b = 3*B.wins+B.ties;
  agd = A.goalsFor - A.goalsAgainst;
  bgd = B.goalsFor - B.goalsAgainst;
  agp = A.wins+A.losses+A.ties;
  bgp = B.wins+B.losses+B.ties;
  if(a != b)
    return a > b;
  else if(A.wins != B.wins)
    return A.wins > B.wins;
  else if(agd != bgd)
    return agd > bgd;
  else if(A.goalsFor != B.goalsFor)
    return A.goalsFor > B.goalsFor;
  else if(agp != bgp)
    return agp < bgp;
  else
  {
    aname = A.name;
    bname = B.name;
    for(int i = 0; i < aname.size(); i++)
      aname[i] = tolower(aname[i]);
    for(int i = 0; i < bname.size(); i++)
      bname[i] = tolower(bname[i]);
    return aname < bname;
  }      
}

int main()
{
  int N, T, G;
  cin >> N;
  cin.ignore();
  bool first=true;
  while(N--)
  {
    string title;
    getline(cin, title, '\n');
    cin >> T;
    cin.ignore();
    vector<country> countries(T);
    map<string, int> c_num;
    for(int i = 0; i < T; i++)
    {
      getline(cin, countries[i].name, '\n');
      c_num[countries[i].name] = i;
    }
    cin >> G;
    cin.ignore();
    for(int i = 0; i < G; i++)
    {
      int c1,c2,g1,g2;
      string tmp;
      getline(cin, tmp, '#');
      c1 = c_num[tmp];
      getline(cin, tmp, '@');
      g1 = stoi(tmp);
      getline(cin, tmp, '#');
      g2 = stoi(tmp);
      getline(cin, tmp, '\n');
      c2 = c_num[tmp];
      countries[c1].goalsFor+=g1;
      countries[c2].goalsFor+=g2;
      countries[c1].goalsAgainst+=g2;
      countries[c2].goalsAgainst+=g1;
      if(g1 > g2)
      {
	countries[c1].wins++;
	countries[c2].losses++;
      }
      else if(g2 > g1)
      {
	countries[c1].losses++;
	countries[c2].wins++;
      }
      else
      {
	countries[c1].ties++;
	countries[c2].ties++;
      }
    }
    sort(countries.begin(), countries.end(), myComp);
    int k = 1;
    if(!first) cout << endl;
    else first = false;
    cout << title << endl;
    for(vector<country>::iterator it = countries.begin(); it != countries.end(); it++)
    {
      cout << k++ << ") " << it->name << " " << 3*it->wins+it->ties << "p, "
	   << it->wins+it->losses+it->ties << "g ("<<it->wins << "-" << it->ties << "-" << it->losses << "), "
	   << it->goalsFor - it->goalsAgainst << "gd (" << it->goalsFor << "-" << it->goalsAgainst << ")" << endl;
    }

  }
}
