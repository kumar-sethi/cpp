#include <iostream>
#include <vector>
using namespace std;

class Base{
public:
	virtual void fun(){	
		cout<<"Base";
	}
};

class Derived: public Base{
public:
	void fun(){	
		cout<<"Derived";
	}
};

class Derived2: public Derived{
public:
	void fun(){	
		cout<<"Derived2";
	}
};

main(){

    cout<<sizeof(new Base)<<endl;
    cout<<sizeof(new Derived)<<endl;
    cout<<sizeof(new Derived2)<<endl;
    Base* obj = new Derived2;
    obj->fun();
}