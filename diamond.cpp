#include <iostream>
#include <vector>
using namespace std;
 
class A{public:int a=900;};

class B:virtual public A{public:int b;};
class C:virtual public A{public:int c;};

class D:public B, public C{int d;};

main(void){

A obj1;
B obj2;
C obj3;
D obj4;
cout<<sizeof(obj1)<<endl;
cout<<sizeof(obj2)<<endl;
cout<<sizeof(obj3)<<endl;
cout<<sizeof(obj4)<<endl;

cout<<obj4.a<<endl;

}