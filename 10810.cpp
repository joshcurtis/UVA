#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

template<class T>
unsigned long long merge(vector<T>& arr, const vector<T>& left, const vector<T>& right)
{
    unsigned long long inversions = 0;
    int i=0,j=0,k=0;
    while(i < left.size() && j < right.size())
    {
	if(left[i] <= right[j])
	{
	    arr[k++] = left[i++];
	}
	else
	{
	    arr[k++] = right[j++];
	    inversions += left.size() - i;
	}
    }
    while(i < left.size())
	arr[k++] = left[i++];
    while(j < right.size())
	arr[k++] = right[j++];
    return inversions;
}

template<class T>
unsigned long long mergeCount(vector<T>& arr)
{
    if(arr.size() <= 1)
	return 0;
    unsigned long long inversions = 0;
    vector<T> left(arr.begin(), arr.end()-arr.size()/2);
    vector<T> right(arr.end()-arr.size()/2, arr.end());
    inversions += mergeCount<T>(left);
    inversions += mergeCount<T>(right);
    inversions += merge<T>(arr, left, right);
    return inversions;
}

int main()
{
    int t, size;
    for(cin >> t; t != 0; cin >> t)
    {
	vector<unsigned long long> V(t);
	for(int i = 0; i < t;i++)
	    cin >> V[i];
	cout << mergeCount(V) << endl; 
    }
    return 0;
}
