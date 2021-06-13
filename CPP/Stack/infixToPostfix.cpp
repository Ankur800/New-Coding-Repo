/*
	Given infix presentation. Convert it into Postfix.
	I/P:	a+b*(c^d-e)^(f+g*h)-i
	O/P:	abcd^e-fgh*+^*+i-
*/
#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;

string convertToPostfix(string str) {
	unordered_map<char, int> map;
	map['^'] = 10;
    map['*'] = 8;
    map['/'] = 7;
    map['+'] = 6;
    map['-'] = 6;

    stack<char> s;
    string res;
    for(char ch : str) {
    	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
    		res.push_back(ch);
    	} else if(ch == '(') {
    		s.push(ch);
    	} else if(ch == ')') {
    		while(s.top() != '(') {
    			res.push_back(s.top());
    			s.pop();
    		}
    		s.pop();		// Remove '('
    	} else {
    		while(!s.empty() && map[ch] <= map[s.top()]) {
    			res.push_back(s.top());
    			s.pop();
    		}
    		s.push(ch);
    	}
    }
    while(!s.empty()) {
    	res.push_back(s.top());
    	s.pop();
    }

    return res;
}

int main() {
	string str = "a+b*(c^d-e)^(f+g*h)-i";

	cout<<convertToPostfix(str)<<endl;

	return 0;
}