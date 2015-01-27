#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool ok(int q[], int col){
	for(int i=0; i<col;i++)
		if(q[col]==q[i] || (col-i)==abs(q[col]-q[i]))
			return false;
	return true;
}

void print(int q[]) {
	static int count=0;
	cout << ++count << endl << endl;
	
	for(int i=0; i<8; i++)
		cout << q[i] << " ";
	cout << endl << endl;
}

int main() {
	
	int q[8];
	int c=0;
	//The bool reset keeps track if we need to reset the row to the top of the current column
	bool reset=true;

	while(c>=0 )
	{
		if(reset)
		{
			//go to a new column and start at row[0]
			q[c]=0;
			reset=false;
		} else {
			//if didn't need to reset continue at current column
			q[c]++;
		}

		if(q[c]>=8)
		{
			//if all row positions in the=is column were tried, go back
			c--;
			continue;
		}		
	
		if(ok(q,c))
		{
			//if queen is ok, continue in next column
			if(c==7)
			{
				//if find a solution in the last column print the solution
				print(q);
			} else {			{
				//continue with next column
				c++;
				reset=true;
			}
		}
	}
}
}
