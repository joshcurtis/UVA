/*
  Solution to 00941
 */
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

typedef  long long ll;

int main()
{
    ll cases, permutation, factorials[21],  f = 1;
    string s;

    //Calculate all factorials through 20
    factorials[0] = 1;
    for(int i = 1; i <= 20; i++)
    {
	f *= i;
	factorials[i] = f; 
    }

    cin >> cases;
    while(cases--)
    {
	cin >> s >> permutation;
	sort(s.begin(),s.end());
	while(s.size())
	{
	    int i = 0;
	    //Subtract (size-1)! until it is less than the permutation we want
	    while(permutation >= factorials[s.size()-1])
	    {
		permutation -= factorials[s.size()-1];
		i++;
	    }
	    cout << s[i];
	    s.erase(s.begin()+i);
	}
	cout << endl;
    }
    return 0;
}
