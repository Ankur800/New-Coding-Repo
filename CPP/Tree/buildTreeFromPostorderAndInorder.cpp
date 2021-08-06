/*
	Given postorder and inorder traversals of a binary tree. Construct the tree.
	I/P:	postorder[]:	{4, 2, 5, 3, 1};
			inorder[]:		{4, 2, 1, 5, 3};

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
	for(int i=start;i<=end;i++) {
		if(inorder[i] == curr) {
			return i;
		}
	}
	return -1;
}

Node* buildTree(int postorder[], int inorder[], int start, int end, int &idx) {
	
	if(start > end) {
		return NULL;
	}

	int curr = postorder[idx];
	idx--;

	Node *node = new Node(curr);

	if(start == end) {
		return node;
	}

	int pos = search(inorder, start, end, curr);

	node->right = buildTree(postorder, inorder, pos+1, end, idx);
	node->left = buildTree(postorder, inorder, start, pos-1, idx);

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
	int postorder[] = {4, 2, 5, 3, 1};
	int inorder[] = {4, 2, 1, 5, 3};

	int n = sizeof(inorder) / sizeof(inorder[0]);

	int lastIndex = n-1;	// because we need the last index

	Node* root = buildTree(postorder, inorder, 0, n-1, lastIndex);
	printInorder(root);

	return 0;
}