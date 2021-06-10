/*
	Given a Linked List. Reverse the linked list in groups of size k.
	I/P:	10 -> 20 -> 30 -> 40 -> 50 -> 60 -> 70
	O/P:	30 -> 20 -> 10 -> 60 -> 50 -> 40 -> 70
*/
#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node(int x) {
			data = x;
			next = NULL;
		}
};

Node *buildList() {
	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(arr[0]);
	Node *head = new Node(10);
	Node *curr = head;
	for(int i=1;i<n;i++) {
		curr->next = new Node(arr[i]);
		curr = curr->next;
	}

	return head;
}

void printList(Node *head) {
	Node *curr = head;
	while(curr != NULL) {
		cout<<curr->data<<" ";
		curr = curr->next;
	}
	cout<<endl;
}

Node* reverseInGroup(Node *head, int k) {		// O(n) time and O(n/k) space because of recursion
	int count = 0;
	Node *curr = head;
	Node *prev = NULL;
	while(count < k && curr != NULL) {
		Node *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}

	if(curr != NULL) {
		head->next = reverseInGroup(curr, k);	
	}
	
	return prev;
}

Node* reverseInGroupIterative(Node *head, int k) {
	Node *curr = head;
	Node *prevFirst = NULL;
	bool isFirstPass = true;
	while(curr != NULL) {
		Node *first = curr, *prev = NULL;
		int count = 0;
		while(curr != NULL && count < k) {
			Node *next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			count++;
		}
		if(isFirstPass) {
			head = prev;
			isFirstPass = false;
		} else {
			prevFirst->next = prev;
		}
		prevFirst = first;
	}

	return head;
}

int main() {
	Node *head = buildList();
	//printList(head);

	int k = 3;
	//head = reverseInGroup(head, k);
	head = reverseInGroupIterative(head, k);
	printList(head);

	return 0;
}