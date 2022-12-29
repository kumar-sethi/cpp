#include <iostream>
#include <vector>
using namespace std;

class Subject{
    int value;

    public:
    Subject(int v):value(v){};
    vector<Observer*> vec;
    void registers(Observer* obs){
        vec.push_back(obs);
    }
    void unregisters(Observer* obs){
        // remove(vec.begin(), vec.end(), obs);
       // vec.erase()
    }
    void setvalue(int val){
        this->value = val;
        notify();
    }
    int getval(){        return this->value;    }
    void notify();
};

class Observer{
    protected:
        Subject* subject;
    public:
        int amount;
        Observer(Subject* subj){
            subject = subj;
            cout<<"Base cons called"<<endl;
            subject->registers(this);
        }
        Subject* getSub(){
            return subject; 
        }
        virtual void update() = 0;
};
void Subject::notify(){
    for(auto it:vec)
        it->update();
}

class Person1 : public Observer{
    public:
    Person1(Subject* subj):Observer(subj){update();}
    void update(){
        amount = 15 * (getSub()->getval());
        cout<<"Person1 -> "<<amount<<endl;
    }
};

class Person2 : public Observer{
    public:
    Person2(Subject* subj):Observer(subj){update();}
    void update(){
        amount = 25 * (getSub()->getval());
        cout<<"Person2 -> "<<amount<<endl;
    }
};

int main(){

    Subject* sub = new Subject(100);
    cout<<"Value: "<<sub->getval()<<endl;

    Person1 p1(sub);
    Person2 p2(sub);
    sub->setvalue(200);
    sub->setvalue(657);
 
    delete sub;
}