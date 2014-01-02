/*
  Solution to 739 from UVA's online judge
 */

#include<iostream>
#include<map>
using namespace std;

int main()
{
    //Assign a code for each of the letters
    string a = "AEIOUYWH";
    string b = "BPFV";
    string c = "CSKGJQXZ";
    map<char,int> code;
    for(int i = 0; i < a.size(); i++)
	code[a[i]] = 0;
    for(int i = 0; i < b.size(); i++)
	code[b[i]] = 1;
    for(int i = 0; i < c.size(); i++)
	code[c[i]] = 2;
    code['D'] = 3;
    code['T'] = 3;
    code['L'] = 4;
    code['M'] = 5;
    code['N'] = 5;
    code['R'] = 6;

    string name;
    int i;
    //Output header
    for(i = 0; i < 9; i++)
	cout << ' '; cout << "NAME"; i+=4;
    while(i++ < 34) cout << ' ';
    cout << "SOUNDEX CODE\n";
    //Get input until the end of file
    while( getline(cin, name) )
    {

	for(i = 0; i < 9; i++)
	    cout << ' ';
	 cout << name;
	//Get proper spacing
	 i += name.size();
	 while(i++ < 34)
	     cout << ' ';
	 //Output the first letter
	 cout << name[0];
	 //Keep track of the size of the code
	 int numbers = 0;
	 for(int j = 1; j < name.size() && numbers < 3; j++)
	 {
	     int prev = code[name[j-1]];
	     int current = code[name[j]];
	     if(current != prev && current != 0)
	     {
		 cout << current;
		 numbers++;
	     }
	 }
	 //Append zeroes if necessary
	 for(int j = numbers; j < 3; j++)
	     cout << '0';
	 cout << endl;
    }
    for(int i = 0; i < 19; i++)
	cout << ' '; cout << "END OF OUTPUT\n";
    return 0;
}
