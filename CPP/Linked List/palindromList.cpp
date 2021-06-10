/*
	Given a Linked List. Find whether it is palindrom or not.
	I/P:	R -> A -> D -> A -> R
	O/P:	Yes
*/
#include<iostream>
using namespace std;

class Node {
	public:
		char data;
		Node *next;

	Node(char ch) {
		data = ch;
		next = NULL;
	}
};

Node *makeList(string s) {
	Node *head = new Node(s[0]);
	Node *curr = head;
	for(int i=1;i<s.length();i++) {
		curr->next = new Node(s[i]);
		curr = curr->next;
	}

	return head;
}

Node *getMidNode(Node *head) {
	Node *slow = head, *fast = head;
	while(fast != NULL && fast->next != NULL && fast->next->next != NULL) {	// third cond. for floor mid
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

void reverseList(Node *head) {
	Node *curr = head->next;
	Node *prev = NULL;
	while(curr != NULL) {
		Node *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	head->next = prev;
}

bool checkPalindrome(Node *head) {
	// Find the mid node
	Node *mid = getMidNode(head);		// R -> A -> D -> A -> R
										//			 ^
										//			mid

	// Reverse the list from mid
	reverseList(mid);					// R -> A -> D -> R -> A

	mid = mid->next;
	Node *curr = head;

	while(mid != NULL) {
		if(curr->data != mid->data) {
			return false;
		}
		curr = curr->next;
		mid = mid->next;
	}

	return true;
}

int main() {
	string s = "RADAR";
	Node *head = makeList(s);
	
	if(checkPalindrome(head)) {
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}

	return 0;
}