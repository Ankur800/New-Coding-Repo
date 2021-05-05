#include<iostream>
#include<string>
using namespace std;

class TrieNode {
public:
	TrieNode **children;
	int weight;

	TrieNode() {
		children = new TrieNode*[26];
		for(int i=0;i<26;i++) {
			children[i] = NULL;
		}
		weight = 0;
	}
};

void insert(string s, int weight, TrieNode *root) {
	if(s.empty()) {
		return;
	}

	TrieNode *child;
	int index = s[0] - 'a';
	if(root->children[index]) {
		child = root->children[index];
	} else {
		child = new TrieNode();
		root->children[index] = child;
	}

	if(root->weight < weight) {
		root->weight = weight;
	}

	insert(s.substr(1), weight, child);
}

int searchBest(string s, TrieNode *root) {
	int bestWeight = -1;
	TrieNode *curr = root;
	for(int i=0;i<s.length();i++) {
		int index = s[i] - 'a';
		TrieNode *child = curr->children[index];
		if(child) {
			curr = child;
			bestWeight = child->weight;
		} else {
			return -1;
		}
	}
	return bestWeight;
}

int main() {
	int n, q;
	cin>>n>>q;
	TrieNode *root = new TrieNode();
	for(int i=0;i<n;i++) {
		string s;
		cin>>s;
		int weight;
		cin>>weight;
		insert(s, weight, root);
	}
	for(int i=0;i<q;i++) {
		string pre;
		cin>>pre;
		cout<<searchBest(pre, root)<<endl;
	}

	return 0;
}