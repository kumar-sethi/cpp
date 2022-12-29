#include<iostream>
#include<string>
using namespace std;

class Rational{

        int n;
        int d;
    public:
        Rational() { cout<<"Default constructor";};
        Rational(const int& num) : n(num), d(1) { cout<<"Param 1 constructor"<<endl;};
        Rational(const int& num, const int& den) : n(num), d(den) { cout<<"Param 2 constructor"<<endl;};
        Rational(const Rational& rhs) : n(rhs.n), d(rhs.d) { cout<<"Copy constructor"<<endl;};
        Rational (Rational&&) noexcept;
        // noexcept keyword prevents object to be in an unknown state
        // Whenever we create Move constructor, it must have noexcept
        // qualifier to prevent the exceptions from leaving source object 
        // in an unknown state.
        // Compiler may ignore move constructor if its not declared with
        // noexcept.
        
        /* We donot need it in case of Copy and swap idiom
        Rational& operator=(const Rational& rhs){
            cout<<"Assignment operator"<<endl;
            if(this != &rhs){
                this->n = rhs.n;
                this->d = rhs.d;
            }
            return *this;
        }
        */
       /* We donot need it in case of Copy and swap idiom
        Rational& operator=(Rational&&) noexcept;
        */
        void swap(Rational& o){
            std::swap(n, o.n);
            std::swap(d, o.d);
        }
        Rational& operator=(Rational other){
            cout<<"copy and swap idiom"<<endl;
            swap(other);

        }
        ~Rational(){};
        void printvalues();
        void reset(){
            n = 0;
            d = 1;
        };

};

Rational::Rational(Rational&& rhs) noexcept{

    cout<<"Move const"<<endl;
    n = std::move(rhs.n);
    d = std::move(rhs.d);
    rhs.reset();

}

   /* We donot need it in case of Copy and swap idiom
    
    Rational& Rational:: operator=(Rational&& rhs) noexcept{
        cout<<endl<<"Move Assignment operator"<<endl;
            if(this != &rhs){
                this->n = rhs.n;
                this->d = rhs.d;
                rhs.reset();
            }
            return *this;
    }
    */

void Rational::printvalues(){
    cout<<n<<"   "<<d<<endl;
}

int main(){
    /*
    Rational a = 7;     // 7/1
    Rational b(5, 3);   // 5/3
    Rational c = b;     // copy ctor
    Rational d;         // default ctor
    //Rational e = std::move(a);         // Trying for move if Move is not specified it will call copy ctor
    // If class doesnt contain move semantic then it will call copy constructor
    //After move definition
    Rational e = std::move(a);
   // Rational f = (Rational &&)b;  //calling move const without using move(), by using casting

    a.printvalues();
    b.printvalues();
    c.printvalues();
    d.printvalues();
    e.printvalues();
    
    
    d = move(b); // if move assignment const is not defined it will call normal = operator
    
    a.printvalues();
    b.printvalues();
    c.printvalues();
    d.printvalues();
    e.printvalues();
    //printf("%s + %s is %s\n", a.c_str(), b.c_str(), Rational(a + b).c_str());
    return 0;

    */

   // Copy and swap idiom

    Rational b1(5, 3);
    Rational b2(1,6);
    b1.printvalues();
    b2.printvalues();

    b2 = b1;  // Assignemnt operator with copy and swap
    
    b1.printvalues();
    b2.printvalues();

    Rational m1(15, 3);
    Rational m2(1,6);
    m1.printvalues();
    m2.printvalues();

    m1 = move(m2);
    m1.printvalues();
    m2.printvalues();


}