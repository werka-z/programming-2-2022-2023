/*
 * Część 1 –Napisz klasę reprezentującą dyplom magisterski absolwenta UJ.
 * Powinna ona zawierać pola przechowujące:
 * Napisz odpowiednie konstruktory,
 * metodę do wyświetlania danych na ekran i metodę do zmiany średniej ocen
 * studenta zachowującą spójność danych (w szczególności średnią ocen wszystkich
 * studentów). Zakładamy,że po konstrukcji będzie to jedyna metoda umożliwiająca
 * modyfikację już skonstruowanego obiektu. Dane które mogą być statyczne lub stałe
 * powinny takie być i w efekcie w klasie powinny się pojawić wszystkie kombinacje
 * pól (statyczne/dynamiczne, stałe/niestałe).
*/

#include <iostream>
#include <string>
using namespace std;

class dyplomUJ {

    const string imie;
    const string nazwisko;
    string kierunek;
    static int rocznik;
    static const string uczelnia;
    int liczbaAbs;
    float srednia;
    float sredniaAbs;

public:

    dyplomUJ(): imie(), nazwisko(), kierunek(), liczbaAbs(3000),
    srednia(4.0), sredniaAbs(4.0) {}

    dyplomUJ (string _imie, string _nazwisko, string _kierunek,
              int _rocznik, int la, float sr, float sa) : imie(_imie), nazwisko(_nazwisko){
        kierunek = _kierunek;
        rocznik = _rocznik;
        liczbaAbs = la;
        srednia = sr;
        sredniaAbs = sa;
    }


    void wyswietl() const{
        printf("Absolwent %s %s kierunku %s na uczelni %s\n", imie.c_str(), nazwisko.c_str(), kierunek.c_str(), uczelnia.c_str());
        printf("Rocznik: %d, liczba absolwentow: %d.\n", rocznik, liczbaAbs);
        printf("Srednia ocen absolwenta: %f, wszystkich absolwentow: %f.\n", srednia, sredniaAbs);
    }

    void zmienSredniaAbsolwenta(float nowaSrednia){
        float staraAbs = sredniaAbs, staraSrednia = srednia;
        float staraSuma = liczbaAbs * sredniaAbs;
        float nowaSuma = staraSuma - srednia + nowaSrednia;
        sredniaAbs = nowaSuma / liczbaAbs;
        srednia = nowaSrednia;
        std::cout << "\nzmieniam srednia absolwenta z " << staraSrednia << " na " << srednia
                  << ", a srednia wszystkich absolwentow z " << staraAbs << " na \n" << sredniaAbs << std::endl;
    }


};

int dyplomUJ::rocznik = 2020;
const string dyplomUJ::uczelnia = "UJ";

int main() {

    dyplomUJ* dyplom = new dyplomUJ("Adam", "Kowalski", "Biologia", 2017, 35, 2.0, 3.0);
    dyplom->wyswietl();
    dyplom->zmienSredniaAbsolwenta(5.0);
    dyplom->wyswietl();

    return 0;
}
