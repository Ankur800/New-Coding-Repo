#include<iostream>
using namespace std;

void solveTowerOfHanoi(int n, int source, int destination, int helper) {
	if (n == 1) {
		cout << "Move plate " << n << " from " << source << " to " << destination << endl;
		return;
	}
	solveTowerOfHanoi(n - 1, source, helper, destination);
	cout << "Move plate " << n << " from " << source << " to " << destination << endl;
	solveTowerOfHanoi(n - 1, helper, destination, source);
}

int main() {
	int n = 3;
	int source = 1;
	int helper = 2;
	int destination = 3;
	solveTowerOfHanoi(n, source, destination, helper);

	return 0;
}