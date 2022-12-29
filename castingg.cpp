#include<iostream>
using namespace std;

class Base{};
class Derived1:public Base{};
class Derived2:public Base{};

main(){
    float f = 3.5;
    int a ;
//1
    a = f;//does same work no difference
    a = static_cast<int> (f); //Explicit msg that we are type casting

//2 
    char c;   //1 byte data
    int* p = (int*) &c; // 4 bytes data
    *p = 5; //pass at compile time, fail at runtime.
    
    //int* ip = static_cast<int*>(&c);// Fail:- Compiletime error
    
    //int d = 10;
    //char *cp = static_cast<char*>(&d);
//3
/*     Derived d1;
    Base* bp1 = (Base*)&d1;
    Base* bp2 = static_cast<Base*>(&d1); //if privately inherit then error */

//4th Main

    Derived1 d1;
    Derived2 d2;

    Base* b1 = static_cast<Base*>(&d1);
    Base* b2 = static_cast<Base*>(&d2);

    Derived1* d1p = static_cast<Derived1*>(b2);
    Derived2* d2p = static_cast<Derived2*>(b1);
//5th
    int i = 10;
    void* v = static_cast<void*>(&i);
    //cout<<" "<<(int*)v<<endl;
    int* ip = static_cast<int*>(v);
cout<<" "<<*ip<<endl;
}