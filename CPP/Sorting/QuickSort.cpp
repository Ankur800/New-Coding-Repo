#include<iostream>
#include<algorithm>
using namespace std;

int partition(int a[], int l, int r) {
    int i = l+1;
    int pivot = a[l];
    int index = l;
    int countMin = 0;
    for(;i<=r;i++) {
        if(a[i] <= pivot) {
            countMin++;
        }
    }
    index = l + countMin;
    swap(a[l], a[index]);
    i = l;
    int j = r;
    while(i < index) {
        if(a[i] <= pivot) {
            i++;
        } else {
            while(a[j] > pivot && j > index) {
                j--;
            }
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    
    return index;
}

void quick_sort(int a[], int l, int r) {
    if(l >= r) {
        return;
    }
    if(l < r) {
        int c = partition(a, l, r);
        quick_sort(a, l, c-1);
        quick_sort(a, c+1, r);
    }
}

int main() {
	int arr[] = {5, 9, 8, 3, 2, 7, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	quick_sort(arr, 0, n-1);
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
