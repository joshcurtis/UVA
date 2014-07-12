#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int T, i, j, m, n, size, sum, area, maxArea, A[25][25];
    string line;
    cin >> T;
    cin.ignore(100, '\n');
    for(int t = 0; t < T; t++)
    {
	maxArea = 0;
	size = 1;
	cin.ignore(100, '\n');	
	for(i = 0; i < size; i++)
	{
	    getline(cin, line);
	    size = line.size();
	    for( j = 0; j < size; j++)
	    {
		A[i][j] = line[j]-'0';
		if(i > 0) A[i][j] += A[i-1][j];
		if(j > 0) A[i][j] += A[i][j-1];
		if(i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
	    }
	}
	for(i = 0; i < size; i++)
	{
	    for( j = 0; j < size; j++)
	    {
		for(m = i; m < size; m++)
		{
		    for(n = j; n < size; n++)
		    {
			sum = A[m][n];
			if(i > 0) 
			    sum -= A[i-1][n];
			if(j > 0) 
			    sum -= A[m][j-1];
			if(i > 0 && j > 0) 
			    sum += A[i-1][j-1];
			area = (m-i+1)*(n-j+1);
			if(area == sum)
			    if(area > maxArea)
				maxArea = area;
		    }
		}
	    }
	}
	if(t> 0) 
	    cout << endl;
	cout << maxArea << endl;
    }
    return 0;
}
