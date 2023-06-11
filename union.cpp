#include<iostream>
using namespace std;

union un{
int a; short b; char c;
un(){
    a = 5;
}
};

main()
{
    un obj;
    std::cout<<obj.a;

}