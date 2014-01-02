#include<iostream>
using namespace std;

char keyboard[128];

void remap();

int main()
{
    //Remap the keyboard
    remap();
    char c;
    while(1)
    {
	c = cin.get();
	if(cin.eof())
	    break;
	cout << keyboard[c];
    }
    return 0;
}

void remap()
{
    for(int i = 0; i < 128; i++)
	keyboard[i] = i;
    keyboard['A'] = 'A';
    keyboard['B'] = 'V';
    keyboard['C'] = 'X';
    keyboard['D'] = 'S';
    keyboard['E'] = 'W';
    keyboard['F'] = 'D';
    keyboard['G'] = 'F';
    keyboard['H'] = 'G';
    keyboard['I'] = 'U';
    keyboard['J'] = 'H';
    keyboard['K'] = 'J';
    keyboard['L'] = 'K';
    keyboard['M'] = 'N';
    keyboard['N'] = 'B';
    keyboard['O'] = 'I';
    keyboard['P'] = 'O';
    keyboard['Q'] = 'Q';
    keyboard['R'] = 'E';
    keyboard['S'] = 'A';
    keyboard['T'] = 'R';
    keyboard['U'] = 'Y';
    keyboard['V'] = 'C';
    keyboard['W'] = 'Q';
    keyboard['X'] = 'Z';
    keyboard['Y'] = 'T';
    keyboard['Z'] = 'Z';
    keyboard['1'] = '`';
    keyboard['2'] = '1';
    keyboard['3'] = '2';
    keyboard['4'] = '3';
    keyboard['5'] = '4';
    keyboard['6'] = '5';
    keyboard['7'] = '6';
    keyboard['8'] = '7';
    keyboard['9'] = '8';
    keyboard['0'] = '9';
    keyboard['-'] = '0';
    keyboard['='] = '-';
    keyboard['['] = 'P';
    keyboard[']'] = '[';
    keyboard['\\'] = ']';
    keyboard[';'] = 'L';
    keyboard['\''] = ';';
    keyboard[','] = 'M';
    keyboard['.'] = ',';
    keyboard['/'] = '.';
}
