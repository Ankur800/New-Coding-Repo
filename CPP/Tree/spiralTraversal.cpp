/*
	Given a binary tree. Traverse and print the tree in Spiral order.
	I/P:						1
							   / \
							  2	  3
							  	 / \
							  	4	5
							   / \	 \
							  6	  7	  8
							 / \	 / \
							9	11	12  13

	O/P:	1 	3 	2 	4 	5 	8 	7	6	9	11	12	13
*/
#include<iostream>
#include<stack>
using namespace std;

class Node{
	public:
		int data;
		Node *left, *right;
		Node(int x) {
			data = x;
			left = NULL;
			right = NULL;
		}
};

void printInSpiralForm(Node *root) {
	if(root == NULL) {
		return;
	}

	stack<Node*> s1, s2;
	s1.push(root);

	while(!s1.empty() || !s2.empty()) {
		while(!s1.empty()) {
			Node *node = s1.top();
			s1.pop();
			cout<<node->data<<" ";
			if(node->left)	s2.push(node->left);
			if(node->right)	s2.push(node->right);
		}

		while(!s2.empty()) {
			Node *node = s2.top();
			s2.pop();
			cout<<node->data<<" ";
			if(node->right)	s1.push(node->right);
			if(node->left) 	s1.push(node->left);
		}
	}
}

int main() {
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(5);
	root->right->left->left = new Node(6);
	root->right->left->right = new Node(7);
	root->right->right->right = new Node(8);
	root->right->left->left->left = new Node(9);
	root->right->left->left->right = new Node(11);
	root->right->right->right->left = new Node(12);
	root->right->right->right->right = new Node(13);

	printInSpiralForm(root);

	return 0;
}