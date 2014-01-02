/**
   Solution to 10420
 */
#include<iostream>
#include<map>
#include<set>
using namespace std;

int main()
{
    int n;
    //The key is a country associated with the set of conquests in that country
    map<string, set<string> > conquest;
    string country;
    string name;
    cin >> n;
    while(n--)
    {
	cin >> country;
	if(cin.eof())
	    break;
	//Get the conquest's name and store it in with the country
	getline(cin,name);
	conquest[country].insert(name);
    }
    //Output the countries and number of conquests in alphabetical order
    for(map<string, set<string> >::iterator i = conquest.begin(); i!= conquest.end(); i++)
	cout << i->first << ' ' << i->second.size() << endl;
    return 0;
}
