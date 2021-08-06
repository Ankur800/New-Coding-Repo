/*
	Given a binary tree. Find if this tree follows children sum property or not.
	i.e. Sum of children equal to parent.
	I/P:	

				8								
			  /   \	
			 4     4		
			/ \     \
		   1   3   	 4

	O/P:	Yes
*/
#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *left, *right;
		Node(int x) {
			data = x;
			left = NULL;
			right = NULL;
		}
};

bool isChildrenSumProperty(Node *root) {
	if(root == NULL || (root->left == NULL && root->right == NULL)) {
		return true;
	}

	int temp = 0;
	if(root->left) {
		temp += root->left->data;
	}
	if(root->right) {
		temp += root->right->data;
	}

	if(temp != root->data) {
		return false;
	}

	return (isChildrenSumProperty(root->left) && isChildrenSumProperty(root->right));
}

int main() {
	Node *root = new Node(8);
	root->left = new Node(4);
	root->right = new Node(4);
	root->left->left = new Node(1);
	root->left->right = new Node(3);
	root->right->right = new Node(4	);

	cout<<(isChildrenSumProperty(root) ? "Yes" : "No")<<endl;

	return 0;
}