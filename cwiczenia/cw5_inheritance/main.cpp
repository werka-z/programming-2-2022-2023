#include <iostream>
#include "Przedmiot.h"
#include "Bron.h"
#include "BronSieczna.h"
#include "BronMiotana.h"
#include "BronPalna.h"
#include "Plecak.h"

int main() {

//    BronSieczna miecz = BronSieczna("miecz", 100, 100, 100, 2, 3.5);
//    miecz.wyswietl();
//    printf("\n\n");
//
//    BronPalna rewolwer = BronPalna("rewolwer", 50, 25, 34, 12, 240);
//    rewolwer.wyswietl();
//    printf("\n\n");
//
//    BronMiotana oszczep = BronMiotana("oszczep", 20, 30, 15, 10,70);
//    oszczep.wyswietl();
//    printf("\n\n");

    Przedmiot miecz = Przedmiot("miecz", 7, 10);
    Przedmiot latarka = Przedmiot("latarka", 4, 4);
    Przedmiot zapalki = Przedmiot("zapalki", 1, 1);
    Przedmiot kamien = Przedmiot("kamien", 5, 15);
    Plecak plecak = Plecak(20, 20);
    //Plecak plecak = Plecak();
    printf("\n\n");

    plecak.wyswietl();
    plecak.wstaw(&miecz);
    plecak.wstaw(&latarka);
    plecak.wstaw(&zapalki);
    plecak.wyswietl();

    plecak.wstaw(&kamien);

    plecak.wyjmij(&miecz);
    plecak.wstaw(&kamien);
    plecak.zmienParametry(25, 15);
    plecak.wyswietl();


    printf("\n\n");

}
