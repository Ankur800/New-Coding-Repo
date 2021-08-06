/*
	Given a binary tree, print it vertically.
							  1
					        /   \ 
					       2     3
					      / \   / \
					     4   5 6   7
					              / \ 
					             8   9 

			O/P:	4
					2
					1 5 6
					3 8
					7
					9
*/
#include<iostream>
#include<map>
#include<vector>
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

void getVerticalOrder(Node *root, int hd, map<int, vector<int>> &m) {
	if(root == NULL) {
		return;
	}

	m[hd].push_back(root->data);

	getVerticalOrder(root->left, hd-1, m);
	getVerticalOrder(root->right, hd+1, m);
}

void printVerticalOrder(Node *root) {
	map<int, vector<int>> m;
	int hd = 0;					// HORIZONTAL DISTANCE
	getVerticalOrder(root, hd, m);

	for(auto it = m.begin();it != m.end();it++) {
		for(int i = 0;i<it->second.size();i++) {
			cout<<it->second[i]<<" ";
		}
		cout<<endl;
	}
}

int main() {
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->right->right->left = new Node(8);
	root->right->right->right = new Node(9);

	printVerticalOrder(root);

	return 0;
}