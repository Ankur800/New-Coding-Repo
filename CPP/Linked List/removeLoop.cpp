/*
	Given a singly linked-list, remove the loop if exists.
	I/P:	15 -> 10 -> 12 -> 20
				  ^			   |
				  |____________|
	O/P:	Loop found
*/
#include <bits/stdc++.h> 
using namespace std; 

struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void printList(Node *head) {
	Node *curr = head;
	while(curr != NULL) {
		cout<<curr->data<<" ";
		curr = curr->next;
	}
	cout<<endl;
}

void removeLoop(Node *head) {
	Node *slow = head, *fast = head;
	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) {
			break;
		}
	}
	if(slow != fast) {		// No Loops found
		return;
	}
	slow = head;
	while(slow->next != fast->next) {
		slow = slow->next;
		fast = fast->next;
	}

	fast->next = NULL;
}

int main() 
{ 
	Node *head=new Node(15);
	head->next=new Node(10);
	head->next->next=new Node(12);
	head->next->next->next=new Node(20);
	head->next->next->next->next=head->next;
	
	//printList(head);
	removeLoop(head);
	printList(head);

	return 0;
} 
