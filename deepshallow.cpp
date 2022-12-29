#include<iostream>
using namespace std;


class A{

    int *ptr;
    public:
    A(){
        
    }
    A(const A &obj){

        this->ptr = new int[sizeof(obj.ptr)];
        *(this->ptr) = *(obj.ptr); 
        cout<<"Addr already existing: "<<&(obj.ptr)<<endl;
        cout<<"Addr of new : "<<&(this->ptr)<<endl;
        cout<<"Addr already existing: "<<obj.ptr<<endl;
        cout<<"Addr of new : "<<this->ptr<<endl;
    }

    A& operator =(const A& obj){
        this->ptr = new int[sizeof(obj.ptr)];
        *(this->ptr) = *(obj.ptr); 
        return *this;
    }

    /*
if copy constructor takes the caller supplied object as value, 
i.e. pass by value, then it needs the copy constructor of the given object; hence, 
to get the supplied object from caller into our function itself 
(in this case the copy constructor) we need to call the copy constructor,
which is nothing but calling the same function during function declaration.

That's the reason for passing a reference to a copy constructor.
    */


};


int main(){
    A obj;
    A obj2 = obj;
}