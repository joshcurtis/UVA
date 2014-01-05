#include<iostream>
#include<map>
#include<string>
#include<cstdlib>
using namespace std;

//A conversion from numbers to roman numerals
map<int, string> n2r;
map<string, int> r2n;
void init();

int main()
{
    string input;
    string numerals[6] = {"CM", "CD", "XC", "XL", "IX", "IV"};
    init();
    while(cin >> input)
    {
	//Convert number to numerals
	if(isdigit(input[0]))
	{
	    int num = atoi(input.c_str());
	    //Output the largest numeral that is less than or eqaul to the number
	    for(map<int, string>::reverse_iterator i = n2r.rbegin(); i != n2r.rend(); i++)
		while(num >= i->first)
		{
		    num -= i->first;
		    cout << i->second;
		}
	}
	//Convert numerals to number
	else
	{
	    int num = 0;
	    //Find all 2 character numerals, remove them and add their value to the total
	    for(int i = 0; i < 6; i++)
	    {
		int pos = input.find(numerals[i]);
		if(pos != -1)
		{
		    num += r2n[numerals[i]];
		    input.erase(pos,2);
		}
	    }
	    //Go through the rest of the 1 character numerals and add their values
	    for(int i = 0; i < input.size(); i++)
		num += r2n[input.substr(i,1)];
	    cout << num;
	}
	cout << endl;
    }
}

void init()
{
    n2r[1] = "I";
    n2r[4] = "IV";
    n2r[5] = "V";
    n2r[9] = "IX";
    n2r[10] = "X";
    n2r[40] = "XL";
    n2r[50] = "L";
    n2r[90] = "XC";
    n2r[100] = "C";
    n2r[400] = "CD";
    n2r[500] = "D";
    n2r[900] = "CM";
    n2r[1000] = "M";
    for(map<int, string>::iterator i = n2r.begin(); i != n2r.end(); i++)
	r2n[i->second] = i->first;
}
