/*
	Givent a binary tree with n1 and n2, find the Lowest Common Ancestor of n1 and n2;
	I/P:			10
				   /  \
				 20	   30
				 	  /  \
				 	50	  60
				   /	 /  \
				 70	   80	 90
				 			   \
				 			    40

				n1 = 40		n2 = 80

	O/P:	LCA:	60
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

Node* findLCA(Node *root, int n1, int n2) {
	if(root == NULL) return root;

	if(root->data == n1 || root->data == n2) return root;

	Node *lca1 = findLCA(root->left, n1, n2);
	Node *lca2 = findLCA(root->right, n1, n2);

	if(lca1 && lca2) return root;

	if(lca1) return lca1;
	else return lca2;
}

int main() {
	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->right->left = new Node(50);
	root->right->right = new Node(60);
	root->right->left->left = new Node(70);
	root->right->right->left = new Node(80);
	root->right->right->right = new Node(90);
	root->right->right->right->right = new Node(40);

	int n1 = 40, n2 = 80;

	Node *lca = findLCA(root, n1, n2);

	cout<<lca->data<<endl;

	return 0;
}