
#ifndef ZAJECIA5_POKARM_H
#define ZAJECIA5_POKARM_H
#include "Przedmiot.h"

class Pokarm : public Przedmiot {
    public:
        Pokarm(std::string Nazwa, int Obj, int Waga, int Sila, float Woda);
        ~Pokarm();
        void wyswietl();

        int getSila() const;
        float getWoda() const;

        void setSila(int Sila);
        void setWoda(float Woda);

    private:
        int sila;
        float woda;
    };

#endif
