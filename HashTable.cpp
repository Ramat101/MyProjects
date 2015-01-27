#include <iostream>
#include "TableNodeList.h"
using namespace std;

class HashTable{
  public:
	int Bsize;
	TableNodeList** table;
	
	HashTable(){
		Bsize = 0;
		table = new TableNodeList*[Bsize];
	}	
	
	HashTable(int b){
		Bsize = b;
		table = new TableNodeList*[Bsize];
		for(int i = 0; i<Bsize; i++){
		    table[i] = new TableNodeList();
		}
	}
	
	TableNodeList* getElement(int index) {
		return table[index];
	}
    
    void printHashTable(){
		TableNode* spot;
		for(int i = 0; i<Bsize; i++){
			spot = (table[i])->listHead;
			cout<<endl<<"["<<i<<"]=";
			while(spot != NULL){
				if(spot->data == -999999){
					cout<<"dummy->";
					spot = spot->next;
				}
				else{
				    cout<<spot->data<<"->";
				    spot = spot->next;
				}//else
			}//while
			cout<<"NULL";
		}//for
	}//printHashTable

}; //HashTable
