#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node*next;
}node;

node* createLinkedList(node*head);
void displayLinkedList(node*head);
node* addAtFront(node*head);
node* addAtEnd(node*head);
node* insertAtGivenPos(node*head);
node* deleteFromList(node*head);

int main()
{
	node*head = NULL;
	
	cout << "Choose from the choices given below : " << endl;
	cout << "1. Create a Linked List." << endl;
	cout << "2. Display a Linked List." << endl;
	cout << "3. Insert a node at front of the Linked List." << endl;
	cout << "4. Insert a node at the end of the Linked List." << endl;
	cout << "5. Insert a node at your desired position." << endl;
	cout << "6. Delete a node from your desired position." << endl;
	cout << "7. Exit." << endl << endl;
	
	while (1)
	{
		int choice = 0;
		cout << "Enter your choice here :";
		cin >> choice;
		switch (choice)
		{
		case 1:
			head = createLinkedList(head);
			break;
		case 2:
			displayLinkedList(head);
			break;
		case 3:
			head = addAtFront(head);
			break;
		case 4:
			head = addAtEnd(head);
			break;
		case 5:
			head = insertAtGivenPos(head);
			break;
		case 6:
			head = deleteFromList(head);
			break;
		case 7:
			exit(0);
		default:
			cout << "Error !";
			break;
		}
	}
	system("pause");
	return 0;
}

node* createLinkedList(node*head)
{
	int n;
	cout << "How many nodes ?";
	cin >> n;
	node*temp = NULL;
	node*p = NULL;
	for (int i = 0; i < n; i++)
	{
		temp = (node*)malloc(sizeof(node));
		cout << "Enter the data " << i+1 << " :";
		cin >> temp->data;
		temp->next = NULL;
		if (head == NULL)
			head = temp;
		else
		{
			p = head;
			while (p->next != NULL)
				p = p->next;
			p->next = temp;
		}
	}
	return head;
}

void displayLinkedList(node*head)
{
	if (head == NULL)
		cout << "No List Found !";
	else
	{
		node*p = head;
		while (p != 0)
		{
			cout << p->data << " ";
			p = p->next;
		}
	}
}

node* addAtFront(node*head)
{
	node*temp = NULL;
	temp = (node*)malloc(sizeof(node));
	cout << "\nEnter the data which has to be inserted at front :";
	cin >> temp->data;
	if (head == NULL)
		head = temp;
	else
	{
		temp->next = head;
		head = temp;
	}
	return head;
}

node* addAtEnd(node*head)
{
	node*temp = NULL;
	temp = (node*)malloc(sizeof(node));
	cout << "\nEnter the data which has to be inserted at end :";
	cin >> temp->data;
	temp->next = NULL;
	if (head == NULL)
		head = temp;
	else
	{
		node*p = NULL;
		p = head;
		while (p->next != NULL)
			p = p->next;
		p->next = temp;
		return head;
	}
}

node* insertAtGivenPos(node*head)
{
	int k = 0;
	node*temp = NULL;
	temp = (node*)malloc(sizeof(node));
	cout << "\nEnter the position at which you want to insert your data :";
	cin >> k;
	cout << "\nEnter the data :";
	cin >> temp->data;
	temp->next = NULL;
	node*p = NULL;
	p = head;
	for (int i = 1; i < k-1; i++)
	{
		p = p->next;
	}
	temp->next = p->next;
	p->next = temp;
	return head;
 }
node* deleteFromList(node*head)
{
	int k;
	cout << "\nEnter the position from which node has to be deleted :";
	cin >> k;
	if (head == NULL)
		cout << "No List Found !";
	else
	{
		node*p = NULL;
		node*temp = NULL;
		p = head;
		if (k == 1)
		{
			p = head;
			temp = p;
			head = temp->next;
		}
		else
		{
			for (int i = 1; i < k - 1; i++)
				p = p->next;
			temp = p->next;
			p->next = temp->next;
		}
		free(temp);
	}
	return head;
}