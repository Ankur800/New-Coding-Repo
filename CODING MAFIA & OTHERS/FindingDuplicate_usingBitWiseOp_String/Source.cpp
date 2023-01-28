#include<iostream>
using namespace std;

int main()
{
	char str[] = "finding";
	int H = 0, x = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		x = 1;
		x = x << (str[i] - 97);
		if ((x & H) > 0)
			cout << str[i] << " is duplicate." << endl;
		else
			H = x | H;
	}

	return 0;
}