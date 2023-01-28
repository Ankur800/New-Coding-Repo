#include<iostream>
using namespace std;

class Array {
private:
	int *A;
	int length;
public:
	Array();
	~Array();
	void display();
	void Append();
	void insert();
	void Delete();
	void linearSearch();
	void binarySearch();
};
Array::Array() : A(new int[100]) {
	cout << "Enter the number of elements of array:";
	cin >> length;
	cout << "Enter the elements: ";
	for (int i = 0; i < length; i++)
		cin >> A[i];
}
Array::~Array() { delete[] A; }
void Array::display() {
	for (int i = 0; i < length; i++)
		cout << A[i] << " ";
	cout << endl;
}
void Array::Append()
{
	int x;
	cout << "Enter the element which has to be append";
	cin >> x;
	A[length++] = x;
}
void Array::insert()
{
	int a, n;
	cout << "Enter the element which has to be insert :";
	cin >> a;
	cout << "Enter the position at which it has to be inserted:";
	cin >> n;
	if (n <= length)
	{
		for (int i = length; i > n - 1; i--)
			A[i] = A[i - 1];
		A[n - 1] = a;
		length++;
	}
	else
		cout << "Insertion range out of array range." << endl;
}
void Array::Delete()
{
	int n;
	cout << "Enter the position from which the element has to be deleted: ";
	cin >> n;
	if (n >= 0 && n < length)
	{
		for (int i = n - 1; i < length; i++)
			A[i] = A[i + 1];
		length--;
	}
	else
		cout << "Given index out of range" << endl;
}
void Array::linearSearch()
{
	int key;
	cout<< "Enter the element you want to search: ";
	cin >> key;
	int flag = 0;
	for (int i = 0; i < length; i++)
	{
		if (A[i] == key)
		{
			cout << "The key has been found at " << i+1 << "th position" << endl;
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "The element has not found." << endl;
}
int performBinarySearch(int *A, int l, int h, int key)
{
	if (l <= h)
	{
		int mid = floor((l + h) / 2);
		if (key == A[mid])
		{
			cout << "The key has been found at " << mid + 1 << "th position" << endl;
			return 0;
		}
		else if (key < A[mid])
			return performBinarySearch(A, l, mid - 1, key);
		else
			return performBinarySearch(A, mid + 1, h, key);
	}
	else
		cout << "They has not been found." << endl;
}
void Array::binarySearch()
{
	int key;
	cout << "Enter the element which has to be searched.";
	cin >> key;
	performBinarySearch(A, 0, length, key);
}

int main()
{
	Array arr;
	while (true)
	{
		cout << "Press 0 to exit, or press any key to continue." << endl;
		int p;
		cin >> p;
		if (p == 0)
			exit(0);
		cout << "*******************Array Program **********************" << endl;
		int n;
		cout << "Please select the options given below:" << endl;
		cout << "1.Display the Array." << endl;
		cout << "2.Append an element in the array." << endl;
		cout << "3.Insert an element at some position in the array." << endl;
		cout << "4.Delete an element from some position in the array." << endl;
		cout << "5.Linear Search." << endl;
		cout << "6.Binary Search." << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			arr.display();
			break;
		case 2:
			arr.Append();
			break;
		case 3:
			arr.insert();
			break;
		case 4:
			arr.Delete();
			break;
		case 5:
			arr.linearSearch();
			break;
		case 6:
			arr.binarySearch();
			break;
		default:
			cout << "Pleasr provide a valid input" << endl;
			break;
		}
	}

	return 0;
}