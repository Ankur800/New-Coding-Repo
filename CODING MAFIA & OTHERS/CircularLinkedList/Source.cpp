#include<iostream>
using namespace std;

class Node {
private:
	int data;
	Node *ptr;
public:
	Node() {};
	~Node() { delete ptr; }
	Node* createCircularLinkedList(Node* head);
	void displayCicularLinkedList(Node* head);
	Node* insertNewNode(Node* head);
	Node* deleteNode(Node* head);
};

Node* Node::createCircularLinkedList(Node* head) {
	int n;
	Node *temp = NULL;
	Node *p = NULL;
	cout << "Enter the number of elements: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		temp = new Node;
		cout << "Enter the data: ";
		cin >> temp->data;
		temp->ptr = NULL;
		if (head == NULL) {
			head = temp;
			head->ptr = head;
		}
		else {
			p = head;
			while (p->ptr != head) {
				p = p->ptr;
			}
			p->ptr = temp;
			temp->ptr = head;
		}
	}
	return head;
}

void Node::displayCicularLinkedList(Node* head) {
	Node* p = NULL;
	p = head;
	do {
		cout << p->data << " ";
		p = p->ptr;
	} while (p != head);
}

Node* Node::insertNewNode(Node* head) {
	Node* temp = new Node;
	Node* p = head;
	int n;
	cout << "Enter the position at which you want to insert the data: ";
	cin >> n;
	cout << "Enter the data: ";
	cin >> temp->data;
	if (n == 0) {
		temp->ptr = head;
		while (p->ptr != head)
			p = p->ptr;
		p->ptr = temp;
		head = temp;
	}
	else {
		for (int i = 0; i < n - 1; i++)
			p = p->ptr;
		temp->ptr = p->ptr;
		p->ptr = temp;
	}
	return head;
}

Node* Node::deleteNode(Node* head) {
	int n;
	cout << "Enter the position from which you want to delete the node: ";
	cin >> n;
	Node *p = head;
	Node *q = NULL;
	if (n == 0) {
		while (p->ptr != head)
			p = p->ptr;
		q = head;
		p->ptr = head->ptr;
		
		free(q);
		head = p->ptr;
	}
	else {
		for (int i = 0; i < n - 2; i++)
			p = p->ptr;
		q = p->ptr;
		p->ptr = q->ptr;
		free(q);
	}
	return head;
}

int main() {
	Node *head = NULL;
	head = head->createCircularLinkedList(head);
	head->displayCicularLinkedList(head);
	head = head->insertNewNode(head);
	head->displayCicularLinkedList(head);
	head = head->deleteNode(head);
	head->displayCicularLinkedList(head);

	return 0;
}