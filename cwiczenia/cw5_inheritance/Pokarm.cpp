#include "Pokarm.h"
#include <cstdio>

Pokarm::Pokarm(std::string Nazwa, int Obj, int Waga, int Sila, float Woda)
        : Przedmiot(Nazwa, Obj, Waga) {
    setSila(Sila);
    setWoda(Woda);
    printf("Tworze Pokarm\n");
}

Pokarm::~Pokarm() {
    printf("Niszcze Pokarm\n");
}

void Pokarm::wyswietl() {
    Przedmiot::wyswietl();
    printf("Pola Pokarmu: sila: %d, woda: %.2f\n", sila, woda);
}

int Pokarm::getSila() const {return sila;}
float Pokarm::getWoda() const {return woda;}

void Pokarm::setSila(int Sila) {
    if (Sila >= 20 && Sila <= 200) {
        sila = Sila;
    } else {
        printf("Sila powinna miescic sie w przedziale 20-200. Ustawiam na 20.\n");
        sila = 20;
    }
}

void Pokarm::setWoda(float Woda) {
    if (Woda >= 0.1 && Woda <= 1.0) {
        woda = Woda;
    } else {
        printf("Zawartosc wody w jedzeniu powinna byc miedzy 0.1 a 1. Ustawiam na 0.1\n");
        woda = 0.1;
    }
}
