#include<iostream>
using namespace std;
int ages[100];
int main()
{
    int size;
    for(int i = 0; i < 100; i++)
	ages[i] = 0;
    for(cin >> size; size != 0; cin >> size)
    {
	int age;
	for(int i = 0; i < size; i++)
	{
	    cin >> age;
	    ages[age]++;
	}
	bool first = true;
	for(int i = 0; i < 100; i++)
	{
	    while(ages[i])
	    {
		if(!first)
		    cout << ' ';
		cout << i;
		ages[i]--;
		first = false;
	    }
	}
	cout << endl;
    }
    return 0;
}
