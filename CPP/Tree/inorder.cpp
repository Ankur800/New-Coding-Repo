#include<iostream>
#include<stack>
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

// Iterative
void inorder(Node *root) {
	Node *curr = root;
	stack<Node*>st;
	while(curr != NULL || !st.empty()) {
		while(curr != NULL) {
			st.push(curr);
			curr = curr->left;
		}
		curr = st.top();
		st.pop();
		cout<<curr->data<<" ";
		curr = curr->right;
	}
}

//Recursive
void inorderRec(Node *root) {
	if(root == NULL) {
		return;
	}
	inorderRec(root->left);
	cout<<root->data<<" ";
	inorderRec(root->right);
}

int main() {

	/*
				1
			  /   \	
			 2     3		Right View = [1, 3, 7]
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

	cout<<"Iterative"<<endl;
	inorder(root);
	cout<<endl<<"Recursive"<<endl;
	inorderRec(root);

	return 0;
}