/*
Solutiont to 11044
 */
#include<iostream>
using namespace std;

int main()
{
    int cases;
    cin  >> cases;
    unsigned long long height, width;
    while(cases--)
    {
	cin >> height >> width;
	//Divisions have to happen first so that the result truncates
	cout << (height / 3) * (width / 3) << endl;
    }
    return 0;
}
