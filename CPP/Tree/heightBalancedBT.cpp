/*
	Given a binary tree, check whether it is height balanced binary tree or not?
	I/P:	Tree-1
				1							
			  /   \						  
			 2     3
			/ \   / \					
		   4   5 6   7	

	O/P: 	Yes

	I/P:	Tree-2
					1
				   /
				  2
				 /
				3

	O/P:	No
*/

#include<iostream>
#include<cmath>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int _data) {
		data = _data;
		left = NULL;
		right = NULL;
	}
};

int isBalancedTree(Node* root) {		// O(v)
	if(root == NULL) {
		return 0;
	}

	int lh = isBalancedTree(root->left);
	if(lh < 0) return -1;

	int rh = isBalancedTree(root->right);
	if(rh < 0) return -1;

	if(abs(lh - rh) > 1) return -1;		// -1 means not balanced

	return max(lh, rh) + 1;
}

int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	int height = 0;

	if(isBalancedTree(root) != -1) {
		cout<<"Tree-1 is Balanced"<<endl;
	} else {
		cout<<"Tree-1 is NOT Balanced"<<endl;
	}

	Node* root2 = new Node(1);
	root2->left = new Node(2);
	root2->left->left = new Node(3);

	int height2 = 0;
	if(isBalancedTree(root2) != -1) {
		cout<<"Tree-2 is Balanced"<<endl;
	} else {
		cout<<"Tree-2 is NOT Balanced"<<endl;
	}



	return 0;
}