#include "Budynki.h"
#include "Osiedle.h"
using namespace std;

int main() {
    Blok b1("Piekna 1"), b3("Piekna 3");

    //chyba coś jest nie tak z operatorami = lub [] w szablonie z adresami/pointerami

//    Osiedle<Blok> o1(4); //inicjalizacja szblonu nie działa, ale tylko dla bloku - coś z inicjalizacją wektora
//    o1[1] = &b1;
//    o1[3] = &b3;
//    cout << o1;

    //o1[5] = &b1;

    Dom d2("Kwiatowa 2");
    Osiedle<Dom> o2(3);
    o2[1] = &b1;
    o2[3] = &b3;
    cout << o2;

    DomZGarazem dzg("Sadowa 10");
    dzg.dodajRok();
    Budynek* ptr = &dzg;
    ptr->wyswietlWiek();

}
