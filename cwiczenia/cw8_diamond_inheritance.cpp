#include <iostream>
#include <string>
using namespace std;


class Animal{
public:
    string name;
    Animal() : name("generic_animal_name"){}

    Animal(string _name){
        name = _name;
        cout << "Konstruktor zwierzecia\n";
    }

    virtual void makeSound(){
        cout << "** generic animal sound **\n";
    }

};

class Mammal : public virtual Animal{
public:
    string color;

    void eat(){
        cout << "I'm eating\n";
    }
};

class Bird : public virtual Animal{
public:
    int wingSize;
    Bird() : Animal(), wingSize(20){
        cout << "Konstruktor ptaka\n";
    }

    void fly(){
        cout << "I'm flying!\n";
    }

};

class Parrot : public Bird{
public:
    string feathers;
    Parrot() : Bird(){
        cout << "konstruktor papugi\n";
    }
};

class Bat: public Bird,  public Mammal {
public:

    Bat() : Animal(), Bird(){
        cout << "Konstruktor nietoperza\n";
    }

    void makeSound(){
        cout << "Squeek squeek\n";
    }

};


int main() {

//    Animal animal("animal");
//    animal.makeSound();

    Bat b1;
    Animal* ptr = &b1;
    ptr->makeSound();

//    Bat* bat = new Bat();
//    bat->makeSound();
//    bat->fly();
//    bat->eat();
//    cout << "Wingsize: " << bat->wingSize;
//    delete bat;

    return 0;
}
