#include<iostream>
using namespace std;

void sayHello() {
	cout<<"Hello World!"<<endl;
}

void sayHello2(int val) {
	cout<<"Hello World, val = "<<val<<endl;
}

int main() {
	auto function = sayHello;
	function();

	void(*func)() = sayHello;
	func();

	auto function2 = sayHello2;
	function2(10);

	void(*func2)(int) = sayHello2;
	func2(10);

	return 0;
}