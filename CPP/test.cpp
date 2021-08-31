#include<bits/stdc++.h>
using namespace std;

class A {
    public:
        virtual void display() {
            cout<<"Display A"<<endl;
        }
};

class B : public A {
    public:
        int b;
        void display() {
            cout<<"Display B"<<endl;
        }
};

int main() {
    A *ptr;
    A a;
    B b;
    ptr = &a;
    ptr->display();
    ptr = &b;
    ptr->display();

    return 0;
}