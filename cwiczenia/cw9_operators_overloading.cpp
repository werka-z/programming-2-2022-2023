#include <iostream>
using namespace std;

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

    ComplexNumbers n1(3,1);
    ComplexNumbers n2(4.7, 3.4);
    
    cout << "n1: " << n1 <<endl;
    cout << "!n1 (czesc urojona):"<< !n1 << endl;

    cout << "n2: " << n2 <<endl;
    cout << "n1 + n2 : " << n1+n2 <<endl;

    ComplexNumbers n3(n1);
    cout << "n1 == n3? " << std::boolalpha << (n1==n3) << endl;

    cout << "n1[0]: " << n1[0] << "n1[1]: "  << n1[1] << "n1[7]: "  << n1[7]<<endl; //n1[7] wywoluje exception out of range

    return 0;
}
/*
 * output:
n1: 3+1i
!n1 (czesc urojona):1

n2: 4.7+3.4i
n1 + n2 : 7.7+4.4i
n1 == n3? true
n1[0]: 3n1[1]: 1n1[7]:
terminate called after throwing an instance of 'std::out_of_range'
what():  Out of range
 */
