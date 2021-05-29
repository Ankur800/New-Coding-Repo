#include<iostream>
#include<climits>
using namespace std;

double findMedian(int arr1[], int arr2[], int n1, int n2) {
	int low = 0, high = n1;
	while(low <= high) {
		int i1 = (low + high) / 2;
		int i2 = (n1 + n2 + 1) / 2 - i1;
		int min1 = (i1 == n1) ? INT_MAX : arr1[i1];
		int max1 = (i1 == 0) ? INT_MIN : arr1[i1-1];
		int min2 = (i2 == n2) ? INT_MAX : arr2[i2];
		int max2 = (i2 == 0) ? INT_MIN : arr2[i2-1];

		if(max1 <= min2 && max2 <= min1) {
			if((n1 + n2) % 2 == 0) {
				return ((double)max(max1, max2) + min(min1, min2)) / 2;
			} else {
				return (double)max(max1, max2);
			}
		} else if(max1 > min2) {
			high = i1-1;
		} else {
			low = i1 + 1;
		}
	}

	return -1;
}

int main() {
	int arr1[] = {10, 20, 30};
	int n = 3;
	int arr2[] = {5, 15, 25, 35, 45};
	int m = 5;

	cout<<findMedian(arr1, arr2, n, m)<<endl;

	return 0;
}