/*
  Solution to 11727
 */
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    int c;
    cin >> c;
    int sale[3];
    for(int t = 1; t <= c; t++)
    {
	for(int i = 0; i < 3; i++)
	    cin >> sale[i];
	sort(sale, sale + 3);
	cout << "Case " << t << ": " << sale[1] << endl;
    }
    return 0;
}
