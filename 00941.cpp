/*
  Solution to 00941
 */
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std;

typedef  long long ll;

int main()
{
    ll cases, permutation, factorials[21],  factorial = 1;
    string s;
    factorials[0] = 1;
    //Calculate all factorials through 20
    for(int n = 1; n <= 20; n++)
    {
	factorial *= n;
	factorials[n] = factorial; 
    }

    cin >> cases;
    while(cases--)
    {
	cin >> s >> permutation;
	sort(s.begin(),s.end());
	map<int,char> values;
	set<int> available;
	for(int i = 0; i < s.size(); i++)
	{
	    values[i]=s[i];
	    available.insert(i);
	}
	ll size, i;
	while(available.size())
	{
	    size = available.size()-1;
	    i = 0;
	    //Calculate which character to output next
	    while(permutation - (i+1) * factorials[size] >= 0)
		i++;
	    set<int>::iterator a = available.begin();
	    for(int j = 0; j < i; j++, a++);
	    //Output and delete character
	    cout << values[*a];
	    available.erase(a);
	    permutation = permutation - i*factorials[size];
	}
	cout << endl;
    }
    return 0;
}
