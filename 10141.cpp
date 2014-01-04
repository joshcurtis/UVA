/*
  Solution to 10141
 */
#include<iostream>
#include<string>
using namespace std;
int main()
{
    //Keep track of the lower cost and high number of features
    pair<double,long long> bestProposal;
    int requirements,proposals, features;
    string best, proposal;
    double cost;

    for(int cases = 1;;cases++)
    {
	cin >> requirements >> proposals;
	cin.ignore(1);
	bestProposal.first = -1;
	if(requirements == 0 && proposals == 0)
	    break;
	//Ignore all requirements
	for(int i = 0; i < requirements; i++)
	    cin.ignore(250,'\n');
	for(int i = 0; i < proposals; i++)
	{
	    getline(cin, proposal, '\n');
	    cin >> cost >> features;
	    cin.ignore(1);
	    //Check if the current proposal has more features
	    if(features > bestProposal.first)
	    {
		bestProposal.first = features;
		bestProposal.second = cost;
		best = proposal;
	    }
	    //Check if the current proposal has the same number of features but a lower cost
	    else if(features == bestProposal.first && cost < bestProposal.second)
	    {
		bestProposal.first = features;
		bestProposal.second = cost;
		best = proposal;
	    }
	    //Ignore all requirements met
	    for(int j = 0; j < features; j++)
		cin.ignore(250,'\n');
	}
	if(cases != 1)
	    cout << endl;
	cout << "RFP #" << cases << endl << best << endl;
    }
    return 0;
}
