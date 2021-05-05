/*
	Decrease value at any index and correct th heap
*/

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
		void buildDummyHeap() {
			arr[0] = 10;
			arr[1] = 20;
			arr[2] = 40;
			arr[3] = 80;
			arr[4] = 100;
			arr[5] = 70;
			
			size = 6;
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
		void printHeap() {
			for(int i=0;i<size;i++) {
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		void decreaseKey(int index, int key) {
			arr[index] = key;
			while(index >= 0 && arr[parent(index)] > arr[index]) {
				swap(arr[parent(index)], arr[index]);
				index = parent(index);
			}
		}
};

int main() {
	Heap heap(10);
	// We have build a min heap
	heap.buildDummyHeap();
	heap.printHeap();

	heap.decreaseKey(3, 5);

	heap.printHeap();

	return 0;
}