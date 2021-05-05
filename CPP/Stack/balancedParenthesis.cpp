#include<iostream>
#include<stack>
using namespace std;

bool isMatching(char a, char b) {
	return ((a == '(' && b == ')') || 
			(a == '[' && b == ']') ||
			(a == '{' && b == '}'));
}

bool isBalanced(string s) {
	stack<char>st;
	for(char ch : s) {
		if(ch == '[' || ch == '(' || ch == '{') {
			st.push(ch);
		} else {
			if(st.empty()) {
				return false;
			}
			if(!isMatching(st.top(), ch)) {
				return false;
			} else {
				st.pop();
			}
		}
	}
	return st.empty() ? true : false;
}

int main() {
	string s = "[({}{}([]))]()";
	if(isBalanced(s)) {
		cout<<"Balanced"<<endl;
	} else {
		cout<<"NOT Balanced";
	}

	return 0;
}