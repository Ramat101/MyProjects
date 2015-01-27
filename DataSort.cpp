//step 0
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	int parameter;
	cout<<"Enter the index of the argument of your data file: "<<endl;
	cin>>parameter;	
    ifstream inFile;
    inFile.open(argv[parameter]);

	//step 1
	int position = 0;
	int walker = position;
	int smallest = position;
	int temp = 0;
	int iteration = 1;
	int index = 0;
	int count = 0; 
	int dataIn;

	//find out how many integers are in the file
	while(inFile>>dataIn)
		count++; 
	
	int* array = new int[count];
	inFile.close();
	inFile.open(argv[parameter]);

	//fill array with integers read in from the file
	while(inFile>>dataIn){
		array[index] = dataIn;
		index++;
	}//while

	cout<<"Unsorted Array from File: "<<endl;
	for (int i = 0; i < count; i++)    
   		cout<<"["<<i<<"]:"<<array[i]<<",  ";		
	cout<<endl;

	while(position < count -1){//step 6
		while(walker<count-1){//step 3
			walker++;
			if(array[walker]<array[smallest])
		   		smallest = walker;
		}//while2
		//step 4	
		cout<<endl<<"Iteration #"<<iteration<<": Position Index = "<<position<<" , Min Index = "<<smallest<<endl;
		iteration++;
		//swap
		temp = array[position];
		array[position]= array[smallest];
		array[smallest] = temp;
		position++;
		cout<<"Swapped Array: "<<endl;
		for (int i = 0; i < count; i++)    
   		cout<<"["<<i<<"]:"<<array[i]<<",  ";		
		cout<<endl;
		//step5
		walker = position;
		smallest = position;
	}//while1

	//step 8
	cout<<endl<<"Final Array: "<<endl;
	for (int i = 0; i < count; i++)    
   		cout<<"array["<<i<<"]:"<<array[i]<<endl;		

	return 0; 
}
