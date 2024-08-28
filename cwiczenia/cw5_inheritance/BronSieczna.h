#ifndef ZAJECIA5_BRONSIECZNA_H
#define ZAJECIA5_BRONSIECZNA_H
#include "Bron.h"

class BronSieczna : public Bron{

private:
    float ostrze;

public:
    BronSieczna (std::string Nazwa, int Obj, int Waga, int Razenie, int Kaliber, float ostrze);
    ~BronSieczna();
    void wyswietl();
    float getOstrze() const;
    void setOstrze(float Ostrze);
};


#endif
