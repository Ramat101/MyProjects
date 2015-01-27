#include <iostream>
#include <stdlib.h>
using namespace std; 

int main() {
    int arr[10][10] = {0}; 
    int colmSize[10] = {0};
    int sum = 0;
    int largest;

	//Make a 10X10 array
    for (int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
	       arr[i][j] = rand()%900+100; //Fills array with 3-digit numbers- btwn 100 & 1000
        }
    }

	//Find the sum of the column
    for (int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
			sum = sum + arr[i][j];
		}
		cout<<"Sum of column "<<i<<": "<<sum<<endl;
		colmSize[i] = sum;
		sum = 0;
	}
	
	largest = colmSize[0];
	//Find the column with the largest sum
	for(int i = 1; i<10; i++){
		if(largest<colmSize[i])
			largest = colmSize[i];
	}
	
	cout<<"Largest column sum has a value of: "<<largest<<endl;
			
	


return 0;
}

