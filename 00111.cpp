#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;

int LCS(const vector<int> &A, const vector<int> &B)
{
    int l = A.size();
    vector< vector<int> > lcs(l+1, vector<int>(l+1, 0));
    for(int i = 1; i <= l; i++)
	for(int j = 1; j <= l; j++)
	{
	    if(A[i] == B[j])
		lcs[i][j] = lcs[i-1][j-1] +1;
	    else
		lcs[i][j] = max( lcs[i][j-1], lcs[i-1][j]);
	}
    return lcs[l][l];
}

int main()
{
    int n, tmp;
    cin >> n;
    vector<int> correct(n+1);
    vector<int> answers(n+1);
    for(int i = 1; i <= n; i++)
    {
	cin >> tmp;
	correct[tmp] = i;
    }
    while(1)
    {
	cin >> tmp;
	if(!cin.good()) break;
	int i = 1;
	answers[tmp] = i;
	for(int i = 2; i <= n; i++)
	{
	    cin>>tmp;
	    answers[tmp] = i;
	}
	cout << LCS(correct, answers) << endl;;
    }
    return 0;
}
