#include<iostream>
using namespace std;

int main()
{
    int cases, divX, divY, x, y;
    cin >> cases;
    while(cases != 0)
    {
	//Get division lines
	cin >> divX >> divY;
	for(int i = 0; i < cases; i++)
	{
	    cin >> x >> y;
	    //Check for on a border
	    if(x == divX || y == divY)
		cout << "divisa" << endl;
	    //North east
	    else if(x > divX && y > divY)
		cout << "NE" << endl;
	    //South east
	    else if(x > divX && y < divY)
		cout << "SE" << endl;
	    //Sout west
	    else if(x < divX && y < divY)
		cout << "SO" << endl;
	    //North west
	    else
		cout << "NO" << endl;
	}
	cin >> cases;
    }

    return 0;
}
