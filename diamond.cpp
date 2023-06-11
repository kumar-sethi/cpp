#include <iostream>
#include <vector>
using namespace std;
 
class A{
    public:int a;
    A(int value):a(value){
        cout<<"DIamond Constructor created"<<endl;        
    };
    void getGrandfather(){cout<<"Grand Father"<<endl;};
};

class B:virtual public A{
    public:int b;
    using A::A;
};
class C:virtual public A{public:int c;
    using A::A;
};
//This is virtual inheritance: which guarantees the single instance of 
// inherited classes. In other words, the Child class will have a single instance of the Person class, 
//shared by both the Father and Mother classes. 
//By having a single instance of the Person class, the ambiguity is resolved.
class D:public B, public C{
    public:
    int d;
    D(int value):A(value), B(value), C(value) {}
    };

main(void){

A obj1(10);
B obj2(20);
C obj3(30);
D obj4(50);
cout<<sizeof(obj1)<<endl;
cout<<sizeof(obj2)<<endl;
cout<<sizeof(obj3)<<endl;
cout<<sizeof(obj4)<<endl;

cout<<obj4.a<<endl;
obj4.getGrandfather();

}