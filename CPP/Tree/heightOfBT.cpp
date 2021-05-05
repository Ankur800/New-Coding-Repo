#include<iostream>
#include<climits>
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

int calculateHeight(Node* root) {
	if(root == NULL) {
		return 0;
	}

	int leftHeight = calculateHeight(root->left);
	int rightHeight = calculateHeight(root->left);
	return max(leftHeight, rightHeight) + 1;
}

int main() {

	/*
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

	int height = calculateHeight(root);
	cout<<height<<endl;

	return 0;
}