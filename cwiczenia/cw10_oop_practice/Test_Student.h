#include "Pytanie.h"
using namespace std;

class Student{
    string imie;
    string nazwisko;
    Test* test;

public:
    Student();
    Student(string imie, string nazwisko);
    string toJSON() const;
    void display();
    string getImieNazwisko() const;
    void dodajTest(Test*);
};

class Test{

public:
    Student student;
    int lPytan;
    Pytanie* pytania;

    Test();
    Test(Student* student);
    ~Test();
    string toJSON() const ;
    string toCSV() const;
    void display();
    void dodajPytanie(const Pytanie&);

};