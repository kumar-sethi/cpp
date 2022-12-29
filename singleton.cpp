#include <iostream>
using namespace std;

class System1{

    private:
        static System1 * obj;
        System1(){}
        System1(const System1&){}
    public:
        static System1* getInstance(){
            if(!obj)
                obj = new System1();
            return obj;
        }

        void callable(){
            puts("Obj is Live");
        }

};

main(){
    System1 *obj2 = System1::getInstance();
    obj2->callable();
}