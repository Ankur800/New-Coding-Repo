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

int sumAtKthLevel(Node* root, int k) {
	if(root == NULL) {
		return -1;
	}
	int currentLevel = 0;
	int sum = 0;
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		Node* node = q.front();
		q.pop();
		if(node != NULL) {
			if(currentLevel == k) {
				sum += node->data;
			}
			if(node->left) {
				q.push(node->left);
			}
			if(node->right) {
				q.push(node->right);
			}
		} else if(!q.empty()) {
			q.push(NULL);
			currentLevel++;
		}
	}
	return sum;
}

int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	/*						k
				1			0
			  /   \
			 2     3		1
			/ \   / \
		   4   5 6   7		2	Find sum at this level	
	*/

	int k = 2;

	int ans = sumAtKthLevel(root, k);

	cout<<ans<<endl;

	return 0;
}