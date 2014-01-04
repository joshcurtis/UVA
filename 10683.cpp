#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    char decimalTime[8];
    unsigned long long hours, minutes, seconds, fractions;
    while(cin >> decimalTime)
    {
	for(int i = 0; i < 8; i++)
	    decimalTime[i] -= '0';
	hours = 10*decimalTime[0]+decimalTime[1];
	minutes = 10*decimalTime[2]+decimalTime[3];
	seconds = 10*decimalTime[4]+decimalTime[5];
	fractions = 10*decimalTime[6]+decimalTime[7];

	//Perform conversions;
	minutes += 60 * hours;
	seconds += 60 * minutes;
	fractions += 100 * seconds;
	fractions *= 125;
	fractions /= 108;
	hours = fractions / (100 * 100 * 100);
	fractions -= hours*100*100*100;

	minutes = fractions / (100 * 100);
	fractions -= minutes * 100*100;

	seconds = fractions / 100;
	fractions -= seconds * 100;

	cout << hours << setw(2) << setfill('0') << minutes
	     << setw(2) << setfill('0') << seconds << setw(2)
	     << setfill('0') << fractions << endl;


    }
    return 0;
}
