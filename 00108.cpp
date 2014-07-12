#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int i, j, m, n, size, sum, maxSum, A[100][100];;
    maxSum = -127*100*100;
    cin >> size;
    for( i = 0; i < size; i++)
	for( j = 0; j < size; j++)
	{
	    cin >> A[i][j];
	    if(i > 0) A[i][j] += A[i-1][j];
	    if(j > 0) A[i][j] += A[i][j-1];
	    if(i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
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

		    if(sum > maxSum) 
			maxSum = sum;
		}
	    }
	}
    }
    cout << maxSum << endl;
    return 0;
}
