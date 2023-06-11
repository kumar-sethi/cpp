#include <iostream>
using namespace std;
//auto is now after c++11 is  to deduce the type of elements
// Legacy it was very normal auto keyword but after it is very powerful in terms of Generic coding.
    
    
    class Geeks{
    };

    auto getVal(){
        return 5.6;
    }

    int main(){

        auto x = 20;        //int
        auto y = 34.98;     //double
        auto init_list = {'1','2','3','4'};  // initializer_list
        auto obj = Geeks();        //Any Class's object
        auto obj2 = new Geeks();   //Pointer to a class's object

        cout<<typeid(x).name()   <<endl; 
        cout<<typeid(y).name()   <<endl;
        cout<<typeid(init_list).name() <<endl;
        cout<<typeid(obj).name() <<endl;
        cout<<typeid(obj2).name()<<endl;

        cout<<"\n Decltype: \n";

        decltype(getVal()) y1; 
        cout<<typeid(y1).name()   <<endl;
        decltype(x) p = y + 2.2;
        cout<<typeid(p).name()<<endl;
}