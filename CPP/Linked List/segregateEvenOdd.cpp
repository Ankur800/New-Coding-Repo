/*
	Given a linked list. Segregate even elements first and then odd elements.
	Relative order of even and odd element should be maintained.
	I/P:	1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
	O/P:	2 -> 4 -> 6 -> 8 -> 1 -> 3 -> 5 -> 7
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
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	Node *head = new Node(1);
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

Node *segregate(Node *head) {
	Node *evenStart = NULL, *evenEnd = NULL, *oddStart = NULL, *oddEnd = NULL;
	Node *curr = head;
	while(curr != NULL) {
		int x = curr->data;
		if(x % 2 == 0) {	// Even
			if(evenStart == NULL) {
				evenStart = curr;
				evenEnd = evenStart;
			} else {
				evenEnd->next = curr;
				evenEnd = evenEnd->next;
			}
		} else {			// Odd
			if(oddStart == NULL) {
				oddStart = curr;
				oddEnd = oddStart;
			} else {
				oddEnd->next = curr;
				oddEnd = oddEnd->next;
			}
		}
		curr = curr->next;
	}

	// After Loop
	if(evenStart == NULL || oddStart == NULL) {
		return head;
	}
	evenEnd->next = oddStart;
	oddEnd->next = NULL;

	return evenStart;
}

int main() {
	Node *head = buildList();
	//printList(head);

	head = segregate(head);
	printList(head);

	return 0;
}