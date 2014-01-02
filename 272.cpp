/**
   Solution to problem 272 at UVA online judge
 */

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    //Keeps track of whether the quotation is opened or closed
    bool open = true;
    
    //Read input character by character until the end of input
    char c;
    while(1)
    {
	c = cin.get();
	if(cin.eof())
	    break;
	if(c == '"')
	{
	    if(open)
		cout << "``";
	    else
		cout << "''";
	    //The next quotation marks will come on the opposite side
	    open = !open;
	}

	else
	    cout << c;
    }
}

