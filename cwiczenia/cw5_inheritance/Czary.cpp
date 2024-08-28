#include "Czary.h"
#include <cstdio>


Czary::Czary(std::string Nazwa, int Obj, int Waga, std::string Kolor, int Czas, std::string Rodzaj)
        : Przedmiot(Nazwa, Obj, Waga) {
    setKolor(Kolor);
    setCzas(Czas);
    setRodzaj(Rodzaj);
    printf("Tworze Czary\n");
}

Czary::~Czary() {
    printf("Niszcze Czary\n");
}

void Czary::wyswietl() {
    Przedmiot::wyswietl();
    printf("Pola Czarow: kolor: %s, czas: %d, rodzaj: %s\n", kolor.c_str(), czas, rodzaj.c_str());
}

std::string Czary::getKolor() const {return kolor;}
int Czary::getCzas() const {return czas;}
std::string Czary::getRodzaj() const {return rodzaj;}

void Czary::setKolor(const std::string &Kolor) {
    if (Kolor.length() <= 20) {
        kolor = Kolor;
    } else {
        printf("Za dluga nazwa koloru. Ustawiam na niebieski.\n");
        kolor = "niebieski";
    }
}

void Czary::setCzas(int Czas) {
    if (Czas >= 0 && Czas <= 1000) {
        czas = Czas;
    } else {
        printf("Czary dzialaja za dlugo. Doswiadczony magik udzieli pomocy i wykona to natychmiastowo.\n");
        czas = 0;
    }
}

void Czary::setRodzaj(const std::string &Rodzaj) {
    if (Rodzaj.length() <= 20) {
        rodzaj = Rodzaj;
    } else {
        printf("Za dluga nazwa rodzaju - zakladam, ze to czary zwyczajne.\n");
        rodzaj = "zwyczajne";
    }
}