#include<iostream>
using namespace std;

class xyz{
public:
    xyz(){}
    ~xyz(){ 
        delete this;
    }
};

int main()
{
xyz *ptr = new xyz();
delete ptr;
std::cout<<"Sample Output";
}