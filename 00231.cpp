#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<int> vi;

int LDS(const vi& arr)
{
    vi previous(arr.size(), -1);
    vi best(arr.size(), 1);
    for(int i = 0; i < arr.size(); i++)
	for(int j = 0; j < i; j++)
	{
	    //Change the sign to < here for LCS
	    if(arr[j] >= arr[i])
	    {
		if(best[j]+1 > best[i])
		{
		    best[i] = best[j]+1;
		    previous[i] = j;
		}
	    }
	}
    int max=0;
    for(int i = 0; i < arr.size(); i++)
	if(best[i] > max)
	    max = best[i];
    return max;
}

int main()
{
    int n;
    int T=1;
    while(1)
    {
	cin >> n;
	if(n == -1) break;
	vi missiles;
	do
	{
	    missiles.push_back(n);
	    cin >> n;
	}while(n != -1);	
	if(T>1) cout << endl;
	cout << "Test #" << T++ << ":" << endl
	     << "  maximum possible interceptions: " << LDS(missiles) << endl;
    }

    return 0;
}
