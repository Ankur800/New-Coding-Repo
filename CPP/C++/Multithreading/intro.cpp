#include<iostream>
#include<thread>
using namespace std;

void threadFn() {
	cout<<"I am inside a thread"<<endl;
}

int main() {
	thread t1 {threadFn};

	t1.join();

	return 0;
}