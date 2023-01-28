#include<iostream>
#include<vector>
using namespace std;

void soe(int n) {
	vector<int>arr(n + 1, 0);	//initializing all elements to ZERO
	for (int i = 2; i <= sqrt(n); i++) {
		if (arr[i] == 0) {
			for (int j = 2 * i; j <= n; j += i) {
				arr[j] = 1;
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (arr[i] == 0) {
			cout << i << " ";
		}
	}
}

int main() {
	soe(100);

	return 0;
}