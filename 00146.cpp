#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main()
{
    string input;
    while(cin >> input)
    {
	if(input == "#")
	    break;
	//Output the next permutation of the string if it exists
	if( next_permutation(input.begin(), input.end()) )
	    cout << input << endl;
	else
	    cout << "No Successor" << endl;
    }
}
