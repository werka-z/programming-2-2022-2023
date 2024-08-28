#include "Bron.h"
#include <cstdio>

Bron::Bron(std::string Nazwa, int Obj, int Waga, int Razenie, int Kaliber)
        : Przedmiot(Nazwa, Obj, Waga) {
    setRazenie(Razenie);
    setKaliber(Kaliber);
    printf("Tworze Bron.\n");
}

Bron::~Bron() {
    printf("Niszcze Bron.\n");
}

void Bron::wyswietl() {
    Przedmiot::wyswietl();
    printf("Dodatkowe pola Broni: razenie: %d, kaliber: %d.\n", razenie, kaliber);
}

int Bron::getRazenie() const {return razenie;}
int Bron::getKaliber() const {return kaliber;}

void Bron::setRazenie(int Razenie) {
    if (Razenie >= 5 && Razenie <= 100) {
        razenie = Razenie;
    }
    else{
        printf("niepoprawna wartosc razenia, ustawiam na minimalna (5)\n");
        razenie = 5;
    }
    }
void Bron::setKaliber(int Kaliber) {
    if (Kaliber >= 0 && Kaliber <= 12) kaliber = Kaliber;
    else{
        printf("niepoprawny kaliber, ustawiam na 2\n");
        kaliber = 2;
    }
}