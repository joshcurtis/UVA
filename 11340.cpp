#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    string line;
    char dummy;
    long long val, total, cases, lines;
    cin >> cases;
    while(cases--)
    {
	map<char, long long> values;
	total = 0;
	cin >> lines;
	cin.ignore();//Ignore trailing \n

	//Get pair characters and values
	while(lines--)
	{
	    dummy = cin.get();
	    cin >> val;
	    values[dummy] = val;
	    cin.ignore();//Ignore trailing \n

	}
	cin >> lines;
	cin.ignore();//Ignore trailing \n

	//Iterate through the lines character by character
	while(lines--)
	{
	    getline(cin, line);
	    for(string::iterator s = line.begin(); s != line.end(); s++)
		if(values.count(*s))
		    total += values[*s];
	}
	cout << total / 100 << '.' << (total/10)%10 << total %10 << '$' << endl;
    }
    return 0;
}
