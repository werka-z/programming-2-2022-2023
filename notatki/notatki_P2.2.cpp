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
class Bat: public Bird,  public Mammal {
public:
    Bat() : Animal(), Bird(){
        cout << "Konstruktor nietoperza\n";
    }

    void makeSound(){
        cout << "Squeek squeek\n";
    }

};

class ComplexNumbers{
    float R;
    float I;
public:
    ComplexNumbers &operator=(ComplexNumbers other){
        R = other.R;
        I = other.I;
        return *this;
    }

    ComplexNumbers operator+(const ComplexNumbers &other) const{
        return ComplexNumbers(R + other.R,I + other.I);
    }
    ComplexNumbers operator-(ComplexNumbers const &other) const{
        return ComplexNumbers(R - other.R,I - other.I);
    }

    ComplexNumbers operator*(ComplexNumbers const &other){
        class ComplexNumbers result;
        float a = (R * other.R)-(I * other.I);
        float b= (R*other.I)+(I* other.R);
        R = a;
        I = b;
        return *this;
    }

    ComplexNumbers operator/(ComplexNumbers const &other) const{
        float a = ((R * other.R)+(I * other.I))/((other.R*other.R) + (other.I * other.I));
        float b = ((I * other.R)-(R * other.I))/((other.R*other.R) + (other.I * other.I));
        class ComplexNumbers result;
        result.R = a;
        result.I = b;
        return result;
    }

    ComplexNumbers &operator+=(ComplexNumbers other){
        R += other.R;
        I += other.I;
        return *this;
    }

    ComplexNumbers &operator-=(ComplexNumbers other){
        R -= other.R;
        I -= other.I;
        return *this;
    }

    friend ostream &operator<<(ostream& os, const ComplexNumbers &num){
        os << num.R << "+" << num.I << "i";
        return os;
    }

    //x++
    ComplexNumbers &operator++(){
        R+=1;
        return *this;
    }

    //++x
    ComplexNumbers operator++(int){
        ComplexNumbers old = *this;
        R+=1;
        return old;
    }

    //==
    friend bool operator==(const ComplexNumbers& other1, const ComplexNumbers& other2){
        if (other1.R == other2.R && other1.I == other2.I) return true;
        else return false;
    }

    //!=
    friend bool operator!=(const ComplexNumbers& other1, const ComplexNumbers& other2){
        if (other1.R != other2.R || other1.I != other2.I) return true;
        else return false;
    }

    friend bool operator<(const ComplexNumbers& other1, const ComplexNumbers& other2){
        return other1.R < other2.R;
    }

    friend bool operator<=(const ComplexNumbers& other1, const ComplexNumbers& other2){
        return other1.R <= other2.R;
    }

    friend bool operator>(const ComplexNumbers& other1, const ComplexNumbers& other2){
        return other1.R > other2.R;
    }

    friend bool operator>=(const ComplexNumbers& other1, const ComplexNumbers& other2){
        return other1.R >= other2.R;
    }

    //[] - dla indeksu 0 R, dla 1 I, dla innego wyjatek
    float& operator[](int idx){
        if (!idx) return R;
        else if (idx == 1) return I;
        else
            throw out_of_range("Out of range\n");
    }

    //(int) - wyjatek gdy liczba nie jest calkowieta
    operator int() const {
        if (R - int(R) != 0 || I != 0) {
            throw std::invalid_argument("Exception\n");
        }
        return int(R);
    }

    //! - zwraca część rzeczywistą z części zespolonej liczny
    int operator!() const{
        return (int)I;
    }


public:
    ComplexNumbers() : R(0), I(0) {}
    ComplexNumbers(float a, float b) : R(a), I(b){}
    ComplexNumbers(const ComplexNumbers& other){
        R = other.R;
        I = other.I;
    }

};

int main() {
    Bat b1;
    Animal *ptr = &b1;
    ptr->makeSound();

}

