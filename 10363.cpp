#include<iostream>
using namespace std;

int main()
{
    char board[3][3];
    char X = 'X', O = 'O';
    bool xWin, oWin;
    int cases, x, o;
    cin >> cases;
    while(cases--)
    {
	x = o = 0;
	xWin = oWin = false;
	//Read input
	for(int i = 0; i < 3; i++)
	    for(int j = 0; j< 3; j++)
	    {
		cin >> board[i][j];
		if(X == board[i][j])
		    x++;
		else if(O == board[i][j])
		    o++;
	    }
	//Check to see if X or O has won the game
	for(int i = 0; i < 3; i++)
	    if( (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == X) ||
		(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == X) ||
		(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == X) || 
		(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] == X ) )
		xWin = true;
	for(int i = 0; i < 3; i++)
	    if( (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == O) ||
		(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == O) ||
		(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == O) || 
		(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] == O ) )
		oWin = true;

	//Check if both x and o have won
	if(xWin && oWin)
	    cout << "no" << endl;
	//Check if board is valid if X has won
	else if(xWin && x - o != 1)
	    cout << "no" << endl;
	//Check if board is valid if O has won
	else if(oWin && x - o != 0)
	    cout << "no" << endl;
	//Check if board is valid if neither has won
	else if( (o-x > 0) || (x-o > 1) )
	    cout << "no" << endl;
	//The board is valid
	else
	    cout << "yes" << endl;
    }
}
