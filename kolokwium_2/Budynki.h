#ifndef KOLOKWIUM2_BUDYNKI_H
#define KOLOKWIUM2_BUDYNKI_H
#include "Budynek.h"
#include <string>
using namespace std;

class Blok : public Budynek {
public:
    Blok();
    explicit Blok(string ulica = "defaultowa");
    void wyswietlWiek() override;
    friend ostream &operator<<(ostream& os, const Blok &blok);
};

class Dom: public virtual Budynek{
public:

    Dom();
    Dom(string ulica);
    void wyswietlWiek();
    friend ostream &operator<<(ostream& os, const Dom&);
};



class Garaz : public virtual Budynek{
public:
    Garaz();
    Garaz(string ulica);
    void wyswietlWiek();
    friend ostream &operator<<(ostream& os, const Garaz&);
};

class DomZGarazem : public Dom, public Garaz {

public:
    DomZGarazem();
    DomZGarazem(string);
    void wyswietlWiek();
    friend ostream &operator<<(ostream& os, const DomZGarazem&);

};

#endif
