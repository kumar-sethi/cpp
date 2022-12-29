#include<iostream>
using namespace std;
// It can typecast any pointer to another pointer
//i.e.why it is dangerous.
class Mango{
    public:
        void eatM(){cout<<"Eatng Mango"<<endl;}
};

class Banana{
    public:
        void eatB(){cout<<"Eatng Banana"<<endl;}
};

int main1(){
    Banana *b = new Banana();
    Mango* m = new Mango();

    Banana* newBanana = reinterpret_cast<Banana*> (m);
    newBanana->eatB();
}


struct myStr{

    int a, b;
    char c;
    bool d;
};

main(){

    myStr s;
    s.a = 10, s.b = 34, s.c = 'r', s.d = true;

    int* p = reinterpret_cast<int*>(&s);
    cout<<*p<<endl;
    p++;
    cout<<*p<<endl;
    p++;
    char* c = reinterpret_cast<char*>(p);
    cout<<*c<<endl;

    c++;
    //cout<<(bool*)*c<<endl;
    bool* d1 = reinterpret_cast<bool*>(c);
    cout<<*d1<<endl;

    int t = 20;
    const int* ptr = &t;
    int* b2 = const_cast<int*> (ptr);
    //*ptr = 30;
    cout<<*b2<<endl;

}