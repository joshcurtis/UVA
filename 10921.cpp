/*
  Solution to 10921
 */
#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<char,int> charToDigit;
    int i = 0;
    char c;
    //Map each uppercase letter to a number
    for(c = 'A'; c <= 'O'; c++, i++)
	charToDigit[c] = 2 + i/3;
    for(char c = 'P'; c <= 'S'; c++)
	charToDigit[c] = 7;
    for(char c = 'T'; c <= 'V'; c++)
	charToDigit[c] = 8;
    for(char c = 'W'; c <= 'Z'; c++)
	charToDigit[c] = 9;

    while(1)
    {
	c = cin.get();
	if(cin.eof())
	    break;
	//If the character is an uppercase letter then output the corresponding digit
	else if(charToDigit.count(c))
	    cout << charToDigit[c];
	else
	    cout << c;
    }
    return 0;
}
