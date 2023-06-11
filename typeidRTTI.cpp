#include <iostream>
#include <typeinfo>
using namespace std;

 
class Base{
public:
    int age;
    float value;
    virtual void func(){
        cout<<"Base func"<<endl;
    }
};


class Derived : public Base{
public:
    string name;
    void func(){
        cout<<"Derived func"<<endl;
    }
};

int main(int argc, char const *argv[])
{
    Base* obj = new Derived;
    int i{};
    float f{};
    const type_info &t1 = typeid(f); // Compile time detects
    const type_info &t2 = typeid(*obj); // Runtime detects

    cout<<t1.name()<<endl;
    cout<<t2.name()<<endl;
    return 0;
}
