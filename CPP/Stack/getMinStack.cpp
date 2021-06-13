/*
	Implement a stack with getMin() function, which given minimum element of stack so far, 
	in O(1) time and O(1) extra space.
*/
#include<iostream>
#include<stack>
using namespace std;

class Stack {
	public:
		stack<int> s;
		int min;

		void push(int x) {
			if(s.empty()) {
				s.push(x);
				min = x;
			} else if(x <= min) {
				s.push(2*x - min);
				min = x;
			} else {
				s.push(x);
			}
		}

		int pop() {
			int t = s.top();
			s.pop();
			if(t <= min) {
				int res = min;
				min = 2*min - t;
				return res;
			} else {
				return t;
			}
		}

		int top() {
			int t = s.top();
			if(t <= min) {
				return min;
			} else {
				return t;
			}
		}

		int getMin() {
			return min;
		}
};

int main() {
    Stack s;
    s.push(4);
    s.push(5);
    s.push(8);
    s.push(1);
    s.pop();
 
    cout<<"Minimum Element from Stack: " <<s.getMin()<<endl;
  
    return 0; 
}