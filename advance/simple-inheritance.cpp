// simple-inheritance.cpp by Bill Weinman <http://bw.org/>
// 2018-10-08
#include <iostream>
#include <string>
using namespace std;

// Animal class (base)
class Animal {
    string _name;
    string _type;
    string _sound;
    // private constructor prevents construction of base class
    Animal(){}
protected:
    // protected constructor for use by derived classes
    Animal ( const string & n, const string & t, const string & s )
    : _name(n), _type(t), _sound(s) {}
    /*
    friend class Dog;
    friend class Cat;
    friend class Pig;
    */
   //friend const string & get_animal_name(const Animal& a);
public:
    void speak() const;
    const string & name() const { return _name; }
    const string & type() const { return _type; }
    const string & sound() const { return _sound; }
};

void Animal::speak() const {
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}

//const string & get_animal_name(const Animal& a){
//    return a._name;
//}

// Dog class - derived from Animal
class Dog : public Animal {
    int _walked;
public:
    Dog( string n ) : Animal(n, "dog", "woof"), _walked(0) {};
    int walk() { return ++_walked; }
};

    //Dog(string s): Animal(s, "Dog", "boww"), _walked(0){};

class Fur{
    string _quality;
    Fur(){};
protected:
    Fur(const string& s):_quality(s){}
public:
    const string & quality() const {return _quality;};
};

// Cat class - derived from Animal
class Cat : public Animal, public Fur {
    int _petted;
public:
    Cat( string n ) : Animal(n, "cat", "meow"), Fur("silky"), _petted(0) {};
    int pet() { return ++_petted; }
};

// Pig class - derived from Animal
class Pig : public Animal {
    int _fed;
public:
    Pig( string n) : Animal(n, "pig", "oink"), _fed(0) {};
    string latin(){
        return name()+"-ay"; // or Animal::name()
    }
    int feed() { return ++_fed; }
};

int main() {
    Dog d("Rover");
    Cat c("Fluffy");
    Pig p("Arnold");
    
    d.speak();
    c.speak();
    p.speak();
    
    cout << "the " << d.type() << " has been walked " << d.walk() << " times" << endl;
    cout << "the " << c.type() << " has been petted " << c.pet() << " times" << endl;
    cout << "the " << p.type() << " has been fed " << p.feed() << " times" << endl;

    cout << "the " << c.type() << " has Fur of Quality " << c.quality() << endl;

}
