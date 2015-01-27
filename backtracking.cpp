#include <iostream>
using namespace std;

void print(int board[][8], int size){
  for(int i=0; i<=7; i++){
	for (int j=0; j<=7; j++){
		cout << board[i][j];
	}
	cout << endl;
   }
   cout << endl;

}

int main() {

	int board[8][8]={0};
	int r, c=0, size=8;  		  //creates an 8x8 array filled with zeroes
	board[0][0]=1;		 //places first queen in top left corner
	nc: c++;		//move to next column so c = 1. Labels a command "nc" to be used for backtracking
	if (c==8)
		goto print;

	r=-1;
	nr: r++;		//r becomes zero
	if(r==8)
		goto backtrack;

	//Row Test:
	for(int i=0; i<c; i++)
		if(board[r][i]==1)
		goto nr;

	//Up-diagonal Test
	for(int i=1; (r-i)>=0 && (c-i)>=0; i++)
		if(board[r-i][c-i]==1)
			goto nr;

	//Down-Diagonal Test
	for(int i=1; (r+i)<=7 && (c-i)>=0; i++) 
		if(board[r+i][c-i]==1)
			goto nr;
	
	board[r][c]=1;
	goto nc;
	
        backtrack:c--;
	for(r=0; r<=7; r++){
		if(board[r][c]==1){
			board[r][c]=0;
			goto nr;
		}
	}

	print: while(c!=-1){
		print(board, size);
		goto backtrack;
	}

return 0;
}
