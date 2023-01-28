#include<iostream>
using namespace std;

int min(int arr[], int k, int n);
int main()
{
	int n;
	cin >> n;
	int arr[1000];
	int LOC;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n - 1; i++)
	{
		LOC = min(arr, i, n);
		int temp = arr[i];
		arr[i] = arr[LOC];
		arr[LOC] = temp;
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	system("pause");
	return 0;
}

int min(int arr[], int k, int n)
{
	int LOC = k;
	int MIN = arr[k];
	for (int i = k+1; i < n; i++)
	{
		if (MIN > arr[i])
		{
			MIN = arr[i];
			LOC = i;
		}
	}
	return LOC;
}