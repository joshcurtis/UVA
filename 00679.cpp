/**
   Solution to 679 at UVA online judge
 **/
#include<iostream>
#include<bitset>

using namespace std;

int main()
{
    int cases, depth, drops, dummy;
    cin >> cases;
    while(cases--)
    {
	cin >> depth >> drops;
	//The number of possibilties cannot exceed 2^depth
	drops %= (1 << depth);
	//Start at the top of the tree
	int pos = 1;
	for(int i = 1; i < depth; i++)
	{
	    /*
	      Decide at each depth whether the ball will go left or right

	      If the number of drops remaining is odd then the ball will drop left. Otherwise it will go to the right.
	      
	      Since the root is called 1, the left subchild is at 2*index and the right index is 2*index + 1;
	     */
	    pos *= 2;
	    if(drops % 2 == 0)
		pos++;
	    //Adding one to the number of drops if we go down the left subtree makes the arithmetic work
	    else
		drops++;
	    drops /= 2;
	}
	cout << pos << endl;
    }
    //Read in the negative one at the end of the file to avoid any weird errors from leaving input unread.
    cin >> dummy;
}

