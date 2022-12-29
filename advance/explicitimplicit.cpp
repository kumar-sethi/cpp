#include<iostream>
#include<string>
using namespace std;

class explicitimplicit
{
private:
    int data;
public:
    explicit explicitimplicit(const int& value):data(value){}
    void setvalue(const int& value){ data = value;}
    int getvalue() const{ return data;}
    //~explicitimplicit();

};

void func(const explicitimplicit& o){
    printf("value is %d\n", o.getvalue());
}

main(){

    explicitimplicit obj = 52;
    func(90);


}