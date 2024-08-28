
#ifndef ZAJECIA5_CZARY_H
#define ZAJECIA5_CZARY_H
#include <string>
#include "Przedmiot.h"


class Czary : public Przedmiot {
public:
    Czary(std::string Nazwa, int Obj, int Waga, std::string Kolor, int Czas, std::string Rodzaj);
    ~Czary();
    void wyswietl();

    std::string getKolor() const;
    int getCzas() const;
    std::string getRodzaj() const;

    void setKolor(const std::string &Kolor);
    void setCzas(int Czas);
    void setRodzaj(const std::string &Rodzaj);

private:
    std::string kolor;
    int czas;
    std::string rodzaj;
};

#endif
