/*
	Given a binary tree and a leaf node. 
	Find the time required to burn the whole tree if the tree is burnt from the given leaf node.

	I/P:								10
									   /  \
									  20  30
									 /  \
								  	40  50
								   /
							   	  60
							  	 /
								70
			n = 50

	O/P:	5   (50 -> 20 -> 40 -> 60-> 70)
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

int res = 0;

int getBurningTime(Node *root, int leaf, int &dist) {
	if(root == NULL) {
		return 0;
	}

	if(root->data == leaf) {		// From here the fire will start
		dist = 0;
		return 1;
	}

	int lDist = -1, rDist = -1;
	int lh = getBurningTime(root->left, leaf, lDist);
	int rh = getBurningTime(root->right, leaf, rDist);

	if(lDist != -1) {
		dist = lDist + 1;
		res = max(res, dist + rh);
	} else if(rDist != -1) {
		dist = rDist + 1;
		res = max(res, dist + lh);
	}

	return max(lh, rh) + 1;
}

int main() {
	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->left->left->left = new Node(60);
	root->left->left->left->left = new Node(70);

	int dist = -1;

	int leaf = 50;		// The leaf node from where the fire will start

	getBurningTime(root, leaf, dist);

	cout<<res<<endl;

	return 0;
}