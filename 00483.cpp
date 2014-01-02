/**
   A solution to problem 483 from UVA's online judge
 */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    char c;
    string s;
    s.reserve(10000);

    //Get input until end of file is detected
    while(1)
    {
	s.resize(0);
	c = cin.get();
	if(cin.eof())
	    break;
	if(isspace(c))
	    cout << c;
	else
	{
	    //Get characters until a space or end of file is detected
	    do
		s.push_back(c);
	    while( !isspace(c = cin.get()) && !cin.eof() );

	    //Reverse and output the string
	    reverse(s.begin(),s.end());
	    cout << s;
	    s.resize(0);
	    if(cin.eof())
		break;

	    //Output the space
	    cout << c;
	}
    }
    return 0;
}
