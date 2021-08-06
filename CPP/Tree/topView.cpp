/*
	Top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
	Given a binary tree, print the top view of it.
								  1
							    /   \
							   2     3
							  / \   / \
							 4   5 6   7

					Top View: 4 2 1 3 7

				Idea: Do level order traversal for each horizontal distance store first
*/
#include<iostream>
#include<map>
#include<queue>
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

void topView(Node *root) {
	map<int, int> mp;
	queue<pair<Node*, int>> q;
	q.push({ root, 0 });
	while(!q.empty()) {
		auto p = q.front();
		q.pop();
		Node *node = p.first;
		int hd = p.second;		// horizontal distance
		if(mp.find(hd) == mp.end()) {
			mp[hd] = node->data;
		}

		if(node->left) {
			q.push({ node->left, hd-1 });
		}
		if(node->right) {
			q.push({ node->right, hd+1 });
		}
	}

	for(auto it : mp) {
		cout<<it.second<<" ";
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

	topView(root);

	return 0;
}