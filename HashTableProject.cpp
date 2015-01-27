//step 0
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstring>
#include "HashTable.h"
using namespace std;

TableNode* findSpot(TableNodeList* list, int dataIn){
		TableNode* spot = list->listHead;
	    while(spot->next != NULL){
	    	if(spot->next->data == dataIn){
	    		cout<<"Data already in the Hash Table."<<endl;
	    		return NULL;
	        }//if
	    	else if (spot->next->data<dataIn)
	    		spot = spot->next;
	    	else
		        return spot;
	    }//while
	    return spot;
}//findSpot

void hashOne(ifstream& inFile, HashTable* table, int b){
		int data = 0, index = 0; 
		TableNode* spot;
		while(inFile>>data){ //step 5.1
		   index = data % b; //step 5.2
		   cout<<"Data:"<<data<<", Index:"<<index; //step 5.3
		   spot = findSpot(table->getElement(index), data); //step 5.4
		   if(spot == NULL){ //step 5.5
			   continue;
		   }
		   else{
		      TableNode* add = new TableNode(data);
		      add->next = spot->next;
		      spot->next = add;
		   }//else
		}//while	
}//hashOne
	
 int sumOfDigits(int x){
	int digit = 0, sum = 0;
	while(x!=0){
		digit = x%10;
		sum = sum + digit;
		x = x/10;
	}
	return sum;
}//sumOfDigits

void hashTwo(ifstream& inFile, HashTable* table, int b){
		int data = 0, index = 0; 
		TableNode* spot; 
		while(inFile>>data){
			index = sumOfDigits(data)%b;
			cout<<"Data:"<<data<<", Index:"<<index<<endl;
			spot = findSpot(table->getElement(index), data);
			if(spot == NULL){
				continue;
			}
			else{
			    TableNode* add = new TableNode(data);
			    add->next = spot->next;
			    spot->next = add;
			   }//else
			}//while
}//hashTwo

int doIt(string x){
	int val = 0;
	for(int i = 0; i<x.length(); i++){
		val = (val*32)+(int)x[i];
	}
	return abs(val);
}//doIt

void hashThree(ifstream& inFile, HashTable* table, int b){
		int index = 0, data = 0;
		TableNode* spot;
		while(inFile>>data){
		   index = doIt(""+data)%b;
		   cout<<"Data:"<<data<<", Index:"<<index<<endl;
		   spot = findSpot(table->getElement(index), data);
		   if(spot == NULL){
			  continue;
		   }
		   else{
			   TableNode* add = new TableNode(data);
			   add->next = spot->next;
			   spot->next = add;
		   }//else
		}//while
}//hashThree

int main(int argc, char* argv[]){
	int parameter = 0, Bsize = 0, whichHash = 0;
	ifstream inFile;
	cout<<"Enter the argument index of where the file is loaded: "<<endl;
	cin>>parameter;
	inFile.open(argv[parameter]); //step 3
	cout<<"Enter the amount of buckets you will use for the Hash Table:"<<endl;
	cin>>Bsize; //step 1
	HashTable* table = new HashTable(Bsize); //step 2
	
	while(true){
		      cout<<"Which hash function would you like to use:"<<endl;
		      cin>>whichHash; //step 4
		      if((whichHash>=1) && (whichHash<=3))
		    	  break;
		   }//while
		   //step 5
		   if(whichHash == 1)
			   hashOne(inFile, table, Bsize);
		   else if (whichHash == 2)
			   hashTwo(inFile, table, Bsize);
		   else if (whichHash == 3)
			   hashThree(inFile,table, Bsize);
		  
		 table->printHashTable(); //step 6
	
	return 0; 
}
