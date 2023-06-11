#include<iostream>
using namespace std;
class Integer{

    int* m_pInt;

public:

    Integer();
    Integer(int value);
    Integer(const Integer& obj);
    Integer(Integer&& obj);
    Integer& operator=(const Integer& obj);
    Integer& operator=(Integer&& obj);
    int GetValue()const;
    void SetValue(int value);
    ~Integer();
};

Integer::Integer(){
    cout<<"Integer()"<<endl;
    m_pInt = new int(0);
}


Integer::Integer(int value){
    cout<<"Integer (int value)"<<endl;
    m_pInt = new int(value);
}


Integer::Integer(const Integer& obj){
    cout<<"const Integer&()"<<endl;
    m_pInt = new int(*obj.m_pInt);
}
// move constructor
Integer::Integer(Integer&& obj){
    cout<<"const Integer&&()"<<endl;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

Integer::~Integer(){
    cout<<"~Integer :"<<endl;//<<*m_pInt<<endl;
    delete m_pInt;
}


int Integer::GetValue() const{
    return *m_pInt;
}


void Integer::SetValue(int value){
    *m_pInt = value;
}

Integer& Integer::operator=(const Integer& obj){
    cout<<"const Integer&() operator"<<endl;
    if(this==&obj){
        return *this;
    }
    delete m_pInt;
    m_pInt = new int(*obj.m_pInt);
    return *this;
}

Integer& Integer::operator=(Integer&& obj){
    cout<<"Integer&& operator"<<endl;
    if(this==&obj){
        return *this;
    }
    delete m_pInt;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
    return *this;
}


Integer Add(const Integer&a, const Integer& b){

    Integer temp;
    temp.SetValue(a.GetValue() + b.GetValue());
    return temp;  // when it returns temp object Compiler calls Move/Copy Const that may/maynot be called
                    // becauze of compiler performing copy or move elision

                    //Move Constructor to be called while returning temp object as we have 
                    // implemented Move contructor now

}

class Number
{
private:
    Integer m_Value{};
public:
    Number(int value):m_Value{value}{}
    // When we define Copy constructor here Move cons./operator deleted
    Number(const Number &n):m_Value{n.m_Value}{ 
        cout<<"Copy Construxtor"<<endl;
    }
    //Same as above with destructor ~Number(){}

    // If we provide implementation of any Move operation then Copy & other move operations got deleted
   // Number(Number&& n):m_Value{move(n.m_Value)}{}
    // then use default specifier
    /*Number(const Number& n)=default;
    Number& operator=(const Number& n)=default;
    Number& operator=(Number&& n)=default;*/

};
Number CreateNumber(int value){
        Number n{value};
        return n;
    }
int main()
{
    /*
    //Integer a(1), b(3);
    //a.SetValue(Add(a, b).GetValue());

    //Integer c = move(b);
    */
    
    Number n1{1};
    auto n2(n1);
    n2=n1;
    auto n4{move(n1)};

    auto n3{CreateNumber(3)};
    n3 = CreateNumber(4);
    

    Integer a(1);
    auto b{a}; // it calls Copy Constructor : To force it to call Move constructor we need to cast 
                // l-value to r-value reference with help of move()
    auto c{move(a)};
    return 0;
}
