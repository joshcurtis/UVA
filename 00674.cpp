#include<iostream>

using namespace std;

const int coins[] = {0, 1, 5, 10, 25, 50};
const int num_coins = 5;

int main()
{
    int i, j , n;
    int change[7500][num_coins+1];
    for(i = 0; i < 7500; i++)
	for(j = 0; j <= num_coins; j++)
	{
	    if(i == 0)
		change[i][j] = 1;
	    else if(j == 0)
		change[i][j] = 0;
	    else if(i - coins[j] < 0)
		change[i][j] = change[i][j-1];
	    else
		change[i][j] = change[i-coins[j]][j] + change[i][j-1];
	}
    while(cin >> n)
	cout << change[n][5] << endl;
}
