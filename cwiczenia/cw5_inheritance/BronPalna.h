#ifndef ZAJECIA5_BRONPALNA_H
#define ZAJECIA5_BRONPALNA_H
#include "Bron.h"

class BronPalna: public Bron {

private:
    int szybkosc;

public:
    BronPalna (std::string Nazwa, int Obj, int Waga, int Razenie, int Kaliber, int szybkosc);
    ~BronPalna();
    void wyswietl();
    int getSzybkosc() const;
    void setSzybkosc(int szybkosc);
};


#endif
