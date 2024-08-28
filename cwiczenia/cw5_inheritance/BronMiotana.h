#ifndef ZAJECIA5_BRONMIOTANA_H
#define ZAJECIA5_BRONMIOTANA_H
#include "Bron.h"



class BronMiotana : public Bron{
    private:
        int wyrzutnia;

    public:
        BronMiotana (std::string Nazwa, int Obj, int Waga, int Razenie, int Kaliber, int wyrzutnia);
        ~BronMiotana();
        void wyswietl();
        int getWyrzutnia() const;
        void setWyrzutnia(int wyrzutnia);

};


#endif //ZAJECIA5_BRONMIOTANA_H
