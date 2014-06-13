#include<vector>
#include<stack>
#include<iostream>

using namespace std;

typedef vector<int> vi;

int LIS(const vector<int>& arr)
{
    vector<int> prev(arr.size(), -1);
    vector<int> best(arr.size(), 1);
    stack <int> S;
    for(int i = 0; i < arr.size(); i++)
	for(int j = 0; j < i; j++)
	{
	    //Change the sign to < here for LCS
	    if(arr[j] <= arr[i])
	    {
		if(best[j]+1 > best[i])
		{
		    best[i] = best[j]+1;
		    prev[i] = j;
		}
	    }
	}
    int max=0;
    int index;
    for(int i = 0; i < arr.size(); i++)
	if(best[i] > max)
	{
	    index = i;
	    max = best[i];
	}
    S.push(index);
    while(prev[index] != -1)
    {
	index = prev[index];
	S.push(index);
    }
    cout << "Max hits: " << max << endl;
    while(S.size())
    {
	cout << arr[S.top()] << endl;
	S.pop();
    }
    return max;
}

int main()
{
    int T, m;
    cin >> T;
    for(int i = 1; i <= T; i++)
    {
	vi M;
	cin >> m;
	cin.ignore();
	M.push_back(m);
	while(cin.peek() != '\n' && cin.good())
	{
	    cin >> m;
	    cin.ignore();
	    M.push_back(m);
	}
	if(i > 1) cout << endl;
	LIS(M);
    }
    return 0;
}

