#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int q[8];	//1-D array with 8 columns
	int c = 0, i, count = 1;
	q[0] = 0;	//A queen is placed in the first column

nc: 	
	c++;	//c is now positioned at the 1st element of the array

	if (c == 8)	goto print;
	q[c] = -1;	//q[c] = row


nr:	
	q[c]++;	//Another queen is placed in [0,1]
	if(q[c] == 8)	goto back;

	//Test for conflicts
	for(int i = 0; i< c; i++)
        	if(q[i] == q[c] || (c-i) == abs(q[c] - q[i]))	goto nr;
	goto nc;


back:
	c--;
	if(c == -1)	return 0;
	goto nr;
	

print: 
	cout << endl;
	cout << "Solution #: " << count << endl;

	for(int i=0; i<=7; i++)
		cout << q[i] << " ";

	cout << endl;
	count++;
	goto back;
//	system ("pause");

	return 0;
}
