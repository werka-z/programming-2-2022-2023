#include <iostream>
#include <sstream>
#include "Test_Student.h"
using namespace std;

Test::Test() : student(), pytania(nullptr), lPytan(0){}
Test::Test(Student* student):  student(*student), pytania(nullptr),lPytan(0){}

void Test::dodajPytanie(const Pytanie& p) {
    Pytanie* nowePytania = new Pytanie[lPytan + 1];
    for(int i = 0; i < lPytan; ++i) {
        nowePytania[i] = pytania[i];
    }
    nowePytania[lPytan] = p;
    delete[] pytania;
    pytania = nowePytania;
    lPytan++;
}

Test::~Test() {
    delete[] pytania;
}

string Test::toJSON() const {
    std::stringstream ss;
    ss << "{\n";
    ss << "\"student\": " << student.toJSON() << ",\n";
    ss << "\"lPytan\": " << lPytan << ",\n";
    ss << "\"pytania\": [\n";
    for (int i = 0; i < lPytan; ++i) {
        ss << pytania[i].toJSON();
        if (i != lPytan - 1) {
            ss << ",";
        }
        ss << "\n";
    }
    ss << "]\n";
    ss << "}\n";
    return ss.str();
}

void Test::display() {
    student.display();
    for (int i=0; i<lPytan; i++){
        cout << "Pytanie " << i << ": " << pytania[i].getlOdp();
    }
    cout << endl;
}

string Test::toCSV() const {
    string result = student.getImieNazwisko() + "\n";
    for (int i=0; i<lPytan; i++){
        result += "Pytanie " + to_string(i) +": ";
        for (int j=0; j < pytania[i].getlOdp(); j++){
            result+= pytania[i].getOdpStr(j);
            if (j<pytania[i].getlOdp()-1) result += ",";
        }
    }
    return result;
}



Student::Student() : test(nullptr){}

void Student::display() {
    cout << imie << " " << nazwisko << endl;
}

string Student::toJSON() const {
    std::stringstream ss;
    ss << "{\n";
    ss << "\"student\": {\n";
    ss << "\"imie\": \"" << imie << "\",\n";
    ss << "\"nazwisko\": \"" << nazwisko << "\"\n";
    ss << "},\n";
    ss << "\"lPytan\": " << test->lPytan << ",\n";
    ss << "\"pytania\": [\n";
    for (int i = 0; i < test->lPytan; ++i) {
        ss << "{\n";
        ss << "\"lOdp\": " << test->pytania[i].getlOdp() << ",\n";
        ss << "\"odp\": [\n";
        for (int j = 0; j < test->pytania[i].getlOdp(); ++j) {
            ss << static_cast<int>(test->pytania[i].getOdp(j));
            if (j != test->pytania[i].getlOdp() - 1) {
                ss << ",";
            }
        }
        ss << "]\n";
        ss << "}";
        if (i != test->lPytan - 1) {
            ss << ",";
        }
        ss << "\n";
    }
    ss << "]\n";
    ss << "}\n";
    return ss.str();
}

string Student::getImieNazwisko() const {
    return imie + " " + nazwisko;
}

Student::Student(string imie, string nazwisko) : imie(imie) , nazwisko(nazwisko), test(nullptr) {}

void Student::dodajTest(Test* t){
    this->test = t;
}
