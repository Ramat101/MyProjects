#include <string>
using namespace std;

class TableNode{
   public:
	int data;
	TableNode* next;
   
	TableNode(){
	   data = 0;
	   next = NULL;
	}//constructor zero arguments
	
	TableNode(int inputData){
		data = inputData;
		next = NULL;
	}//constructor one argument
};

class TableNodeList{
	public:
	TableNode* listHead;
	TableNode* last;
	int length;
	
	TableNodeList(){
		listHead = new TableNode(-999999);
		last = listHead;
		length = 0;
	}	
	
}; //LinkedList
