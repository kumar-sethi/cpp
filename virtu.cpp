#include<iostream>
using namespace std;

class Base{
    
    public:
    
    char a;
    int b;
    virtual void print(){
        puts("THis is base class\n");
    }

    virtual ~Base(){
        puts("Destructing base class\n");
    }
};


class Derived:public Base{
    public:
    void print(){
        puts("\nObvio, THis is Derived class\n");
    }
    ~Derived(){
        puts("Destructing Derived class\n");
    }
};

main(void){
    Base obj;
    cout<<sizeof(obj);
 
    //Derived obj2;
    Base* ptr = new Derived;
    ptr->print();
    cout<<sizeof(ptr);

    delete ptr;

}