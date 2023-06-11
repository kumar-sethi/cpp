#include <iostream>
#include<vector>
using namespace std;

class Base
{
private:
    int value;
public:
    Base(int a): value(a)
    {
    }
    ~Base(){}
    const Base& operator >(Base* obj1)
    {
        cout<<"Calling";
        if((this->value > obj1->value))
        {
            return *this;
        }
        else{
            return*obj1;
        }
    }
    const Base& operator *()
    {
        return *this;
    }
    virtual void Display()
    {
        cout<<"Base";
    }
};

class ABC:public Base
{
private:
    int value;
public:
    ABC(int a): value(a), Base(a)
    {
    }
    ~ABC(){}
    void Display()
    {
        cout<<"ABC is bigger";
    }
};


class XYZ:public Base
{
private:
    int value;
public:
    XYZ(int a): value(a), Base(a)
    {
    }
    void Display()
    {
        cout<<"XYZ is bigger";
    }
    ~XYZ(){}
};

main()
{
    Base* obj1 = new ABC(50);
     Base* obj2 = new XYZ(40);
    //cout<<*obj1;
    //*obj1
    obj1->Display();
    (obj1>obj2);//.Display();
    //(*obj1 > *obj2).Display();  //should print XYZ is bigger

}