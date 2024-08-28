#ifndef ZAJECIA5_BRON_H
#define ZAJECIA5_BRON_H
#include "Przedmiot.h"

class Bron: public Przedmiot {
private:
    int razenie;
    int kaliber;

public:
        Bron (std::string Nazwa, int Obj, int Waga, int Razenie, int Kaliber);
        ~Bron();
        void wyswietl();
        int getRazenie() const;
        int getKaliber() const;
        void setRazenie(int Razenie);
        void setKaliber(int Kaliber);
};

#endif
