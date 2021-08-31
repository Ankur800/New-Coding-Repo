#include<iostream>
using namespace std;

using ll = long long;

ll calcSum(ll start, ll end) {
	ll sum = 0;
	for(ll i = start;i <= end;i++) {
		sum += i;
	}

	return sum;
}

int main() {
	ll start = 0, end = 3000000000;
	ll sum = calcSum(start, end);

	cout<<sum<<endl;

	return 0;
}