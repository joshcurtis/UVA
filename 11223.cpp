/*
  Solution to 11223
 */
#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string, char> decode;
void encode();

int main()
{
    int cases;
    string message;
    encode();

    cin >> cases;
    cin.ignore();
    for(int num = 1; num <= cases; num++)
    {
	getline(cin, message);
	if(num > 1)
	    cout << endl;
	cout << "Message #" << num << endl;
	for(int i = 0; i < message.size(); i++)
	{
	    //Check to see if its the start of a new word
	    if(i > 0 && message[i] == message[i-1] && message[i] == ' ')
		cout << ' ';
	    //Otherwise, get decode next character
	    else
	    {
		//find returns -1 if it fails which will only happen at the end of the string
		int space = message.find(' ', i);
		cout << decode[message.substr( i, space-i )];
		i = space == -1 ? message.size() : space;
	    }
	}
	cout << endl;
    }
}

void encode()
{
    decode[".-"] = 'A';
    decode["-..."]= 'B';
    decode["-.-."]  = 'C';
    decode["-.."] = 'D';
    decode["."] = 'E';
    decode["..-."] = 'F';
    decode["--."] = 'G';
    decode["...."] = 'H';
    decode[".."] = 'I';
    decode[".---"] = 'J';
    decode["-.-"] = 'K';
    decode[".-.."] = 'L';
    decode["--"] = 'M';
    decode["-."] = 'N';
    decode["---"] = 'O';
    decode[".--."] = 'P';
    decode["--.-"] = 'Q';
    decode[".-."] = 'R';
    decode["..."] = 'S';
    decode["-"] = 'T';
    decode["..-"] = 'U';
    decode["...-"] = 'V';
    decode[".--"] = 'W';
    decode["-..-"] = 'X';
    decode["-.--"] = 'Y';
    decode["--.."] = 'Z';
    decode["-----"] = '0';
    decode[".----"] = '1';
    decode["..---"] = '2';
    decode["...--"] = '3';
    decode["....-"] = '4';
    decode["....."] = '5';
    decode["-...."] = '6';
    decode["--..."] = '7';
    decode["---.."] = '8';
    decode["----."] = '9';
    decode[".-.-.-"] = '.';
    decode["--..--"] = ',';
    decode["..--.."] = '?';
    decode[".----."] = '\'';
    decode["-.-.--"] = '!';
    decode["-..-."] = '/';
    decode["-.--."] = '(';
    decode["-.--.-"] = ')';
    decode[".-..."] = '&';
    decode["---..."] = ':';
    decode["-.-.-."] = ';';
    decode["-...-"] = '=';
    decode[".-.-."] = '+';
    decode["-....-"] = '-';
    decode["..--.-"] = '_';
    decode[".-..-."] = '"';
    decode[".--.-."] = '@';
}
