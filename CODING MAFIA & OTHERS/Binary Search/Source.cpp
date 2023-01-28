#include<iostream>
#include<cstddef>
using namespace std;

void binarySearch(int* arr, int n, int target) {
	int l = 0;
	int h = n - 1;
	int ans = -1;
	while (l <= h) {
		int mid = (l + h) / 2;
		if (arr[mid] == target) {
			ans = mid;
			break;
		}
		else if (arr[mid] > target) {
			h = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << "Found at " << ans << " position" << endl;
}

int main() {
	int arr[] = { 3,4,5,6,8,9,10,13,16,19 };
	int target = 16;
	binarySearch(arr, sizeof(arr) / sizeof(arr[0]), target);

	return 0;
}