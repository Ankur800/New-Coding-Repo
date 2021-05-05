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

int calcHeight(Node* root) {
	if(root == NULL) {
		return 0;
	}
	int lHeight = calcHeight(root->left);
	int rHeight = calcHeight(root->right);

	return max(lHeight, rHeight) + 1;
}

int calcDiameter(Node* root) {		// O(v^2)
	if(root == NULL) {
		return 0;
	}
	int lHeight = calcHeight(root->left);
	int rHeight = calcHeight(root->right);
	int currDiameter = lHeight + rHeight + 1;

	int lDiameter = calcDiameter(root->left);
	int rDiameter = calcDiameter(root->right);

	return max(currDiameter, max(lDiameter, rDiameter));
}

int calculateDiameter(Node* root, int* height) {	// O(v)
	if(root == NULL) {
		*height = 0;
		return 0;
	}

	int lh = 0, rh = 0;
	int lDiameter = calculateDiameter(root->left, &lh);
	int rDiameter = calculateDiameter(root->right, &rh);

	int currDiameter = lh + rh + 1;
	*height = max(lh, rh) + 1;

	return max(currDiameter, max(lDiameter, rDiameter));
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

	int height = 0;
	int diameter = calculateDiameter(root, &height);
	cout<<diameter<<endl;

	return 0;
}