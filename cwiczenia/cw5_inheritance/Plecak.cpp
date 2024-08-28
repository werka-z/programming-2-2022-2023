#include "Plecak.h"

Plecak::Plecak( int maxObj, int maxWaga){
    przedmioty = nullptr;
    this->liczbaPrzedmiotow = 0;
    this->maxWaga = maxWaga;
    this->maxObj = maxObj;
    printf("Tworze plecak.\n");
}

Plecak::~Plecak(){
    delete[] przedmioty;
    printf("Niszcze plecak.\n");
}
void Plecak::wyswietl(){
    if (liczbaPrzedmiotow == 0){
        printf("Plecak jest pusty.\n");
        return;
    }
    printf("Przedmioty w plecaku:\n");
    for (int i=0; i<liczbaPrzedmiotow; i++){
        printf("%d. ", i+1);
        przedmioty[i]->wyswietl();
    }
}

void Plecak::wstaw(Przedmiot* przedmiot){
    if (this->getWaga() + przedmiot->getWaga() > this->getMaxWaga()){
        printf("Przedmiot %s nie zmiesci sie w plecaku - jest za ciezki.\n", przedmiot->getNazwa().c_str());
        return;
    }
    if (this->getObj() + przedmiot->getObjetosc() > this->getMaxObj()){
        printf("Przedmiot %s nie zmiesci sie w plecaku - zajmuje za duzo miejsca.\n", przedmiot->getNazwa().c_str());
        return;
    }

    liczbaPrzedmiotow ++;
    Przedmiot** nowePrzedmioty = new Przedmiot*[liczbaPrzedmiotow];
    int i;
    for (i=0; i<liczbaPrzedmiotow-1; i++){
        nowePrzedmioty[i] = przedmioty[i];
    }
    nowePrzedmioty[i] = przedmiot;

    delete[] przedmioty;
    this->przedmioty = nowePrzedmioty;
    printf("Wkladam %s do plecaka.\n", przedmiot->getNazwa().c_str());
}


void Plecak::wyjmij(Przedmiot* przedmiot){

    int i=0;
    while (!przedmioty[i]->tenSam(przedmiot) && i<liczbaPrzedmiotow) i++;

    if (i>=liczbaPrzedmiotow){
        printf("Tego przedmiotu nie ma w plecaku\n");
        return;
    }

    liczbaPrzedmiotow --;
    Przedmiot** nowePrzedmioty = new Przedmiot*[liczbaPrzedmiotow];

    int k=0;
    while (k<liczbaPrzedmiotow){
        if (k<i) nowePrzedmioty[k] = przedmioty[k];
        else nowePrzedmioty[k] = przedmioty[k+1];
        k++;
    }

    delete[] przedmioty;
    this->przedmioty = nowePrzedmioty;
    printf("Wyjmuje %s z plecaka.\n", przedmiot->getNazwa().c_str());
}

int Plecak::getMaxWaga(){return maxWaga;}
int Plecak::getMaxObj(){return maxObj;}

int Plecak::getWaga(){
    int waga =0;
    for (int i=0; i<liczbaPrzedmiotow; i++){
        waga += przedmioty[i]->getWaga();
    }
    return waga;
}
int Plecak::getObj(){
    int obj =0;
    for (int i=0; i<liczbaPrzedmiotow; i++){
        obj += przedmioty[i]->getObjetosc();
    }
    return obj;
}
void Plecak::setMaxWaga(int maxWaga){
    if (maxWaga<0){
        printf("Waga nie moze byc ujemna. Ustawiam na 0.\n");
        this->maxWaga = 0;
    }
    else this->maxWaga = maxWaga;
}
void Plecak::setMaxObj(int maxObj){
    if (maxObj<0){
        printf("Objetosc nie moze byc ujemna. Ustawiam na 0.\n");
        this->maxObj = 0;
    }
    else this->maxObj = maxObj;

}
void Plecak::zmienParametry(int maxObj, int maxWaga){
    if (maxWaga<0 || maxObj<0){
        printf("Podaj dodatnie wartosci.\n");
        return;
    }
    if (maxWaga<getWaga()){
        printf("Nie mozna tak bardzo zmniejszyc max wagi plecaka - przedmioty sie nie zmieszcza.\n");
        return;
    }
    if (maxObj<getObj()){
        printf("Nie mozna tak bardzo zmniejszyc max objetosci plecaka - przedmioty sie nie zmieszcza.\n");
        return;
    }
    this->maxWaga = maxWaga;
    this->maxObj = maxObj;
}

