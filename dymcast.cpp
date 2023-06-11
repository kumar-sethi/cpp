#include<iostream>
    #include "memory"
using namespace std;

class Base{
public:
    virtual void print(){
                cout<<"Base"<<endl;    }
};
class Derived1:public Base{
    //public:void print(){    cout<<"Derived1"<<endl;  }
};
class Derived2:public Base{
    public:void print(){    cout<<"Derived2"<<endl;  }
};

main(){
    // int i =0;
    // int j = i++;
    // cout<<i<<j;
    // // R reference
    // int &&rr = 10;
    // cout<<rr;
    
    Derived1 d1;
    Base *b = dynamic_cast<Base*>(&d1);

    //b->print();

    //(b)
    //Derived2* d2 = dynamic_cast<Derived2*> (b);
    Derived2* d11 = dynamic_cast<Derived2*> (b);
    //d11->print();
    if(d11!=nullptr)
       d11->print();

}
