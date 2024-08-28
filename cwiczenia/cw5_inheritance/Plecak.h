//
// Created by wzygi on 17/04/2023.
//

#ifndef ZAJECIA5_PLECAK_H
#define ZAJECIA5_PLECAK_H
#include "Przedmiot.h"


class Plecak {
private:
    int maxObj;
    int maxWaga;
    Przedmiot** przedmioty;
    int liczbaPrzedmiotow;

public:
    Plecak(int maxObj = 100, int maxWaga = 100);
    ~Plecak();
    void wyswietl();
    void wstaw(Przedmiot* przedmiot);
    void wyjmij(Przedmiot* przedmiot);
    int getMaxWaga();
    int getMaxObj();
    int getWaga();
    int getObj();
    void setMaxWaga(int maxWaga);
    void setMaxObj(int maxObj);
    void zmienParametry(int maxObj, int maxWaga);
};


#endif
