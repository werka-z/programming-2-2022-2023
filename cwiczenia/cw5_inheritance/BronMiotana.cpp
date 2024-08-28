#include "BronMiotana.h"


BronMiotana::BronMiotana (std::string Nazwa, int Obj, int Waga, int Razenie, int Kaliber, int wyrzutnia): Bron(Nazwa, Obj, Waga, Razenie, Kaliber){
    BronMiotana::setWyrzutnia(wyrzutnia);
    printf("Tworze bron miotana.\n");
}
BronMiotana::~BronMiotana(){
    printf("Niszcze bron miotana.\n");
}
void BronMiotana::wyswietl(){
    Bron::wyswietl();
    printf("Dodatkowe pole broni miotanej wyrzutnia: %d.\n", wyrzutnia);
}

int BronMiotana::getWyrzutnia() const {
    return wyrzutnia;
}

void BronMiotana::setWyrzutnia(int Wyrzutnia){
    if (wyrzutnia < 50 || wyrzutnia >1000){
        printf("wyrzutnia nie moze miec takiej mocy. Ustawiam na 50.\n");
        wyrzutnia = 50;
    }
    else wyrzutnia = Wyrzutnia;
}
