/*
	Givent a complete binary tree. Count the total number of nodes.
	I/P:					10
					  	/   	\
					20	  		  30
				   /  \  		  /  \
				  40   50 		60   70
				 /  \  / \		/
				80 90 100 110  120

	O/P:	15

	Naive - O(n)
	Efficient- O(logN * logN)
*/
#include<iostream>
#include<cmath>
using namespace std;

class Node {
	public:
		int data;
		Node *left, *right;
		Node(int x) {
			data = x;
			left = right = NULL;
		}
};

int getNodeCount(Node *root) {
	if(root == NULL) {
		return 0;
	}

	int lh = 0, rh = 0;
	Node *curr = root;
	while(curr != NULL) {
		lh++;
		curr = curr->left;
	}

	curr = root;
	while(curr != NULL) {
		rh++;
		curr = curr->left;
	}

	if(lh == rh) {
		return pow(2, lh) - 1;
	}

	return 1 + getNodeCount(root->left) + getNodeCount(root->right);
}

int main() {
	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right->left = new Node(60);
	root->right->right = new Node(70);
	root->left->left->left = new Node(80);
	root->left->left->right = new Node(90);
	root->left->right->left = new Node(100);
	root->left->right->right = new Node(110);
	root->right->left->left = new Node(120);

	cout<<getNodeCount(root)<<endl;

	return 0;
}