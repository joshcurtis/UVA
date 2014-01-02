#include<iostream>
#include<string>
#include<map>
#include<sstream>
using namespace std;

int main()
{
    map<string, int> notes;
    //Assign each key a numerical value
    notes["C"] = 0;
    notes["C#"] = 1;
    notes["D"] = 2;
    notes["D#"] = 3;
    notes["E"] = 4;
    notes["F"] = 5;
    notes["F#"] = 6;
    notes["G"] = 7;
    notes["G#"] = 8;
    notes["A"] = 9;
    notes["A#"] = 10;
    notes["B"] = 11;

    map<int,string> numToKey;
    for(map<string, int>::iterator i = notes.begin(); i != notes.end(); i++)
	numToKey[i->second] = i->first;
    string n;
    string note;
    bool key[12];

    while(1)
    {
	//Initialize each key to be allowable
	for(int i = 0; i < 12; i++)
	    key[i] = true;

	getline(cin , n);
	if(n == "END" || n == "END\n")
	    break;
	istringstream s(n);

	//Disallow the keys 2,4,6,11, and 9 half-steps away from a note
	while(s >> note)
	    key[ (notes[note]+2)%12 ] =  key[ (notes[note]+4)%12 ] = key[ (notes[note]+6)%12 ] = key[ (notes[note]+11)%12 ] = key[ (notes[note]+9)%12 ] = false;

	//Output allowable keys
	for(int i = 0; i < 12; i++)
	    if(key[i])
	    {
		if(i > 0)
		    cout << ' ';
		cout  << numToKey[i];
	    }

	cout << endl;
    }
    return 0;
}
