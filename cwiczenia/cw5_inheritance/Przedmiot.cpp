#include "Przedmiot.h"
#include <string>
#include <cstdio>

Przedmiot::Przedmiot(std::string Nazwa, int Obj, int Waga ){
    setNazwa(Nazwa);
    setObjetosc(Obj);
    setWaga(Waga);
    printf("Tworze Przedmiot %s.\n", nazwa.c_str());
}

Przedmiot::~Przedmiot(){
    printf("Niszcze Przedmiot %s.\n", nazwa.c_str());
}

void Przedmiot::wyswietl() {
    printf("Przedmiot: nazwa: %s, objetosc: %d, waga: %d\n", nazwa.c_str(), objetosc, waga);
}

std::string Przedmiot::getNazwa() const {return nazwa;}
int Przedmiot::getObjetosc() const {return objetosc;}
int Przedmiot::getWaga() const {return waga;}



void Przedmiot::setNazwa(const std::string& Nazwa) {
    nazwa = Nazwa;
}
void Przedmiot::setObjetosc(int Obj) {
    if (Obj >= 0) {
        objetosc = Obj;
    } else {
        printf("Ujemna objetosc - ustawiam na 0.\n");
        objetosc = 0;
    }
}
void Przedmiot::setWaga(int Waga) {
    if (Waga >= 0) {
        waga = Waga;
    } else {
        printf("Ujemna waga - ustawiam na 0.\n");
        waga = 0;
    }
}

bool Przedmiot::tenSam(Przedmiot* inny) const{
    return this == inny;
}