/*
  solution to 10323
 */
#include<iostream>
using namespace std;

//An array with 0! through 13!
unsigned long long f[14] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600, 6227020800};

int main()
{
    int n;
    while(cin >> n)
    {
	//You really shouldn't have n less than 0 with factorials, but this problem does and this is how you deal with them.
	if(n < 0)
	    if(-n%2==1)
		cout << "Overflow!\n";
	    else
		cout << "Underflow!\n";
	else if(n < 8)
	    cout << "Underflow!\n";
	else if(n > 13)
	    cout << "Overflow!\n";
	else
	    cout << f[n] << endl;
    }    
    return 0;
}
