/*
  Solution to 594.cpp at UVA's online judge
 */
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int i;
    //Assigns a pointer the size of a byte to the address of i. 
    //This will allow swapping to take place within the integer.
    char* c = (char*)&i;
    while(cin >> i)
    {
	cout << i << " converts to ";
	//Swap the 0th and 3rd byte
	swap(c[0],c[3]);
	//Swap the 1st and 2nd byte
	swap(c[1],c[2]);
	cout << i << endl;
    }
    return 0;
}
