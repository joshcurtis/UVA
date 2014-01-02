#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
using namespace std;

int main()
{
    long long speed = 0;
    double distance = 0;
    string line;
    //Time elapsed
    unsigned long long elapsed = 0, current;
    while(getline(cin, line))
    {
	//Parse the current time into seconds
	current = 3600 * atoi(line.substr(0,2).c_str()) +
	          60 * atoi(line.substr(3,5).c_str()) + 
	          atoi(line.substr(6,8).c_str());

	//Calculate the distance traveled,
	distance += (current - elapsed) / (double)3600 * speed;
	elapsed = current;

	//Update the speed or output the total distance traveled
	if(line.size() > 8)
	    speed = atoi(line.substr(9).c_str());
	else
	    cout << fixed << setprecision(2) << line << ' ' << distance << " km\n";
    }
    return 0;
}
