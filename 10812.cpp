/*
  Solution to 10812
 */
#include<iostream>
using namespace std;

int main()
{
    int n, s, d;
    cin >> n;
    while(n--)
    {
	cin >> s >> d;
	//These are both twice the high score and low score
	int highScore = s+d; 
	int lowScore = s-d;
	//Check for negative scores and non integer scores
	if(highScore < 0 || lowScore < 0 || highScore%2 || lowScore%2)
	    cout << "impossible";
	else
	    cout << highScore/2 << ' ' << lowScore/2;
	cout << endl;
    }
    return 0;
}
