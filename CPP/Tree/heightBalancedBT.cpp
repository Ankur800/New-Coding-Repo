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

int height(Node* root) {
	if(root == NULL) {
		return 0;
	}
	int lHeight = height(root->left);
	int rHeight = height(root->right);

	return max(lHeight, rHeight) + 1;
}

bool isBalanced(Node* root) {		// O(v^2)
	if(root == NULL) {
		return true;
	}

	if(isBalanced(root->left) == false) {
		return false;
	}
	if(isBalanced(root->right) == false) {
		return false;
	}

	int lh = height(root->left);
	int rh = height(root->right);

	if(abs(lh - rh) <= 1) {
		return true;
	} else {
		return false;
	}
}

bool isBalancedTree(Node* root, int* height) {		// O(v)
	if(root == NULL) {
		return true;
	}

	int lh = 0, rh = 0;
	if(isBalancedTree(root->left, &lh) == false) {
		return false;
	}
	if(isBalancedTree(root->right, &rh) == false) {
		return false;
	}

	*height = max(lh, rh) + 1;
	if(abs(lh - rh) <= 1) {
		return true;
	} else {
		return false;
	}
}

int main() {

	/*			
			BALANCED BINARY TREE

				1							
			  /   \						  
			 2     3
			/ \   / \					
		   4   5 6   7				   
	*/

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	int height = 0;

	if(isBalancedTree(root, &height)) {
		cout<<"Tree-1 is Balanced"<<endl;
	} else {
		cout<<"Tree-1 is NOT Balanced"<<endl;
	}

	/* 
			NOT BALANCED TREE

					1
				   /
				  2
				 /
				3
	*/

	Node* root2 = new Node(1);
	root2->left = new Node(2);
	root2->left->left = new Node(3);

	int height2 = 0;
	if(isBalancedTree(root2, &height2)) {
		cout<<"Tree-2 is Balanced"<<endl;
	} else {
		cout<<"Tree-2 is NOT Balanced"<<endl;
	}



	return 0;
}