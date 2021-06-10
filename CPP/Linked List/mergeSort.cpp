/*
	Write a merge sort code for Linked Lists.
	I/P:	7 -> 2 -> 9 -> 1 -> 0 -> 4 -> 2 -> 3
	O/P:	0 -> 1 -> 2 -> 2 -> 3 -> 4 -> 7 -> 9
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
	int arr[] = {7, 2, 9, 1, 0, 4, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	Node *head = new Node(7);
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

Node *getTail(Node *head) {
	if(head == NULL || head->next == NULL) {
		return head;
	}
	Node *curr = head;
	while(curr->next != NULL) {
		curr = curr->next;
	}

	return curr;
}

Node *getMidNode(Node *head, Node *tail) {
	Node *slow = head, *fast = head;
	while(fast != tail && fast->next != tail) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

Node *mergeLists(Node *head1, Node *head2) {
	Node *curr1 = head1, *curr2 = head2;
	Node *head = NULL;

	if(curr1->data <= curr2->data) {
		head = curr1;
		curr1 = curr1->next;
	} else {
		head = curr2;
		curr2 = curr2->next;
	}

	Node *curr = head;

	while(curr1 != NULL && curr2 != NULL) {
		if(curr1->data <= curr2->data) {
			curr->next = curr1;
			curr1 = curr1->next;
			curr = curr->next;
		} else {
			curr->next = curr2;
			curr2 = curr2->next;
			curr = curr->next;
		}
	}

	while(curr1 != NULL) {
		curr->next = curr1;
		curr = curr->next;
		curr1 = curr1->next;
	}

	while(curr2 != NULL) {
		curr->next = curr2;
		curr = curr->next;
		curr2 = curr2->next;
	}

	return head;
}

Node *mergeSort(Node *head, Node *tail) {
	if(head == tail) {
		Node *node = new Node(head->data);
		return node;
	}
	Node *mid = getMidNode(head, tail);
	Node *leftHead = mergeSort(head, mid);
	Node *rightHead = mergeSort(mid->next, tail);
	Node *node = mergeLists(leftHead, rightHead);

	return node;
}

int main() {
	Node *head = buildList();
	cout<<"Before Sorting: "<<endl;
	printList(head);

	cout<<"After Sorting: "<<endl;
	Node *tail = getTail(head);
	head = mergeSort(head, tail);
	printList(head);

	return 0;
}