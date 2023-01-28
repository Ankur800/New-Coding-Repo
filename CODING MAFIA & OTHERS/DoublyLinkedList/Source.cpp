#include<iostream>
using namespace std;

class Node {
private:
	int data;
	Node* next;
	Node* pre;
public:
	Node() {};
	~Node() {
		delete next;
		delete pre;
	}
	Node* createDoublyLinkedList(Node* head);
	void displayList(Node* head);
	void displayReverse(Node* head);
	Node* insertNewList(Node* head);
	Node* deleteList(Node* head);
};

Node* Node::createDoublyLinkedList(Node* head) {
	Node* temp = NULL;
	Node* p = NULL;
	int n;
	cout << "How many elements are there?";
	cin >> n;
	for (int i = 0; i < n; i++) {
		p = head;
		temp = new Node;
		cout << "Enter the data: ";
		cin >> temp->data;
		temp->pre = NULL;
		temp->next = NULL;
		if (head == NULL)
			head = temp;
		else {
			while (p->next != NULL)
				p = p->next;
			temp->pre = p;
			p->next = temp;
		}
	}
	return head;
}

void Node::displayList(Node* head) {
	Node* p = head;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
}

void Node::displayReverse(Node* head) {
	Node* p = head;
	while (p->next != NULL)
		p = p->next;
	cout << endl;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->pre;
	}
}

Node* Node::insertNewList(Node* head) {
	Node* temp = new Node;
	Node* p = head;
	int n;
	cout << "Enter the position at which you want to insert: ";
	cin >> n;
	cout << "Enter the data: ";
	cin >> temp->data;
	temp->pre = NULL;
	temp->next = NULL;
	if (n == 0) {
		temp->next = head;
		head->pre = temp;
		head = temp;
	}
	else {
		for (int i = 0; i < n - 1; i++)
			p = p->next;
		temp->next = p->next;
		p->next->pre = temp;
		p->next = temp;
		temp->pre = p;
	}
	return head;
}

Node* Node::deleteList(Node* head) {
	Node *p = head;
	Node *q = NULL;
	int n;
	cout << "Enter the index from where the node has to be deleted: ";
	cin >> n;
	if (n == 0) {
		head = p->next;
		head->pre = NULL;
		free(p);
	}
	else {
		for (int i = 0; i < n - 1; i++)
			p = p->next;
		q = p->next;
		p->next = q->next;
		if (q->next != NULL)
			q->next->pre = p;
		free(q);
	}
	return head;
}

int main() {
	Node *head = NULL;
	head = head->createDoublyLinkedList(head);
	head->displayList(head);
	head->displayReverse(head);
	head = head->insertNewList(head);
	head->displayList(head);
	head->displayReverse(head);
	head = head->deleteList(head);
	head->displayList(head);
	head->displayReverse(head);

	return 0;
}