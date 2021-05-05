#include<iostream>
using namespace std;

class Heap {
private:
	int *arr;
	int size, capacity;
public:
	Heap(int sz) {
		capacity = sz;
		arr = new int[capacity];
		size = 0;
	}
	int left(int i) {
		return (2*i + 1);
	}
	int right(int i) {
		return (2*i + 2);
	}
	int parent(int i) {
		return (i-1)/2;
	}
	void insert(int x) {
		if(size == capacity) {
			return;
		}
		size++;
		arr[size-1] = x;
		for(int i = size-1;i != 0 && arr[parent(i)] > arr[i];) {
			swap(arr[i], arr[parent(i)]);
			i = parent(i);
		}
	}
	void printHeap() {
		for(int i=0;i<size;i++) {
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};

int main() {
	Heap heap(10);
	heap.insert(10);
	heap.insert(20);
	heap.insert(15);
	heap.insert(40);
	heap.insert(50);
	heap.insert(100);
	heap.insert(25);
	heap.insert(45);
	heap.printHeap();
	heap.insert(12);
	heap.printHeap();

	return 0;
}