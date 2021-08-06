/*
	Given a binary tree. Convert it into a doubly linked list.
	I/P:	
				10							
			   /  \						  
			  2   20
				  / \					
		    	 30 35

	O/P:			|‾‾‾| -->	|‾‾‾| -->	|‾‾‾|  -->	|‾‾‾|  -->	|‾‾‾|
			Head -->| 2 |		|10 |		|30 |		|20 |		|35 |
					|___| <--	|___| <--	|___|  <--	|___|  <--	|___|
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

Node *binaryTreeToLinkedList(Node *root) {
	if(root == NULL) {
		return root;
	}

	static Node *prev = NULL;

	Node *head = binaryTreeToLinkedList(root->left);

	if(prev == NULL) {
		head = root;
	} else {
		prev->right = root;
		root->left = prev;
	}

	prev = root;

	binaryTreeToLinkedList(root->right);

	return head;
}

void printList(Node *head) {
	Node *curr = head;
	while(curr != NULL) {
		cout<<curr->data<<" ";
		curr = curr->right;
	}
	cout<<endl;
}

int main() {
	Node *root = new Node(10);
	root->left = new Node(2);
	root->right = new Node(20);
	root->right->left = new Node(30);
	root->right->right = new Node(35);

	Node *head = binaryTreeToLinkedList(root);

	printList(head);

	return 0;
}