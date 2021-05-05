#include<iostream>
#include<climits>
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
		void buildDummyHeap() {
			arr[0] = 10;
			arr[1] = 20;
			arr[2] = 30;
			arr[3] = 40;
			arr[4] = 50;
			arr[5] = 35;
			arr[6] = 38;
			arr[7] = 45;	
			
			size = 8;
		}
		int left(int i) {
			return (2*i + 1);
		}
		int right(int i) {
			return (2*i + 2);
		}
		int parent(int i) {
			return (i - 1) / 2;
		}
		void printHeap() {
			for(int i=0;i<size;i++) {
				cout<<arr[i]<<" ";
			}
			cout<<endl;
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
				swap(arr[smallest], arr[i]);
				minHeapify(smallest);
			}
		}
		int extractMin() {
			if(size == 0) {
				return INT_MIN;
			}
			if(size == 1) {
				size--;
				return arr[size];
			}
			swap(arr[0], arr[size-1]);
			size--;
			minHeapify(0);
			return arr[size];
		}
		void decreaseKey(int index, int key) {
			arr[index] = key;
			while(index >= 0 && arr[parent(index)] > arr[index]) {
				swap(arr[parent(index)], arr[index]);
				index = parent(index);
			}
		}
		void deleteKey(int index) {
			decreaseKey(index, INT_MIN);
			extractMin();
		}
};

int main() {
	Heap heap(10);
	heap.buildDummyHeap();
	heap.printHeap();

	heap.deleteKey(3);

	heap.printHeap();


	return 0;
}