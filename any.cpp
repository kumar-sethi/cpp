#include<bits/stdc++.h>
using namespace std;

class A{
    public:
        A(){cout<<"default"<<endl;}
        A(const int){cout<<"param"<<endl;}
        A(const A&){cout<<"copy"<<endl;}
        A(A && ) {cout<<"move"<<endl;}
        ~A() {cout<<"~A";}
};

A func(const int choice){
    if(choice == 1)
        return A{};
    else if(choice == 2)
        return A{2};
    else
        return move(A{});
}

main(){
    //A ob = func(1);
    //A ob2 = func(2);
    //A ob3 = func(0);
    //return 0;
    int i = 1, j = 1, k = 1;
    if(i++ == 1 || ++j == 1 && ++k >2){
        cout<<i<<j<<k;
    }
    else{}
}

/* 
class B{
    public:
        B() {cout<<"1";}
        ~B() {cout<<"d1";}
        void test(){cout<<"4";}
};

class C: public B{
    public:
        C() {cout<<"3";}
        ~C() {cout<<"d3";}
        void test(){cout<<"5";}
    private:
        A a;
}; */

