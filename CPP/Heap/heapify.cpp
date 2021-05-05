/*
	Correct the min heap by using heapify method
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
		void buildWrongHeap() {
			arr[0] = 40;
			arr[1] = 20;
			arr[2] = 30;
			arr[3] = 35;
			arr[4] = 25;
			arr[5] = 80;
			arr[6] = 32;
			arr[7] = 100;
			arr[8] = 70;
			arr[9] = 60;
			size = 10;
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
		void minHeapify(int i) {
			int lt = left(i);
			int rt = right(i);
			int smallest = i;
			if(lt < size && arr[lt] < arr[smallest]) {
				smallest = lt;
			}
			if(rt < size && arr[rt] < arr[smallest]) {
				smallest = rt;
			}
			if(smallest != i) {
				swap(arr[i], arr[smallest]);
				minHeapify(smallest);
			}
		}
		int extractMin() {
			if(size == 0) {
				return -1;
			}
			if(size == 0) {
				size--;
				return arr[0];
			}
			swap(arr[0], arr[size-1]);
			size--;
			minHeapify(0);
			return arr[size];
		}
};

int main() {
	Heap heap(10);
	// We have build a min heap but it is wrong i.e. the root is greater
	heap.buildWrongHeap();
	heap.printHeap();
	// Let's fix it by using heapify
	heap.minHeapify(0);
	heap.printHeap();

	cout<<"Extracted Min is: "<<heap.extractMin()<<endl;
	heap.printHeap();

	return 0;
}