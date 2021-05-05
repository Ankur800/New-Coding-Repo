#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

class TrieNode {
public:
	TrieNode *left, *right;
};

void insert(int n, TrieNode *head) {
	TrieNode *curr = head;
	for(int i=31;i>=0;i--) {
		int b = (n>>i) & 1;

		if(b == 0) {
			if(!curr->left) {
				curr->left = new TrieNode();
			}
			curr = curr->left;
		} else {
			if(!curr->right) {
				curr->right = new TrieNode();
			}
			curr = curr->right;
		}
	}
}

int findMaxXORPair(TrieNode *head, int *arr, int n) {
	int max_XOR = INT_MIN;
	for(int i=0;i<n;i++) {
		TrieNode *curr = head;
		int value = arr[i];
		int curr_XOR = 0;
		for(int j=31;j>=0;j--) {
			int b = (value>>j) & 1;

			if(b == 0) {	// Search for 1
				if(curr->right) {
					curr_XOR += pow(2, j);	// 1<<j
					curr=curr->right;
				} else {
					curr = curr->left;
				}
			} else {	// Search for 0
				if(curr->left) {
					curr_XOR += pow(2, j);	// 1<<j
					curr = curr->left;
				} else {
					curr = curr->right;
				}
			}
		}
		if(curr_XOR > max_XOR) {
			max_XOR = curr_XOR;
		}
	}
	return max_XOR;
}

int main() {
	int n = 6;
	int arr[n] = { 8, 1, 2, 15, 10, 5 };
	TrieNode *head = new TrieNode();
	for(int i=0;i<n;i++) {
		insert(arr[i], head);
	}
	cout<<findMaxXORPair(head, arr, n)<<endl;

	return 0;
}