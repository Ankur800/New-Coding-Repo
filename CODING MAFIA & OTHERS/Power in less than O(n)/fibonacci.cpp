#include<iostream>
using namespace std;

int long long power(int a, int n) {
	int long long ans = 1;
	while (n > 0) {
		if (n % 2 == 1)
			ans = ans * a;
		a = a * a;
		n = n / 2;
	}
	return ans;
}

int main() {
	cout << power(7, 13);

	return 0;
}