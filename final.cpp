#include<iostream>

class MakeFinal{
    private:
        MakeFinal() {
            std::cout<<"MakeFinal class "<<std::endl;
        }
        friend class Final;
};
//Here we will create one extra class called MakeFinalClass (its default constructor is private). This function is used to solve our purpose. 
//The main Class MyClass can call the constructor of the MakeFinalClass as they are friend classes.
//One thing we have to notice, that the MakeFinalClass is also a virtual base class.
// We will make it virtual base class because we want to call the constructor of the 
//MakeFinalClass through the constructor of MyDerivedClass, 
//not MyClass (The constructor of a virtual base class is not called by the class that inherits from it,
// instead of the constructor that is called by the constructor of the concrete class).
class Final: virtual MakeFinal{

    public:
        Final(){
            std::cout<<"Final class "<<std::endl;
        }

};

class DerivedFinal: public Final{
    public:
        DerivedFinal(){
            std::cout<<"Derived Final class "<<std::endl;
        }
};



class Base final
{
private:
    int value{5};
};

class Derived
{// Cant inherit as Base is final class: public Base{
};

main(){
    DerivedFinal obj;
}