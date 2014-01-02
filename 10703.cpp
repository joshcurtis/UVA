/*
  Solution to 10703
 */
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    long long w,h,n;
    long long x1,y1,x2,y2;
    bool empty[500][500];
    cout << endl;
    while(1)
    {
	cin >> w >> h >> n;
	if( w == 0 && h == 0 && n == 0)
	    break;

	//Initialize all spots to empty
	for(int i = 0; i < 500; i++)
	    for(int j = 0; j < 500; j++)
		empty[i][j] = true;

	for(int i = 0; i < n; i++)
	{
	    //Get input and find the bottom left and top right corner
	    cin >> x1 >> y1 >> x2 >> y2;
	    x1--; y1--; x2--; y2--;
	    if(x1 > x2)
		swap(x1,x2);
	    if(y1 > y2)
		swap(y1, y2);
	    //All spots in rectangle formed by those two points as not empty
	    for(int i = y1; i <= y2; i++)
		for(int j = x1; j <= x2; j++)
		    if(empty[i][j])
			empty[i][j] = false;
	}

	//Count the number of empty spots
	unsigned long long count = 0;
	for(int i = 0; i < h; i++)
	    for(int j = 0; j < w; j++)
		if(empty[i][j])
		    count++;

	if(count == 0)
	    cout << "There is no empty spots.";
	else if(count == 1)
	    cout << "There is one empty spot.";
	else
	    cout << "There are " << count << " empty spots.";
	cout << endl;
    }
    return 0;
}
