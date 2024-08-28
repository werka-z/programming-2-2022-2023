#ifndef ZAJECIA5_PRZEDMIOT_H
#define ZAJECIA5_PRZEDMIOT_H
#include <string>

class Przedmiot{

public:
    Przedmiot(std::string Nazwa = "przedmiot", int Obj = 50 , int Waga=100);
    ~Przedmiot();
    void wyswietl();

    std::string getNazwa() const;
    int getObjetosc() const;
    int getWaga() const;

    void setNazwa(const std::string& Nazwa);
    void setObjetosc(int Obj);
    void setWaga(int Waga);
    bool tenSam(Przedmiot* inny) const;

private:
    std::string nazwa;
    int objetosc{};
    int waga{};
};

#endif



