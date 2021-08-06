/*
	Given a binary tree. Calculate it's diameter.
	A diameter is the maximum distance between two leaf nodes.
	I/P:							10
								   /  \
								 20	   70
								/  \
							  30	80
							 /  \	  \
						   40	 50	   90
						  /				 \
						60				  18

	O/P:	7 (distance between NODE 60 and NODE 18)
*/
#include<iostream>
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

int getDiameter(Node *root, int &diameter) {
	if(root == NULL) {
		return 0;
	}

	int lh = getDiameter(root->left, diameter);
	int rh = getDiameter(root->right, diameter);

	diameter = max(diameter, lh+rh+1);

	return 1 + max(lh, rh);
}

int main() {
	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(70);
	root->left->left = new Node(30);
	root->left->right = new Node(80);
	root->left->left->left = new Node(40);
	root->left->left->right = new Node(50);
	root->left->right->right = new Node(90);
	root->left->left->left->left = new Node(60);
	root->left->right->right->right = new Node(18);

	int diameter = 0;
	getDiameter(root, diameter);

	cout<<diameter<<endl;

	return 0;
}