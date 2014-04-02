#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore(100, '\n');

    for(int i = 0; i < t; i++)
    {
	cin.ignore(100, '\n');
	if(i > 0)
	    cout << endl;
	string input;
	stringstream ss;
	stringstream sss;
	vector< pair<int, string> > nums;
	getline(cin, input);
	ss.str(input);
	getline(cin, input);
	sss.str(input);
	int n;
	string d;
	while(ss >> n)
	{
	    sss >> d;
	    nums.push_back(make_pair(n, d));
	}
	sort(nums.begin(), nums.end());
	for(vector< pair<int, string> >::iterator i = nums.begin(); i != nums.end(); i++)
	    cout << i->second << endl;
    }
}
