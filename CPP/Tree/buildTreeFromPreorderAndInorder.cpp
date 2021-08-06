/*
	Given inorder and preorder traversal of a binary tree. Construct the tree.
	I/P:	preorder[]:	 {1, 2, 4, 3, 5};
			inorder[]:	 {4, 2, 1, 5, 3};

	O/P:				1
					   / \
					  2	  3
					 /	 /
					4	5
*/

#include<iostream>
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

int search(int inorder[], int start, int end, int curr) {
	for(int i=start; i<=end;i++) {
		if(inorder[i] == curr) {
			return i;
		}
	}
	return -1;
}

Node* buildTree(int preorder[], int inorder[], int start, int end) {
	static int idx = 0;

	if(start > end) {
		return NULL;
	}
	
	int curr = preorder[idx];
	idx++;

	Node *node = new Node(curr);

	if(start == end) {
		return node;
	}

	int pos = search(inorder, start, end, curr);

	node->left = buildTree(preorder, inorder, start, pos-1);
	node->right = buildTree(preorder, inorder, pos+1, end);

	return node;
}

void printInorder(Node* root) {
	if(root == NULL) {
		return;
	}
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

int main() {
	int preorder[] = {1, 2, 4, 3, 5};
	int inorder[] = {4, 2, 1, 5, 3};

	int n = sizeof(inorder) / sizeof(inorder[0]);

	Node* root = buildTree(preorder, inorder, 0, n-1);
	printInorder(root);
	
	return 0;
}