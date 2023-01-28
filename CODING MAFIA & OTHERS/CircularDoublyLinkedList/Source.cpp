#include<iostream>
using namespace std;

class Node {
private:
	int data;
	Node* pre;
	Node* next;
public:
	Node() {};
	~Node() {
		delete pre;
		delete next;
	}
	Node* createList(Node* head);
	void displayList(Node* head);
	Node* insertNewNode(Node* head);
	Node* deleteNode(Node* head);
};

Node* Node::createList(Node* head) {
	Node* temp = NULL;
	Node* p = NULL;
	int n;
	cout << "Enter the number of elements in the list: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		temp = new Node;
		p = head;
		cout << "Enter the data: ";
		cin >> temp->data;
		temp->pre = NULL;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			head->next = head;
			head->pre = head;
		}
		else {
			while (p->next != head)
				p = p->next;
			p->next = temp;
			temp->pre = p;
			temp->next = head;
			head->pre = temp;
		}
	}
	return head;
}

void Node::displayList(Node* head) {
	Node* p = head;
	do {
		cout << p->data << " ";
		p = p->next;
	} while (p != head);
}

Node* Node::insertNewNode(Node* head) {
	Node* p = head;
	Node* temp = new Node;
	int n;
	cout << "Enter the index at which you want insertion: ";
	cin >> n;
	cout << "Enter the data: ";
	cin >> temp->data;
	temp->pre = NULL;
	temp->next = NULL;
	if (n == 0) {
		temp->next = head;
		temp->pre = head->pre;
		head->pre->next = temp;
		head->pre = temp;
		head = temp;
	}
	else {
		for (int i = 0; i < n - 1; i++)
			p = p->next;
		p->next->pre = temp;
		temp->next = p->next;
		p->next = temp;
		temp->pre = p;
	}
	return head;
}

Node* Node::deleteNode(Node* head) {
	int n;
	Node* q = NULL;
	Node* p = head;
	cout << "Enter the index from where you want to delete the node: ";
	cin >> n;
	if (n == 0) {
		head->pre->next = p->next;
		p->next->pre = p->pre;
		head = p->next;
		free(p);
	}
	else {
		for (int i = 0; i < n - 1; i++)
			p = p->next;
		q = p->next;
		p->next = q->next;
		q->next->pre = p;
		free(q);
	}
	return head;
}

int main() {
	Node* head = NULL;
	head = head->createList(head);
	head->displayList(head);
	head = head->insertNewNode(head);
	head->displayList(head);
	head = head->deleteNode(head);
	head->displayList(head);

	return 0;
}