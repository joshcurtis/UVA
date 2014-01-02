/**
  Solution to problem 100 at UVA online judge
*/
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int i = 0,j = 0;
    while(cin >> i >> j)
    {
	int maxLength = 0;
	//Make sure that we start at the smaller of the 2 numbers and go to the largest
	for(int l = min(i,j); l <= max(i,j); l++)
	{
	    int len = 1;
	    int k = l;
	    while(k != 1)
	    {
		//K is odd
		if(k%2)
		    k = 3*k+1;
		//K is even
		else
		    k /= 2;

		len++;
	    }
	    if(len > maxLength)
		maxLength = len;
	}
	cout << i << ' ' <<j << ' ' << maxLength << endl;
    }
    return 0;
}
