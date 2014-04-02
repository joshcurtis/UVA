#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

bool myComp(pair<int, string> A, pair<int, string> B)
{
    return A.first < B.first;
}

int main()
{
    int t, size, numStrings;
    string seq;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
	if(i > 0)
	    cout << endl;
	cin >> size >> numStrings;
	vector< pair< int, string > > V(numStrings);
	for(int j = 0; j < numStrings; j++)
	{
	    cin >> seq;
	    int inversions = 0;
	    for(int x = 0; x < seq.size()-1; x++)
		for(int y = x+1; y < seq.size(); y++)
		    if(seq[x] > seq[y])
			inversions++;
	    V[j] = make_pair(inversions, seq);
	}
	stable_sort(V.begin(), V.end(), myComp);
	for(int j = 0; j < V.size(); j++)
	    cout << V[j].second << endl;
    }
    return 0;
}

