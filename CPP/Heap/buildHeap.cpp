/*
	Build a mean heap from a given random array of elements
*/

#include<iostream>
using namespace std;

class Heap {
	private:
		int *arr, size, capacity;
	public:
		Heap(int sz) {
			capacity = sz;
			arr = new int[capacity];
			size = 0;
		}
		void makeWrongHeap() {
			arr[0] = 10;
			arr[1] = 5;
			arr[2] = 20;
			arr[3] = 2;
			arr[4] = 4;
			arr[5] = 8;

			size = 6;
		}
		int left(int i) {
			return (2*i + 1);
		}
		int right(int i) {
			return (2*i + 2);
		}
		int parent(int i) {
			return (i - 1)/2;
		}
		void minHeapify(int i) {
			int smallest = i;
			int lt = left(i);
			int rt = right(i);
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
		void printHeap() {
			for(int i=0;i<size;i++) {
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		void buildHeap() {
			for(int i=(size-2)/2;i>=0;i--) {
				minHeapify(i);
			}
		}
};

int main() {
	Heap heap(10);
	heap.makeWrongHeap();
	heap.printHeap();

	heap.buildHeap();
	heap.printHeap();


	return 0;
}