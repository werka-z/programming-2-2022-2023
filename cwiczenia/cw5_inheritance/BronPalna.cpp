
#include "BronPalna.h"
BronPalna::BronPalna (std::string Nazwa, int Obj, int Waga, int Razenie, int Kaliber, int szybkosc): Bron(Nazwa, Obj, Waga, Razenie, Kaliber){
    BronPalna::setSzybkosc(szybkosc);
    printf("Tworze bron palna.\n");
}
BronPalna::~BronPalna(){
    printf("Niszcze bron palna.\n");
}
void BronPalna::wyswietl(){
    Bron::wyswietl();
    printf("Dodatkowe pole broni palnej szybkosc: %d.\n", szybkosc);
}

int BronPalna::getSzybkosc() const {
    return szybkosc;
}

void BronPalna::setSzybkosc(int szybkosc){
    if (szybkosc < 0){
        printf("Pociski leca za wolno. Ustawiam ich szybkosc na 300.\n");
        this->szybkosc =  300;
    }
    else this->szybkosc = szybkosc ;
}