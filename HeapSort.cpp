#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void bubbleDown(int array[]){
		int fatherIndex = 1; //step 10.1
		int last = array[0];
		int smallKid = 0;
		int leftKid, rightKid, temp;
		while (true){
			//step 10.2
			leftKid = fatherIndex * 2;
			rightKid = (fatherIndex *2)+1;
			//step 10.3 - find smallKid
			//case 1 - father has both left and right kids
			if (rightKid <= last){ //won't go out of bounds
				if (array[leftKid] < array[rightKid])
					smallKid = leftKid;
				else
					smallKid = rightKid;
			} //if
			//case 2 - father has only leftKid
			else if ((leftKid <= last) && (rightKid>last)){
				smallKid = leftKid;
			}//else if
			if ((leftKid>last && rightKid > last) || (array[fatherIndex] <= array[smallKid]))
				return;
			//step 10.4 - array[fatherIndex]
			if((smallKid <= last) && (array[smallKid] < array[fatherIndex])){
				temp = array[fatherIndex];
				array[fatherIndex] = array[smallKid];
				array[smallKid] = temp;
			//	swap(array, smallKid, fatherIndex);
				fatherIndex = smallKid;
			}//if
		}//while
} //BubbleDown

void BubbleUp(int array[]){
		int	kidIndex = array[0]; //step 5.1
		int	fatherIndex, temp;
			while(true){
				fatherIndex = kidIndex/2; //step 5.2
				if((kidIndex == 1) || (array[fatherIndex] <= array[kidIndex]))
					return;
				if(array[kidIndex] < array[fatherIndex]){ //step 5.3
					temp = array[fatherIndex];
					array[fatherIndex] = array[kidIndex];
					array[kidIndex] = temp;
					kidIndex = fatherIndex;
				}//if
			}//while
}//BubbleUp

int main(int argc, char* argv[]){
	int parameter = 0, data = 0, last = 0, count = 0, first = 1, index = 1;
	ifstream inFile;

	cout<<"Enter the index of the argument of your data file: "<<endl;
	cin>>parameter;
	inFile.open(argv[parameter]);
	while(inFile>>data)
 		count++;
	inFile.close();
	
	int* array = new int[count]; //step 4
	inFile.open(argv[parameter]);

	//Build the Heap
	while(inFile>>data){ //step 6 & 2
		last++; //step 3
		array[0] = last;
		array[last] = data;
		BubbleUp(array); //step 5 
	}//while
	inFile.close(); //step 7
	
	cout<<"Unsorted:"<<endl;
	for(int i = 0; i<count+1; i++)
		cout<<"array["<<i<<"]="<<array[i]<<", ";
	cout<<endl<<endl<<"Sorted: "<<endl;
	while(last != 0){
		//Delete the Heap
		cout<<"array["<<index<<"]="<<array[first]<<", "; //step 8
		array[first] = array [last]; //step 9
		last--;
		bubbleDown(array);
		index++;
	}
	
	return 0;
}
