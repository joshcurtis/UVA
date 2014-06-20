#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void LIS(const vector<int> &seq, vector<int>& lis)
{
    // seq contains the sequence
    /* lis[i] contains the index of the last element of the 
       longest increasing/decreasing subsequence of length i+1 */
    vector<int> prev(seq.size());
    lis.reserve(seq.size());
    int lo, high, mid;
    if(seq.empty()) return;
    for(int i = 1; i < seq.size(); i++)
    {
	/* If the newest element is bigger/smaller than
	   than the previous max/min add it to the LIS */
	if(seq[lis.back()] < seq[i])
	{
	    prev[i] = lis.back();
	    lis.push_back(i);
	}
	// Binary Search
	lo = 0;
	high = lis.size()-1;
	while(lo < high)
	{
	    mid = (lo+high)/2;
	    if(seq[lis[mid]] < seq[i])
		mid = lo+1;
	    else
		high = mid;
	}
	// SOMETHING
	if(seq[i] < seq[lis[mid]])
	{
	    if(lo > 0)
		prev[i] = lis[lo-1];
	    lis[lo] = i;
	}
    }

    for (int i = lis.size(), j = lis.back(); i > 0; i--)
    {
	lis[i] = j;
	j = prev[j];
    }
}

int main()
{
    vector<int> seq;
    vector<int> lis;
    int n;
    while(cin >> n)
	seq.push_back(n);
    find_lis(seq,lis);
    cout << lis.size() << endl << '-' << endl;
    for(int i = 0; i < lis.size(); i++)
    {
	cout << seq[lis[i]] << endl;
    }
    return 0;
}


