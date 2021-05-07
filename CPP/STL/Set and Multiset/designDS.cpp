/*
	Design a data structure which support following operations:					unordered_set			set
		*	bool search(x)															O(1)				O(logn)
		*	void insert(x)															O(1)				O(logn)
		*	void delete(x)															O(1)				O(logn)
		*	int getFloor(x)	:	Larget value smaller than or equal to x				O(n)				O(logn)
		*	int getCeil(x)	:	Smallest value greater than or equal to x			O(n)				O(logn)
*/
#include<iostream>
#include<set>
#include<climits>
using namespace std;

template <typename T>
class CustomDS {
	private:
		set<T> s;
	public:
		bool search(T x) {
			if(s.find(x) != s.end()) {
				return true;
			}
			return false;
		}
		void insert(T x) {
			s.insert(x);
		}
		void deleteItem(T x) {
			s.erase(x);
		}
		T getCeil(T x) {
			auto it = s.lower_bound(x);
			if(it == s.end()) {
				return INT_MAX;
			}
			return *it;
		}
		T getFloor(T x) {
			auto it = s.lower_bound(x);
			if(it == s.begin()) {
				if(*it == x) {
					return x;
				} else {
					return INT_MIN;
				}
			} else {
				it--;
				return *it;
			}
		}

};

int main() {
	CustomDS<int> s;
	s.insert(3);
	s.insert(5);

	cout<<s.getFloor(4)<<endl;

	return 0;
}