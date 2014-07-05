#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

void find_min_sum(vector<int>& collection, vector<int>& min_sum)
{
    vector<int>::iterator C;
    int i;
    min_sum[0] = 0;
    fill(min_sum.begin()+1, min_sum.end(), INT_MAX);
    for(C = collection.begin(); C != collection.end(); C++)
	for(i = 10000-*C; i >= 0; i--)
	    if(min_sum[i] != INT_MAX)
		if(min_sum[i]+1 < min_sum[i+*C])
		    min_sum[i+*C] = min_sum[i]+1;
}

int main()
{
    int cases, cost, n, i;
    vector<int> collection(101);
    vector<int> min_sum(10001, 0);
    cin >> cases;
    while(cases--)
    {
	cin >> cost >> n;
	collection.resize(n);
	for(i = 0; i < n; i++) 
	    cin >> collection[i];
	find_min_sum(collection, min_sum);
	for(i = cost; min_sum[i] == INT_MAX; i++);
	cout << i << ' ' << min_sum[i] << endl;
    }
}
