#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node() {
			data = 0;
			next = NULL;
		}
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

int main() {
	Node *head = buildList();
	printList(head);

	return 0;
}