/*
  Solution to 11150
 */
#include<iostream>
using namespace std;

int main()
{
    int bottles, drank;
    while(cin >> bottles)
    {
	drank = 0;
	while(bottles >= 3)
	{
	    //Drinking 3 bottles then getting 1 nets to subtracting to
	    bottles -= 2;
	    drank += 3;
	}
	//If we have 2 bottles left then we can borrow an empty one
	if(bottles == 2)
	    drank += 3;
	//If not then we can only drink what we have
	else
	    drank += bottles;
	cout << drank << endl;
    }
    return 0;
}
