#include<iostream>
#include<vector>
using namespace std;

void printValue(int value) {
	cout<<"Value: "<<value<<endl;
}

void forEach(vector<int> &values, void(*func)(int)) {
	for(int value : values) {
		func(value);
	}
}

int main() {
	vector<int> values = { 1, 5, 4, 2, 3 };
	forEach(values, printValue);

	return 0;
}