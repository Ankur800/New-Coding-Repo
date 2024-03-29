#include<iostream>
using namespace std;

void permutation(char s[], int k)
{
	static int A[10];
	static char Res[10];

	if (s[k] == '\0')
	{
		cout << Res << endl;
	}

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (A[i] == 0)
		{
			Res[k] = s[i];
			A[i] = 1;
			permutation(s, k + 1);
			A[i] = 0;
		}
	}
}

int main()
{
	char s[] = "ABCD";
	permutation(s, 0);

	return 0;
}