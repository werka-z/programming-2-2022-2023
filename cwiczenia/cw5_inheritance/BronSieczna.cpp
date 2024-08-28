#include "BronSieczna.h"

BronSieczna::BronSieczna (std::string Nazwa, int Obj, int Waga, int Razenie, int Kaliber, float ostrze): Bron(Nazwa, Obj, Waga, Razenie, Kaliber){
    setOstrze(ostrze);
    printf("Tworze bron sieczna\n");
}
BronSieczna::~BronSieczna(){
    printf("Niszcze bron sieczna\n");
}
void BronSieczna::wyswietl(){
    Bron::wyswietl();
    printf("Dodatkowe pole broni siecznej ostrze: %f\n", ostrze);
}

float BronSieczna::getOstrze() const{
    return ostrze;
}

void BronSieczna::setOstrze(float Ostrze){
    if (Ostrze < 2.0 || Ostrze > 15.0){
        printf("ostrze nie miesci sie w oczekiwanej grubosci, ustawiam na 15.\n");
        this->ostrze = 15;
    }
    else ostrze = Ostrze;
}
