#include<iostream>
#include<vector>
using namespace std;

vector<int> fixLastElement(vector<int> &arr, int k) {
	if (arr.size() == 0 || arr[arr.size()-1] <= k) {
		arr.push_back(k);
		return arr;
	}
	int lastElement = arr[arr.size() - 1];
	arr = vector<int>(arr.begin(), arr.end() - 1);
	fixLastElement(arr, k);
	arr.push_back(lastElement);

	return arr;
}

vector<int> sortArray(vector<int> &arr) {
	if (arr.size() == 1) {
		return arr;
	}
	//call for arr of size = current_size - 1
	int lastElement = arr[arr.size() - 1];
	arr = vector<int>(arr.begin(), arr.end() - 1);
	sortArray(arr);
	fixLastElement(arr, lastElement);

	return arr;
}

int main() {
	vector<int> arr = { 2,5,1,6,8,10,23,4,0 };
	sortArray(arr);
	for (int x : arr) {
		cout << x << " ";
	}

	return 0;
}