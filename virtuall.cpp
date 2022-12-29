#include<iostream>
using namespace std;

class Base{
public:
	virtual void func(){
		cout<<"Base Function";
	}
};

class D1: public Base{
	public:
	void func(){
		cout<<"D1 Function";
	}
	void func2(){
		cout<<"D2";
	}
};
class D2: public Base{
	public:
	void func(){
		cout<<"D2 Function";
	}
};

main(){
	Base* bptr = new D1;
	bptr->func(); //
    D1* ptr = dynamic_cast<D1*>(bptr);
	if(ptr){
		ptr->func();
		ptr->func2();
	}
    string s;
    cin>>s;
}
