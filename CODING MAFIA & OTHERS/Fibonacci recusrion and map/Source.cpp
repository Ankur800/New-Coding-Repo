#include<iostream>
#include<map>
using namespace std;

map<int, int long long>hashMap;

int long long fibonacci(int n) {
	if (n <= 1)
		return n;
	if (hashMap[n] != 0)
		return hashMap[n];
	else {
		hashMap[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main() {
	int n = 50;
	for (int i = 0; i < n; i++)
		cout << fibonacci(i) << " ";

	return 0;
}