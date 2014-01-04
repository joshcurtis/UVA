#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int cases, n;
    cin >> cases;
    while(cases--)
    {
	cin >> n;
	//Implement algorithm
	n *= 567;
	n /= 9;
	n += 7492;
	n *= 235;
	n /= 47;
	n -= 498;
	//Output tens column
	cout << abs((n/10)%10) << endl;
    }
    return 0;
}
