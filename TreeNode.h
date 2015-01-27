#include<iostream>
using namespace std;
class TreeNode{
   public:
	TreeNode* left;
	TreeNode* right;
 	int data;

	TreeNode(){
		left = NULL;
		right = NULL;
		data = 0;
	}
	
	TreeNode(int content){
		left = NULL;
		right = NULL;
		data = content;
	}//constructor one argument
};
