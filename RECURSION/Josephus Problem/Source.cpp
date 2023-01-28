#include<iostream>
#include<vector>
using namespace std;

void solve_Josephus(vector<int>& arr, int k, int swordPerson) {
	if (arr.size() == 1) {
		cout << arr[0] << endl;
		return;
	}
	int indexOfFirstPersonToBeKilled = (swordPerson + k) % arr.size();
	arr.erase(arr.begin() + indexOfFirstPersonToBeKilled);
	swordPerson = indexOfFirstPersonToBeKilled;
	solve_Josephus(arr, k, swordPerson);
}

int main() {
	int n = 40;
	int k = 7;
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		arr.push_back(i + 1);
	}
	solve_Josephus(arr, k - 1, 0);

	return 0;
}