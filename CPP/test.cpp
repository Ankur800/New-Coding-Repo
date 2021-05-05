#include<iostream>
#include<forward_list>
using namespace std;

int main() {
	forward_list<int> list = {1, 2, 3};
	auto it = list.before_begin();
	advance(it, 2);
	list.erase_after(it);

	for(int num : list) {
		cout<<num<<" ";
	}

	return 0;
}