/*
	Given an array of size N containing level order traversal of a BST. 
	Construct the BST (Binary Search Tree) from its given level order traversal.

	I/P:		7 4 12 3 6 8 1 5 10
	O/P:				7
					  /   \
					 4     12
					/ \	  /
				   3   6 8
				  /	  /   \
				 1 	 5	   10

*/
#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class Node{
	public:
		int data;
		Node *left, *right;
		Node(int x) {
			data = x;
			left = right = NULL;
		}
};

void printInorder(Node *root) {
	if(root == NULL) return;

	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

struct NodeDetails {
	Node *node;
	int min, max;
};

Node *constructBST(int arr[], int n) {
	if(n == 0) return NULL;

	Node *root;
	queue<NodeDetails> q;
	int i = 0;

	NodeDetails newNode;
	newNode.node = new Node(arr[i++]);
	newNode.min = INT_MIN;
	newNode.max = INT_MAX;

	q.push(newNode);

	root = newNode.node;

	while(i != n) {
		NodeDetails temp = q.front();
		q.pop();

		// Can we insert new node in left?
		if(i < n && arr[i] < temp.node->data && arr[i] > temp.min) {
			newNode.node = new Node(arr[i++]);
			newNode.min = temp.min;
			newNode.max = temp.node->data;
			q.push(newNode);

			temp.node->left = newNode.node;
		}

		// Can we insert new node in right?
		if(i < n && arr[i] > temp.node->data && arr[i] < temp.max) {
			newNode.node = new Node(arr[i++]);
			newNode.min = temp.node->data;
			newNode.max = temp.max;
			q.push(newNode);

			temp.node->right = newNode.node;
		}
	}

	return root;
}

int main() {
	int arr[] = { 7, 4, 12, 3, 6, 8, 1, 5, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	Node *root = constructBST(arr, n);
	printInorder(root);

	return 0;
}