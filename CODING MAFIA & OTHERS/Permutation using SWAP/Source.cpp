#include<iostream>
#include<string>
using namespace std;

void permutation(string str, int l, int h) {
	if (l == h) {
		cout << str << endl;
		return;
	}
	for (int i = l; i < h; i++) {
		swap(str[l], str[i]);
		permutation(str, l + 1, h);
		swap(str[l], str[i]);
	}
}

int main() {
	string str = "ABC";
	permutation(str, 0, str.length());

	return 0;
}