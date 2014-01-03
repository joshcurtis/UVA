/*
  Solution to 837
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

//Point struct
struct line{
    double left;
    double right;
    double coef;
};

int main()
{
    cout << fixed << setprecision(3); 
    int cases, numLines;

    cin >> cases;
    while(cases)
    {
	cases--;
	cin >> numLines;
	vector<line> lines(numLines);
	vector<double> points;
	points.reserve(2*numLines);
	for(int i = 0; i < numLines; i++)
	{
	    //Ignore the y coordinates since they aren't necesseary
	    cin >> lines[i].left >> lines[i].right >> lines[i].right >> lines[i].coef >> lines[i].coef;
	    if(lines[i].left > lines[i].right)
		swap(lines[i].left, lines[i].right);
	    points.push_back(lines[i].left);
	    points.push_back(lines[i].right);
	}
	//Sort points by x coordinate
	sort(points.begin(), points.end());


	//If there are n lines there are 2n+1 regions since each point is distinct
	cout << points.size()+1 << endl;
	for(int i = 0; i <= points.size(); i++)
	{
	    //First region
	    if(i == 0)
		cout << "-inf " << points[i] << " 1.000" << endl;
	    //Last region
	    else if(i == points.size())
		cout << points[i-1] << " +inf 1.000" << endl;
	    else
	    {
		double coef = 1;
		//Go through each line, If part of it is in the region then apply it's coefficient
		for(int j = 0; j < lines.size(); j++)
		    if(lines[j].left <= points[i-1] && lines[j].right >= points[i])
			coef *= lines[j].coef;
		cout << points[i-1] << ' ' << points[i] << ' ' << coef << endl;
	    }
	}

	if(cases > 0)
	    cout << endl;
    }
    return 0;
}
