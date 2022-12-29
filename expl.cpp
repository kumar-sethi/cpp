#include <iostream>
using namespace std;
// Explicit is used to avoid implicit call to the constructor.
// Implicit call is when we assign same type one argument of constructor to Obj
// or when through copy constrctr same type value is assigned to constructor as examplesare below:- 
class Base{
        int b_var;
    public:
        explicit Base(int var): b_var(var){}
        void print() {        cout<<b_var<<endl;    }
};

void fun(Base b){
    b.print();
}
main(){
    Base obj(12);   //Normal call to constructor
    Base obj2 = 78; //Implicit call to constructor

    fun(obj);   //Normal call to constructor
    fun(100);   //Implicit call to constructor

}