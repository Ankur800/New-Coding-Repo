/*
	Design LRU Cache.
*/
#include<iostream>
#include<unordered_map>
using namespace std;

class Node {
	public:
		int value;
		Node *prev, *next;
	Node(int val) {
		value = val;
		prev = NULL;
		next = NULL;
	}
};

class LRUCache {
	public:
		unordered_map<int, Node*> map;
		int capacity, count;
		Node *head, *tail;

		LRUCache(int c) {
			capacity = c;
			head = new Node(0);
			tail = new Node(0);
			head->next = tail;
			tail->prev = head;
			count = 0;
		}

		void deleteNode(Node *node) {
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}

		void addToHead(Node *node) {
			node->next = head->next;
			head->next->prev = node;
			node->prev = head;
			head->next = node;
		}

		void printLRU() {
			Node *curr = head->next;
			while(curr->next != NULL) {
				cout<<curr->value<<" ";
				curr = curr->next;
			}
			cout<<endl;
		}

		void visited(int data) {
			// It means the user has visited some data
			if(map.find(data) != map.end()) {	// HIT
				Node *node = map[data];
				if(tail == node) {
					tail = node->prev;
				}
				deleteNode(node);
				addToHead(node);
			} else {							// MISS
				Node *node = new Node(data);
				map[data] = node;

				if(count < capacity) {			// Add simply
					addToHead(node);
					count++;
				} else {						// Delete last one and add new at front
					map.erase(tail->prev->value);
					deleteNode(tail->prev);
					addToHead(node);
				}
			}

			printLRU();
		}
};

int main() {
	LRUCache cache(4);

	cache.visited(10);
	cache.visited(20);
	cache.visited(10);
	cache.visited(30);
	cache.visited(40);
	cache.visited(50);
	cache.visited(30);

	return 0;
}