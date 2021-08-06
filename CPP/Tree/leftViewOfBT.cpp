/*
	Print Left View of a given Binary Tree

	I/P:
				1
			  /   \	
			 2     3		
			/ \   / \
		   4   5 6   7

	O/P:	1 	2	4
	
*/

#include<iostream>
#include<queue>
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

void leftView(Node* root) {
	if(root == NULL) {
		return;
	}

	queue<Node*>q;
	q.push(root);

	while(!q.empty()) {
		int n = q.size();
		for(int i=0;i<n;i++) {
			Node *node = q.front();
			q.pop();

			if(i == 0) {
				cout<<node->data<<" ";
			}
			if(node->left) {
				q.push(node->left);
			}
			if(node->right) {
				q.push(node->right);
			}
		}
	}
}

int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	leftView(root);

	return 0;
}