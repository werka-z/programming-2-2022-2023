#include "Budynek.h"
#include <iostream>
using namespace std;

Budynek::Budynek(): wiek(0){}

void Budynek::dodajRok() {
    wiek++;
}

void Budynek::wyswietlUlice() const {
    cout << ulica;
}
