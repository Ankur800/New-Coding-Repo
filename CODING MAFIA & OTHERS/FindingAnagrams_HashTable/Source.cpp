#include<iostream>
using namespace std;

int main()
{
	char A[] = "verbose";
	char B[] = "observe";
	int arr[26] = {0};
	for (int i = 0; i < strlen(A); i++)
	{
		arr[A[i] - 97] += 1;
	}
	int i = 0;
	for (i = 0; i < strlen(B); i++)
	{
		arr[B[i] - 97] -= 1;
		if (arr[B[i] - 97] < 0)
		{
			cout << "Not Anagram";
			break;
		}
	}
	if (B[i] == '\0')
		cout << "Its Anagram";
	return 0;
}