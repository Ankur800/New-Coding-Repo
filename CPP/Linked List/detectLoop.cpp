/*
	Given a singly linked-list. Detect whether it has loop or not.
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

bool hasLoop(Node* head) {
	Node *slow = head, *fast = head;
	while(fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) {
			return true;
		}
	}

	return false;
}

int main() 
{ 
	Node *head=new Node(15);
	head->next=new Node(10);
	head->next->next=new Node(12);
	head->next->next->next=new Node(20);
	head->next->next->next->next=head->next;
	if (hasLoop(head)) 
        cout << "Loop found"; 
    else
        cout << "No Loop"; 
	return 0;
} 
