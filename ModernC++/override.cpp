#include<iostream>
using namespace std;

class Document{
    public:
        virtual void Serialize(float version){
            cout<<"Document::Serialize"<<endl;
        }
};

class Test:public Document
{
public:
    //void Serialize(int version){  No error but overridden not successful as Test t calls Base Serializa()
    //void Serialize(int version) override{  Compile time error
    void Serialize(float version) override final{ 
            cout<<"TEST::Serialize"<<endl;
        }
};

class RichText : public Test
{
    public:
        void Serialize(float version) override{ 
            cout<<"TEST::Serialize"<<endl;
        }
}


int main(int argc, char const *argv[])
{
    Test t;
    Document& d = t;
    d.Serialize(5.6f);
    //Document* d = &t;
    //d.Serialize(5.2);
}
