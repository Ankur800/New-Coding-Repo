/*
	Given a binary tree. Print Level order traversal line by line.
	I/P:			10
				   /  \
				  20  30
				 /
				40

	O/P:	10
			20	30
			40	
*/
#include<iostream>
#include<queue>
using namespace std;

class TreeNode {
	public:
		int data;
		TreeNode *left, *right;
		TreeNode(int x) {
			data = x;
			left = NULL;
			right = NULL;
		}
};

void levelOrderTraversalLineByLine(TreeNode *root) {
	if(root == NULL) {
		return;
	}
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		TreeNode *node = q.front();
		q.pop();
		if(node != NULL) {
			cout<<node->data<<" ";
			if(node->left) {
				q.push(node->left);
			}
			if(node->right) {
				q.push(node->right);
			}
		} else {
			cout<<endl;
			if(!q.empty()) {
				q.push(NULL);
			}
		}
	}
}

int main() {
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(20);
	root->right = new TreeNode(30);
	root->left->left = new TreeNode(40);

	levelOrderTraversalLineByLine(root);

	return 0;
}