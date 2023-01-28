#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n);
int main()
{
	int n;
	cout << "Enter the number of Elements to be sorted: ";
	cin >> n;
	int arr[1000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	bubbleSort(arr, n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	system("pause");
	return 0;
}

void bubbleSort(int arr[], int n)
{
	for (int round = 1; round <= n - 1; round++)
	{
		for (int i = 0; i <n-round; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
			}
		}
	}
}
