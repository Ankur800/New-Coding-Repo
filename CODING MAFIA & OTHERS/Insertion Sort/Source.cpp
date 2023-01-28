#include<iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of Elements: ";
	cin >> n;
	int arr[1000];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 2; i <= n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (key < arr[j] && j >= 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	for (int i = 1; i <= n; i++)
		cout << arr[i] << " ";
	system("pause");
	return 0;
}