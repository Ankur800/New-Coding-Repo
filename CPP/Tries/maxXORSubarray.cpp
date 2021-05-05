#include<iostream>
using namespace std;

class TrieNode {
public: 
	int data;
	TrieNode *left, *right;
	TrieNode() {
		data = 0;
		left = NULL;
		right = NULL;
	}
	TrieNode(int _data) {
		data = _data;
		left = NULL;
		right = NULL;
	}
};

void insert(int val, TrieNode* root) {
	TrieNode *curr = root;
	for(int i=31;i>=0;i--) {
		int b = (val >> i) & 1;

		if(b == 0) {
			if(!curr->left) {
				curr->left = new TrieNode(1);
			} else {
				(curr->left->data)++;
			}
			curr = curr->left;
		} else {
			if(!curr->right) {
				curr->right = new TrieNode(1);
			} else {
				(curr->right->data)++;
			}
			curr = curr->right;
		}
	}
}

int query(int val, TrieNode *root) {
	int ans = 0;
	TrieNode *curr = root;
	if(root == NULL) {
		return 0;
	}
	for(int i=31;i>=0;i--) {
		int b = (val >> i) & 1;

		if(b == 0) {
			if(curr->right) {
				ans = ans * 2 + 1;
				curr = curr->right;
			} else {
				curr = curr->left;
				ans = ans * 2;
			}
		} else {
			if(curr->left) {
				ans = ans * 2 + 1;
				curr = curr->left;
			} else {
				ans = ans * 2;
				curr = curr->right;
			}
		}
	}
	return ans;
}

int main() {
	int n, xor_till_i;
    int ans = 0;
    cin >> n;
    int *arr = new int[n];
    TrieNode *root = new TrieNode();
    xor_till_i = 0;
    insert(xor_till_i, root);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        xor_till_i ^= arr[i];
        ans = max(ans, query(xor_till_i, root));
        insert(xor_till_i, root);
    }
    cout << ans << endl;

	return 0;
}