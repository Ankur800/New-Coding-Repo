#include<iostream>
using namespace std;

typedef struct Trie {
	bool end;
	Trie* children[10];
};

Trie* root = NULL;

Trie* createNode() {
	Trie* x = new Trie();
	for (int i = 0; i < 10; i++)
		x->children[i] = NULL;
	x->end = false;
	return x;
}

bool search(string s) {
	if (root == NULL)
		return false;
	Trie* curr = root;
	for (int i = 0; i < s.length(); i++) {
		int index = s[i] - '0';
		if (curr->children[index] == NULL)
			return false;
		curr = curr->children[index];
	}
	if (curr != NULL && curr->end == true)
		return true;
	else
		return false;
}

void insert(string s) {
	if (root == NULL)
		root = createNode();
	Trie* curr = root;
	for (int i = 0; i < s.length(); i++) {
		int index = s[i] - '0'; // '3' - '0' = 3
		if (curr->children[index] == NULL) {
			curr->children[index] = createNode();
		}
		else {
			//nothing to do
		}
		curr = curr->children[index];
	}
	curr->end = true;
}

int main() {
	string s[] = { "9876543210", "9876543211", "9876543213" };

	for (int i = 0; i < 3; i++) {
		insert(s[i]);
	}
	cout << search("9876543211") << endl;
	cout << search("9898687");

	return 0;
}