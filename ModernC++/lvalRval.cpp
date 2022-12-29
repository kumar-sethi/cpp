#include <iostream>
using namespace std;
//returns r-value
int add(int x, int y){
    return x+y;
}

//returns l-value
int& transform(int x){
    x *=x;
    return x;

}

void Print(int& x){
    cout<<endl<<"Printing int& L-value"<<endl;
}

void Print(const int& x){
    cout<<endl<<"Printing const int& const L-value"<<endl;
}

void Print(int&& x){
    cout<<endl<<"Printing int&& R-value "<<endl;
}

int main(int argc, char const *argv[])
{
    
    int x = 5;
    int y = 10;
    int z = 8;
    // x,y,z are l-value and 5,10,8 are r-value

    // Expression returns r-value
    int result = (x+y) * z;

    // Expression returns l-value
    ++x = 6;

    // R-value references

    int &&r1 = 10;
    cout<<"R1:"<<r1;
    int &&r2 = add(2,3);
    cout<<"R2:"<<r2;

//    int&& r3 = z; // r value cant bind to l value ref
    int &ref = transform(z);
    //cout<<"REF1:"<<ref;
    const int &ref2 = 3;
    cout<<"REF2:"<<ref2;

///
    Print(x); // L-value
    Print(8); // Calls R-value func if R-value func is commented then const L-value ref

    return 0;
}
