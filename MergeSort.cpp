#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
	int parameter1 = 0, parameter2 = 0, tempA = 0, tempB = 0, tempC = 0;
	ifstream inFile1, inFile2;
	string path = " ";
	cout<<"Enter the argument index of where the first file is loaded: "<<endl;
	cin>>parameter1;
	inFile1.open(argv[parameter1]);
	cout<<"Enter the argument index of where the second file is loaded: "<<endl;
	cin>>parameter2;
	inFile2.open(argv[parameter2]);
		
	 while(inFile1>>tempA){
	  	if(inFile1>>tempB);
	  	else{
	  	  tempC = tempA;
	  	  tempA = tempB;
	  	  tempB = tempC;
	  	}
	  	if(tempA > tempB){
	  	  cout<<"Only sorted files can be merged."<<endl;
	  	  return 0;
	  	}//if
	  	cout<<tempA<<", "<<tempB<<", ";       
	}//while
	cout<<"File1 is in ordered sequence."<<endl;
	//check if file2 is in order
	while(inFile2>>tempA){
	  	if(inFile2>>tempB);
	  	else{
	  	  tempC = tempA;
	  	  tempA = tempB;
	  	  tempB = tempC;
	  	}
	  	if(tempA > tempB){
	  	  cout<<tempB<<" ";
	  	  cout<<"Only sorted files can be merged."<<endl;
	  	  return 0;
	  	}//if
        cout<<tempA<<", "<<tempB<<", ";
	}//while
	cout<<"File2 is in ordered sequence."<<endl;
	inFile1.close();
	inFile2.close();
	inFile1.open(argv[parameter1]);
	inFile2.open(argv[parameter2]);
	cout<<"New Merged File"<<endl;
	ofstream outFile;
	outFile.open("outFile.txt");
	
	tempA = 0, tempB = 0;
	int nothing = 0;
	bool loop = true;
	//step 2
	inFile1>>tempA;
	inFile2>>tempB;
		while((loop)){//step 3
			if(tempA < tempB){
			   cout<<tempA<<endl;
			   outFile<<tempA<<endl;
			   if(inFile1>>tempA)
			   	  nothing++;
			   else loop = false;
			}//if
			else if (tempA > tempB ){
				cout<<tempB<<endl;
				outFile<<tempB<<endl;
				if(inFile2>>tempB)
					nothing++;
				else loop = false;
			}//else if
			else if (tempA == tempB){
				cout<<tempA<<endl;
				outFile<<tempA<<endl;
				if(inFile1>>tempA) nothing++;
				else loop = false;
				if(inFile2>>tempB) nothing++;
				else loop = false;
			}//else if
		}//while
		//step 4
		while(inFile1>>tempA){
			cout<<tempA<<endl;
			outFile<<tempA<<endl;
		}
		while(inFile2>>tempB){
			cout<<tempB<<endl;
			outFile<<tempB<<endl;
		}
		outFile.close();
	
	return 0; 
}
