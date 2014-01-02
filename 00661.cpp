/*
  Solution to problem 661 from UVA's online judge
 */
#include<iostream>
using namespace std;
int main()
{
    unsigned long long n,m,c;
    unsigned long long power[25];
    long long on[25];
    for(int cases = 1;;cases++)
    {
	cin >> n >> m >> c;
	unsigned long long  max = 0;
	unsigned long long current = 0;
	int x;
	if(n == 0 && m == 0 && c == 0)
	    break;
	//Get the power usage of the ith device
	for(int i = 0; i < n; i++)
	    cin >> power[i];
	//-1 idicates a device if off, a 1 indicates it is on
	for(int i = 0; i < 20; i++)
	    on[i] = -1; 
	cout << "Sequence " << cases << endl;
	for(int i = 0; i < m; i++)
	{
	    cin >> x;
	    //Subtract 1 since we're indexing at 0
	    x--;
	    //Turn the device on if it is off or vice versa and add or subtract its power usage
	    on[x] *= -1;
	    current += on[x] * power[x];
	    if(max < current)
		max = current;
	}

	if(max <= c)
	    cout << "Fuse was not blown.\nMaximal power consumption was " << max << " amperes.\n\n";
	else
	    cout << "Fuse was blown.\n\n";
    }
    return 0;
}
