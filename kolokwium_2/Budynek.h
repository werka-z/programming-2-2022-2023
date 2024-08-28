#ifndef KOLOKWIUM2_BUDYNEK_H
#define KOLOKWIUM2_BUDYNEK_H
#include <string>
using namespace std;

class Budynek{
protected:
    int wiek;
    string typ;

public:
    string ulica;
    Budynek();
    virtual void dodajRok();
    virtual void wyswietlWiek() = 0;
    void wyswietlUlice() const;
};


#endif //KOLOKWIUM2_BUDYNEK_H
