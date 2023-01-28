#include<iostream>
using namespace std;

class Node {
private:
	int data;
	Node *ptr;
public:
	//Node();
	~Node() { delete ptr; }

	Node* createLinkedList(Node *head);
	void displayList(Node *head);
	int countNumberOfNodes(Node *p);
	int maxElement(Node *p);
	Node* insertElement(Node *head);
	Node* reverseListUsingArray(Node* head);
	Node* reverseListUsingPointers(Node* head);
	Node* reverseListUsingRecursion(Node* q, Node* p);
	Node* mergeLists(Node* head, Node* head2);
};

Node* Node::createLinkedList(Node* head)
{
	Node *temp = NULL;
	Node *p = NULL;
	int n;
	cout << "Enter the number of elemets: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		temp = new Node;
		cout << "Enter the data: ";
		cin >> temp->data;
		temp->ptr = NULL;
		if (head == NULL)
			head = temp;
		else
		{
			p = head;
			while (p->ptr != NULL)
				p = p->ptr;
			p->ptr = temp;
		}
	}
	return head;
}

void Node::displayList(Node *head)
{
	Node* p = head;
	if (p != NULL)
	{
		cout << p->data << " ";
		displayList(p->ptr);
	}
}

int Node::countNumberOfNodes(Node* p)
{
	static int count = 0;
	if (p != NULL)
	{
		count++;
		countNumberOfNodes(p->ptr);
	}
	return count;
}

int Node::maxElement(Node *p)
{
	static int max = 0;
	if (p != NULL)
	{
		if (p->data > max)
			max = p->data;
		maxElement(p->ptr);
	}
	return max;
}

Node* Node::insertElement(Node* head)
{
	int m;
	cout << "Enter the element which has to be inserted: ";
	cin >> m;
	int n;
	cout << "Enter the position at which it has to be inserted: ";
	cin >> n;
	Node *p = head;
	Node *q = NULL;
	if (n == 1)
	{
		Node *temp = new Node;
		temp->data = m;
		temp->ptr = head;
		head = temp;
	}
	else
	{
		while (n > 1)
		{
			q = p;
			p = p->ptr;
			n--;
		}
		Node *temp = new Node;
		temp->data = m;
		q->ptr = temp;
		temp->ptr = p;
	}

	return head;
}

Node* Node::reverseListUsingArray(Node* head)
{
	Node *p = NULL;
	p = head;
	int arr[10];
	int i = 0;
	while (p != NULL)
	{
		arr[i] = p->data;
		i++;
		p = p->ptr;
	}
	i--;
	p = head;
	while (i >= 0)
	{
		p->data = arr[i];
		i--;
		p = p->ptr;
	}
	return head;
}

Node* Node::reverseListUsingPointers(Node* head)
{
	Node *p = NULL;
	Node *q = NULL;
	Node *r = NULL;
	p = head;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->ptr;
		q->ptr = r;
	}
	head = q;
	return head;
}

Node* Node::reverseListUsingRecursion(Node* q, Node* p)
{
	static Node* head = NULL;
	if (p != NULL)
	{
		reverseListUsingRecursion(p, p->ptr);
		p->ptr = q;
	}
	else
		head = q;
	return head;
}

Node* Node::mergeLists(Node* head, Node *head2)
{
	Node* finalHead = NULL;
	Node* last = NULL;
	if (head->data < head2->data)
	{
		finalHead = last = head;
		head = head->ptr;
		last->ptr = NULL;
	}
	else
	{
		finalHead = last = head2;
		head2 = head2->ptr;
		last->ptr = NULL;
	}
	while (head != NULL && head2 != NULL)
	{
		if (head->data < head2->data)
		{
			last->ptr = head;
			last = head;
			head = head->ptr;
			last->ptr = NULL;
		}
		else
		{
			last->ptr = head2;
			last = head2;
			head2 = head2->ptr;
			last->ptr = NULL;
		}
	}
	if (head != NULL)
		last->ptr = head;
	else
		last->ptr = head2;
	return finalHead;
}

int main()
{
	Node *head = NULL;
	head = head->createLinkedList(head);
	Node *p = head;
	head->displayList(head);
	cout << "The number of nodes are: " << head->countNumberOfNodes(p) << endl;
	cout << "The maximum element is: " << head->maxElement(p) << endl;
	head = head->insertElement(head);
	head->displayList(head);
	cout << endl;
	head = head->reverseListUsingArray(head);
	head->displayList(head);
	cout << endl;
	head = head->reverseListUsingPointers(head);
	head->displayList(head);
	cout << endl;
	p = head;
	Node*q = NULL;
	cout << "Using Recusrion: " << endl;
	head = head->reverseListUsingRecursion(q, p);
	head->displayList(head);

	//merging
	Node *head2 = NULL;
	head2 = head2->createLinkedList(head2);
	cout << "List 1 is: " << endl;
	head->displayList(head);
	cout << "List 2 is: " << endl;
	head2->displayList(head2);

	cout << endl;
	Node *finalHead = NULL;
	Node *last = NULL;
	cout << "\nThe merged linked list is: " << endl;

	finalHead = finalHead->mergeLists(head, head2);
	finalHead->displayList(finalHead);

	return 0;
}