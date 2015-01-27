#include <string>
#include "TreeNode.h"
#include <iostream>
#include <fstream>
using namespace std;

TreeNode* search(TreeNode* root, int data){
	TreeNode* spot = root; //step 5.1
		while(true){ //step 5.5
			if (spot != NULL){ //step 5.2
			   if(spot->data == data){
			   	  cout<<"Found "<<spot->data<<endl;
				  return spot;
			}
			//go to the right
			else if(spot->data < data){ //step 5.3
				if(spot->right == NULL){ //single parent
					 if(spot->data == 0)
					 	cout<<"dummy, ";
					 else
					   cout<<spot->data<<", NULL. Data Not Found:"<<data<<endl;
					   return spot->right;
				}
				else{ //internal node
					 if(spot->data == 0)
					 	 cout<<"dummy, ";
					 else
					 	 cout<<spot->data<<", ";
				     spot = spot->right;
				}
			}
			//go to the left
			else if(spot->data > data){ //step 5.4
				if(spot->left == NULL){//single parent
					cout<<spot->data<<", NULL. Data Not Found:"<<data<<endl;
					return spot->left;
				}
				else{
					 if(spot->data == 0)
					 	cout<<"dummy, ";
					 else 
					 	 cout<<spot->data<<", ";
					spot = spot->left;
				}
			}
			else{
				cout<<"Null. Data not found:"<<data<<endl;
				return spot;
			}
		
		}
		}//while
}//search

void in_Order_Traversal(TreeNode* pointer){
	if (pointer != NULL){
		in_Order_Traversal(pointer->left);
		if(pointer->data == 0)
			cout<<"dummy"<<endl;
		else
			cout<<pointer->data<<", "<<endl;
		in_Order_Traversal(pointer->right);
	}
	return;
}//in_Order_Traversal

void insert(TreeNode* root, int data){
	TreeNode* spot = root; //step 4.1
		while(true){//step 4.5
			if(spot->data == data){//step 4.2
				cout<<endl<<data<<" is already in the tree."<<endl;
				return;
			}//if
			//go to the right
			else if(spot->data < data){ //step 4.3
				if(spot->right == NULL){
					cout<<endl<<"Inserting:"<<data<<endl;
					spot->right = new TreeNode(data);
					return;
				}//if - single parent case
				else
					spot = spot->right; //not a leaf node
			}
			//go to the left
			else{ //spot.data > data //step 4.4
				if(spot->left == NULL){
					cout<<endl<<"Inserting:"<<data<<endl;
				    spot->left = new TreeNode(data);
				    return;
				}//if - single parent case
				else //not a leaf node
					spot = spot->left;
		    }//else
		}//while
}//insert

int main(int argc, char* argv[]){
	int parameter = 0;
	int data = 0;
	char method = ' ';
	ifstream inFile;
	TreeNode* root = new TreeNode(); //step 1

	cout<<"Enter the index of the argument of your data file: "<<endl;
	cin>>parameter;
	inFile.open(argv[parameter]); //step 0
	while(inFile>>method){//step 6
 		if(method == '+')//step 4
 			if(inFile>>data)//step 2
 				insert(root, data);
 		 if (method == 'p'){//step 3
 			cout<<endl<<"Printing:"<<endl;
 			in_Order_Traversal(root);
 		}
 		if(method == '*'){//step 5
 			if(inFile>>data){
 				cout<<endl<<"Searching for:"<<data<<endl;
 				//TreeNode* found = new TreeNode();
 				TreeNode* found = search(root, data);
 			}
 		}
	}
    //}//while
	inFile.close(); //step 7

return 0;
}
