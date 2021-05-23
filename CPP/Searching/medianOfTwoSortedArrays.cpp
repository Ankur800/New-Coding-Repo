#include<iostream>
using namespace std;



int main() {
	int arr1[] = {10, 20, 30, 40, 50};
	int n = 5;
	int arr2[] = {5, 15, 25, 35, 45};
	int m = 5;

	sort(arr1, arr2, n, m);

	for(int i=0;i<n;i++) {
		cout<<arr1[i]<<" ";
	}
	for(int i=0;i<m;i++) {
		cout<<arr2[i]<<" ";
	}
	cout<<endl;

	return 0;
}